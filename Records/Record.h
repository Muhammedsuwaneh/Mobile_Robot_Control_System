/**
 * @file Record.h
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed Suwaneh,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for recording operation.
 */
#ifndef RECORD_H
#define RECORD_H
#include<string>
#include<fstream>
#include<iostream>
#include "../Position/Pose.h"
using namespace std;
class Record
{
public:
	//Record();
	fstream file;
	bool openFile();
	bool closeFile();
	void setFileName(string);
	string readLine();
	bool writeLine(string);
	friend fstream& operator <<(Record&,Pose&);
	friend fstream& operator >>(Record&,Pose&);
	//~Record();

private:
	string fileName;
	//fstream file;

};
#endif // !RECORD_H


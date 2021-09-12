/**
 * @file Record.cpp
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed Suwaneh,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for recording operation.
 */

#include "Record.h"

bool Record::openFile()
{
	file.open(fileName,ios::app|ios::out);
	return file.is_open() ? true : false;
}

bool Record::closeFile()
{
	file.close();
	
	return file.is_open() ? false : true;
}

void Record::setFileName(string name)
{
	fileName = name;
}

string Record::readLine()
{
	string temp;
	getline(file,temp);
	return temp;
}

bool Record::writeLine(string temp)
{
	if (file << temp)return true;
	else return false;
}

fstream& operator<<(Record& out,Pose& pose)
{
	
	out.file <<"Pose X: "<<pose.getX()<<endl;
	out.file <<"Pose Y: "<< pose.getY()<<endl;
	out.file<<"Pose Th: "<<pose.getTh()<<endl;
	return out.file;
}

fstream& operator>>(Record& in, Pose& pose)
{
	int temp,temp1,temp2;
	in.file >>temp>>temp1>>temp2;
	pose.setX(temp);
	pose.setY(temp1);
	pose.setTh(temp2);

	return in.file;
}



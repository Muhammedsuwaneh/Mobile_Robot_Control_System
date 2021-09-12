#include<iostream>
#include"Record.h"
#include"Pose.h"
using namespace std;
int main()
{
	Record record;
	Pose pose;
	pose.setX(5.4);
	pose.setY(12.6);
	pose.setTh(13.2);
	record.setFileName("input.txt");
	record.openFile()==true?cout<<"File is opened"<<endl:cout<<"The file can not opened"<<endl;
	if(record.writeLine("poseX:32 poseY:56 poseTh:19"))cout<<"Write"<<endl;
	record.closeFile();
	record.openFile() == true ? cout << "File is opened" << endl : cout << "The file can not opened" << endl;
	string temp = record.readLine();
	record.closeFile();
	record.openFile() == true ? cout << "File is opened" << endl : cout << "The file can not opened" << endl;
	record << pose;
	record.closeFile();
	record.openFile() == true ? cout << "File is opened" << endl : cout << "The file can not opened" << endl;
	record >> pose;
	record.closeFile();
	return 0;
}
/**
 * @file RobotOperator.h
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This class will be used remoting robot and authorization operation
 */
#ifndef ROBOT_OPERATOR_H
#define ROBOT_OPERATOR_H
#include"../Encryption/Encrpytion.h"
#include<string>
using namespace std;
class RobotOperator
{
public:
	RobotOperator(unsigned int,string,string);
	int encrpytCode(int);
	int decrpytCode(int);
	bool checkAccessCode(int);
	void print();
	//~RobotOperator();

private:
	string name;
	string surname;
	unsigned int accessCode;
	bool accessState;
};
#endif // !ROBOTOPERATOR_H


/**
 * @file RobotOperator.cpp
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This class will be used remoting robot and authorization operation
 */
#include "RobotOperator.h"
#include <iostream>
 /**
  *constructor
  *@params accces is a unsigned int argument.
  *@params name is a string argument.
  *@params surname is a string argument.
  */
RobotOperator::RobotOperator(unsigned int access,string name,string surname)
{
	accessCode = encrpytCode(access);
	this->name = name;
	this->surname = surname;
}
/**
 *encrpyt do encrpytcode
 *@param code is an integer argument.
 *@returns encrpyted code value.
 */
int RobotOperator::encrpytCode(int code)
{
	Encrpytion e;
	return e.encrypt(code);
}
/**
 *dencrpyt do decrpytcode operation
 *@param code is an integer argument.
 *@returns decrpyted code value.
 */
int RobotOperator::decrpytCode(int code)
{
	Encrpytion e;
	return e.decrypt(code);
}
/**
 *checkAccesCode controls whether accesscode is the same code or not  
 *@param code is an integer argument.
 *@returns accessState 
 */
bool RobotOperator::checkAccessCode(int code)
{
	accessState=accessCode == code ? true : false;
	return accessState;
}
/**
 *print prints Robot's infos.
 */
void RobotOperator::print()
{
	cout << "ROBOT INFO" << endl;
	cout << "Robot Name: " << name<<endl;
	cout <<" Robot Surname: " << surname<<endl;
	cout << "Access State: " << accessState << endl;
}

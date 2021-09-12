#include<iostream>
#include"Encrpytion.h"
using namespace std;
int main() 
{
	
	Encrpytion e;
	e.encrypt(1235) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(1235)<<endl;
	e.encrypt(1003) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(1003)<<endl;
	e.encrypt(1006) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(1006)<<endl;
	e.encrypt(100) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(100)<<endl;
	e.encrypt(5633) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(5633)<<endl;
	e.encrypt(3433) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(3433)<<endl;
	e.encrypt(2333) == -1 ? cout << "ERROR"<<endl: cout<<e.encrypt(2333)<<endl;
	e.decrypt(289) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(289)<<endl;
	e.decrypt(7087) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(7087)<<endl;
	e.decrypt(7387) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(7387)<<endl;
	e.decrypt(23) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(23)<<endl;
	e.decrypt(1) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(1)<<endl;
	e.decrypt(90) == -1 ? cout << "ERROR"<<endl: cout<<e.decrypt(90)<<endl;

	return 0;
}
#include<iostream>
#include"RobotOperator.h"
using namespace std;
int main()
{
	RobotOperator opp(1235,"Robot","AI");
	opp.checkAccessCode(1235)?cout<<"True"<<endl:cout<<"False"<<endl;//289 is accessed;
	opp.print();
	return 0;
}
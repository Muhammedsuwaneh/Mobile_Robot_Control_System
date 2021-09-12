#include<iostream>
#include"LaserSensor.h"
using namespace std;
int main()
{
	LaserSensor laser;
	PioneerRobotAPI robot;
	float laserRange[181];
	int index;
	float angle;
	laser.updateSensor(laserRange);
	for (int i = 0; i < 181; i++)
	{
		cout<<laserRange[i]<<endl;
	}
	cout << laser.getRange(2) << endl;
	cout << "Min: " << laser.getMin(index) << endl;
	cout << "Index: " << index << endl;
	cout << "Max: " << laser.getMax(index) << endl;
	cout << "Index: " << index << endl;
	cout << "Value: " << laser[3] << endl;
	cout << "Angle: " << laser.getAngle(143) << endl;
	cout << "Closest Range: " << laser.getClosestRange(95,120, angle)<<endl;
	cout << angle << endl;



	return 0;
}
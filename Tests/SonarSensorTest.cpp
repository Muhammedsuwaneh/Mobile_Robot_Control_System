#include<iostream>
#include"SonarSensor.h"
using namespace std;
int main()
{
	SonarSensor sensor;
	int index;
	float sonarRange[16];
	for (int i = 0; i < 16; i++)
	{
		sonarRange[i] = 0.5 * (i + 1);
	}
	sensor.updateSensor(sonarRange);
	cout << sensor.getRange(2) << endl;
	cout <<"Min: "<<sensor.getMin(index)<<endl;
	cout << "Index: " << index<<endl;
	cout << "Max: " << sensor.getMax(index) << endl;
	cout << "Index: " << index << endl;
	cout << "Value: "<<sensor[3] << endl;
	cout << "Angle: " << sensor.getAngle(13) << endl;
	return 0;
}
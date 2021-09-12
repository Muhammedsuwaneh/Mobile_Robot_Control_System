/**
 * @file SonarSensor.h
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for sonar sensor operation.
 */
#ifndef SONAR_SENSOR_H
#define SONAR_SENSOR_H
#include"../API/PioneerRobotAPI.h"
#include"RangeSensor.h"
#define ssize 16
class SonarSensor:public RangeSensor
{
public:
	SonarSensor(PioneerRobotAPI*,float[]);
	~SonarSensor();
	float getRange(int);
	float getMax(int&);
	float getMin(int&);
	void updateSensor(float[]);
	float operator[](int);
	float getAngle(int);
	float getClosestRange(float, float, float&);

private:
	float ranges[ssize];
	PioneerRobotAPI* robotAPI = new PioneerRobotAPI;

};
#endif //!SONAR_SENSOR_H



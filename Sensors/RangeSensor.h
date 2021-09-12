/**
* @file	RangeSensor.h
* @Author Yakupcan ERGEN 
* @date January, 2021
* @brief RangeSensor Declaration
*
*
* This file includes the RangeSensor class  declaration and whole it's necessary functions
*/
#ifndef RANGE_SENSOR_H
#define RANGE_SENSOR_H
#include "../API/PioneerRobotAPI.h"
class RangeSensor
{
public:
	RangeSensor(PioneerRobotAPI*robot, float range[],int n) {
		robotAPI = robot;
		ranges = new float[n];
		ranges = range;
	}
	virtual float getRange(int)=0;
	virtual float getMax(int&)=0;
	virtual float getMin(int&)=0;
	virtual void updateSensor(float[])=0;
	virtual float operator[](int)=0;
	virtual float getAngle(int)=0;
	virtual float getClosestRange(float, float, float&)=0;
private:
	float *ranges;
	PioneerRobotAPI* robotAPI;
};
#endif //!RANGE_SENSOR_H

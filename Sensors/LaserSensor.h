/**
 * @file LaserSensor.h
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for laser sensor operation.
 */
#ifndef LASER_SENSOR_H
#define LASER_SENSOR_H
#include"../API/PioneerRobotAPI.h"
#include"../Sensors/RangeSensor.h"
#define lsize 181
class LaserSensor:public RangeSensor
{
public:
	LaserSensor(PioneerRobotAPI*,float[]);
	~LaserSensor();
	float getRange(int);
	float getMax(int&);
	float getMin(int&);
	void updateSensor(float[]);
	float operator[](int);
	float getAngle(int);
	float getClosestRange(float, float, float&);
	

private:
	float ranges[lsize];
	PioneerRobotAPI* robotAPI=new PioneerRobotAPI;
};

#endif // !LASER_SENSOR_H

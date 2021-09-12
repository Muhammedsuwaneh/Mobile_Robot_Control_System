/**
 * @file LaserSensor.cpp
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for laser sensor operation.
 */
#include "LaserSensor.h"
#include<math.h>
 /**
  *constructor
  *@param ls is a PioneerRobotAPI pointer argument.
  *@param ranges is a float array argument.
  */
LaserSensor::LaserSensor(PioneerRobotAPI*ls,float ranges[]):RangeSensor(ls,ranges,lsize)
{
	robotAPI = ls;
	*(this->ranges) = *ranges;
}
/**
 *destructor
 */
LaserSensor::~LaserSensor()
{
	delete robotAPI;
}
/**
 *getRange returns range according to given index
 *@param index an integer argument.
 *@returns ranges[index]
 */
float LaserSensor::getRange(int index)
{
	return ranges[index];
}
/**
 *getMax returns max value and assign index
 *@param i is an integer reference argument.
 *@returns max range value.
 */
float LaserSensor::getMax(int& i)
{
	float max = ranges[0];
	int index=0;
	for (int i = 1; i < lsize; i++)
	{
		if (ranges[i] > max)
		{
			max = ranges[i];
			index = i;
		}
	}
	i = index;
	return max;
}
/**
 *getMin returns min value and assign index
 *@param i an integer reference argument.
 *@returns min range value.
 */
float LaserSensor::getMin(int& i)
{
	float min = ranges[0];
	int index=0;
	for (int i = 1; i < lsize; i++)
	{
		if (ranges[i] < min)
		{
			min = ranges[i];
			index = i;
		}
	}
	i = index;
	return min;
}
/**
 *updateSensor assigns the robot's laser range into the ranges array
 *@param arr an float array argument.
 */
void LaserSensor::updateSensor(float arr[])
{
	robotAPI->getLaserRange(arr);
	for (int i = 0; i < lsize; i++)
	{
		ranges[i] = arr[i];
	}
}
/**
 *operator[] returns range according to given index
 *@param index an integer argument.
 *@returns ranges[index]
 */
float LaserSensor::operator[](int index)
{
	return ranges[index];
}
/**
 *getAngle returns angle according to given index
 *@param index an integer argument.
 *@returns angle
 */
float LaserSensor::getAngle(int index)
{
	return index;
}
/**
 *getClosestRange returns closest Range and assign angle
 *@param startAngle is an float argument.
 *@param endAngle is an float argument.
 *@param angle is an float argument.
 *@returns closest range
 */
float LaserSensor::getClosestRange(float startAngle, float endAngle, float& angle)
{
	float rangeStart=cos(startAngle)/getRange(startAngle);
	float rangeEnd=sin(endAngle-90)/getRange(endAngle);
	(rangeStart < rangeEnd) ? angle = startAngle:angle=endAngle;
	return rangeStart + rangeEnd;
}

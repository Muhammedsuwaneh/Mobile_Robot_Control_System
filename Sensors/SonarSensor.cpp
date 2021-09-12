/**
 * @file SonarSensor.cpp
 * @Author Yakupcan ERGEN,Alperen BÝÞKÝN,Muhammed SUWANEH,Halil Kadirhan KUBAT
 * @date December, 2020
 * @brief This  class is responsible for sonar sensor operation.
 */
#include"SonarSensor.h"
 /**
  *constructor
  *@param ss a PioneerRobotAPI pointer argument.
  */
SonarSensor::SonarSensor(PioneerRobotAPI*ss,float ranges[]):RangeSensor(ss,ranges,ssize)
{
	robotAPI = ss;
	*(this->ranges) = *ranges;
}
/**
 *destructor
 */
SonarSensor::~SonarSensor()
{
	delete robotAPI;
}
/**
 *getRange returns range according to given index
 *@param index an integer argument.
 *@returns ranges[index]
 */
float SonarSensor::getRange(int index)
{
	return ranges[index];
}
/**
 *getMax returns max value and assign index
 *@param i an integer reference argument.
 *@returns max range value.
 */
float SonarSensor::getMax(int& i)
{
	float max = ranges[0];
	int index=0;
	for (int i = 1; i < ssize; i++)
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
float SonarSensor::getMin(int& i)
{
	float min = ranges[0];
	int index = 0;
	for (int i = 1; i < ssize; i++)
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
 *updateSensor assigns the robot's sensor range into the ranges array  
 *@param arr an float array argument.
 */
void SonarSensor::updateSensor(float arr[])
{
	robotAPI->getSonarRange(arr);
	for (int i = 0; i < ssize; i++)
	{
		ranges[i] = arr[i];
	}
}
/**
 *operator[] returns range according to given index
 *@param index an integer argument.
 *@returns ranges[index]
 */
float SonarSensor::operator[](int index)
{
	return ranges[index];
}
/**
 *getAngle returns angle according to given index
 *@param index an integer argument.
 *@returns angle
 */
float SonarSensor::getAngle(int index)
{
	int angle = 50;
	if (index == 0 || index == 15)
	{
		return 90;
	}
	else if (index == 7 || index == 8)
	{
		return -90;
	}
	else
	{
		int temp = index;
		if (index >= 9)
		{
			temp = 15 % index;
		}
		angle -= (temp - 1) * 20;
		return angle;
	}
}
/**
 *getClosestRange returns closest Range and assign angle
 *@param startAngle is an float argument.
 *@param endAngle is an float argument.
 *@param angle is an float argument.
 *@returns closest range
 */
float SonarSensor::getClosestRange(float startAngle, float endAngle, float& angle)
{
	float rangeStart = cos(startAngle) / getRange(startAngle);
	float rangeEnd = sin(endAngle - 90) / getRange(endAngle);
	(rangeStart < rangeEnd) ? angle = startAngle : angle = endAngle;
	return rangeStart + rangeEnd;
}

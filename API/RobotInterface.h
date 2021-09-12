/**
 * @file RobotControl.h
 * @Author Alperen Biþkin
 * @date December, 2020
 * @brief  This  class is responsible for control the operation such as turn left,turn right and move etc.
 */
#ifndef RobotInterface_H
#define RobotInterface_H
#include"../Position/Pose.h"	
#include"../Sensors/RangeSensor.h"
class RangeSensor;
class RobotInterface
{
public:
	RobotInterface(Pose* p) {
		position = p;
	}
	virtual void turnLeft()=0;
	virtual void turnRight() = 0;
	virtual void forward(float) = 0;
	virtual void print() = 0;
	virtual void backward(float) = 0;
	virtual Pose getPose() = 0;
	virtual void setPose(Pose) = 0;
	virtual void stopTurn() = 0;
	virtual void stopMove() = 0;
	virtual void updateSensors() = 0;


private:
	Pose *position;
	int state;

};
#endif//!RobotInterface_H

/**
* @file PioneerRobotInterface.h
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date last January, 24th, 2021
* @brief PioneerRobotInterface class declaration
*
*
* This file defines the MainMenu's necessary functions
*/

#ifndef _PIONEERROBOTINTERFACE_
#define _PIONEERROBOTINTERFACE_
#include "PioneerRobotAPI.h"
#include "RobotInterface.h"
#include"../Sensors/RangeSensor.h"
#include"../Sensors/SonarSensor.h"
#include"../Sensors/LaserSensor.h"
#include "../Position/Pose.h"

class PioneerRobotInterface:public RobotInterface
{
private:
	PioneerRobotAPI* robotAPI=new PioneerRobotAPI;
public:
	PioneerRobotInterface(Pose*,PioneerRobotAPI*);
	 ~PioneerRobotInterface();
	void turnLeft();
	void turnRight();
	void forward(float);
	void print();
	void backward(float);
	Pose getPose();
	void setPose(Pose);
	void stopTurn();
	void stopMove();
	void updateSensors();
};

#endif //! _PIONEERROBOTINTERFACE_


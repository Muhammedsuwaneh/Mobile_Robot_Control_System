/**
* @file PioneerRobotInterface.cpp
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date last updated January, 24th, 2021
* @brief PioneerRobotInterface class definitions
*
*
* This file defines the MainMenu's necessary functions
*/
#include <iostream>
#include "PioneerRobotInterface.h"

using namespace std;

/*! 
* PioneerRobotInterface Constructor
* @param p is a Pose pointer argument.
* @param robot is a PioneerRobotAPI pointer argument.
* initializes the position object
*/
PioneerRobotInterface::PioneerRobotInterface(Pose*p,PioneerRobotAPI*robot):RobotInterface(p) {
	robotAPI = robot;
}

/*!
* PioneerRobotInterface destructor
* deles the robotAPI position object pointers
*/
PioneerRobotInterface::~PioneerRobotInterface() { 

	delete robotAPI;
}

/*!
* turnLeft() method 
* turns the robot in the left direction
*/
void PioneerRobotInterface::turnLeft()
{
	robotAPI->turnRobot(robotAPI->left);
}

/*!
* turnRight() method
* turns the robot in the right direction
*/
void PioneerRobotInterface::turnRight()
{
	robotAPI->turnRobot(robotAPI->right);
}

/*!
* forward() method
* @param speed -> given positive speed to move robot forward
* moves the robot in the forward direction
*/
void PioneerRobotInterface::forward(float speed)
{
	if (speed < 0) {
		throw("PioneerRobotInterface::forward -> Speed must be a positive value");
		speed = speed * -1;
	}
	
	robotAPI->moveRobot(speed);
}

/*!
* forward() method
* @param speed -> given negative speed to move robot backward
* moves the robot in the forward direction
*/
void PioneerRobotInterface::backward(float speed)
{
	if (speed > 0) {
		throw("PioneerRobotInterface::backward -> Speed must be a negative value");
		speed = speed * -1;
	}

	robotAPI->moveRobot(speed);
}
/*!
* print() method
* prints the robot's position details
*/
void PioneerRobotInterface::print()
{
	cout << "Robot Position Details" << endl;
	cout << "x: " << robotAPI->getX() << " y: " 
	<< robotAPI->getY() << " angle(th): " << robotAPI->getTh() << endl;
}

/*!
* stopRobot() method
* stops the robot's movement
*/
void PioneerRobotInterface::stopMove()
{
	robotAPI->stopRobot();
}

/*!
* getPose() method
* obtain's the robots position details
*/
Pose PioneerRobotInterface::getPose()
{
	Pose pose(robotAPI->getX(), robotAPI->getY(), robotAPI->getTh());
	setPose(pose);
	return pose;
}

/*!
* setPose() method
* @param pose -> position object
* set's robot's position
*/
void PioneerRobotInterface::setPose(Pose pose)
{
	robotAPI->setPose(pose.getX(), pose.getY(), pose.getTh());
}

/*!
* stopTurn() method
* stops the robot from turning 
*/
void PioneerRobotInterface::stopTurn()
{
	robotAPI->turnRobot(robotAPI->forward);
}

/*!
* updateSensors() method
* update's robot's sonar and laser sensors
*/
void PioneerRobotInterface::updateSensors()
{
	RangeSensor* sSensor;
	RangeSensor* lSensor;
	float sonarRanges[16];
	float laserRanges[724];
	robotAPI->getLaserRange(laserRanges);
	robotAPI->getSonarRange(sonarRanges);
	sSensor = new SonarSensor(robotAPI, sonarRanges);
	lSensor = new LaserSensor(robotAPI, laserRanges);
	cout << "[ ";
	for (int i = 0; i < 16; i++)
	{
		cout << sonarRanges[i]<<" ";
	}
	cout << "] ";
	cout << endl << "-------------------------------------"<<endl;
	cout << "[ ";
	for (int i = 0; i < 181; i++)
	{
		cout << laserRanges[i] << " ";
	}
	cout << " ]"<<endl;
}

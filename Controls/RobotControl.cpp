/**
 * @file RobotControl.cpp
 * @Author Alperen Biþkin
 * @date December, 2020
 * @brief  This  class is responsible for control the operation such as turn left,turn right and move etc.
 */
#include"RobotControl.h"
#include<iostream>
using namespace std;
/**
 *constructor
 *@param rb is a pointer robotAPI argument.
 *@param pose is a Pose pointer argument.
 */
RobotControl::RobotControl(PioneerRobotAPI *rb,Pose*pose)
{
	robotInterface = new PioneerRobotInterface(pose, rb);
}
/**
 *turnLeft turns the robot to the left
 */
void RobotControl::turnLeft()
{
	robotInterface->turnLeft();
}
/**
 *turnRight turns the robot to the right
 */
void RobotControl::turnRight()
{
	robotInterface->turnRight();;
}
/**
 *forward goes the robot towards the forward
 *@param speed is a float argument.
 */
void RobotControl::forward(float _speed)
{
	robotInterface->forward(_speed);
}
/**
 *print prints the robot's infos.
 */
void RobotControl::print()
{
	robotInterface->print();
}
/**
 *backward goes the robot towards the backward
 *@param speed is a float argument.
 */
void RobotControl::backward(float _speed)
{
	robotInterface->backward(_speed);
}
/**
 *setPose sets the robot's location.
 *@param position is a Pose argument.
 */
void RobotControl::setPose(Pose position)
{
	robotInterface->setPose(position);
}
/**
 *getPose gets the robot's location.
 *@returns position 
 */
Pose RobotControl::getPose()
{
	return robotInterface->getPose();
}
/**
 *stopTurn stops the robot's turning.
 */
void RobotControl::stopTurn()
{
	robotInterface->stopTurn();
}
/**
 *stopMove stops the robot's movement.
 */
void RobotControl::stopMove()
{
	robotInterface->stopMove();
}
/**
 *adds the robot's position into path. 
 *@returns true if the pose was added or not false.
 */
bool RobotControl::addToPath()
{
	int temp;
	temp=path.size();
	path.addPose(robotInterface->getPose());
	if (temp != path.size())
		return true;
	else
		return false;
}
/**
 *clear the robot's position into path.
 *@returns true if the pose was cleared or not false.
 */
bool RobotControl::clearPath()
{
	if (path.size() == 0)
		return false;
	path.~Path();
	return true;
}
/**
 *record the robot's position into path.
 *@returns true if the pose was recorded or not false.
 */
bool RobotControl::recordPathToFile()
{
	Record record;
	record.setFileName("input.txt");
	record.openFile();
	if (path.size() == 0)
	{
		throw exception("The Path cannot be found.");
		return false;
	}
	for (int i = 0; i < path.size(); i++)
	{
		record.writeLine("X: " +to_string(path.getPos(i).getX()));
		record.writeLine("\n");
		record.writeLine("Y: " +to_string(path.getPos(i).getY()));
		record.writeLine("\n");
		record.writeLine("Th: " +to_string(path.getPos(i).getTh()));
		record.writeLine("\n");
		record.writeLine("****************************************\n");
	}
	record.closeFile();
	return true;
}
/**
 *Check robot key.If key is true,access is open.
 *@returns true if the key is true or not false
 */
bool RobotControl::openAccess(int access)
{
	if (rOperator->checkAccessCode(access)) {
		return true;
	}
	else
	{
		cout << "INVALID CODE" << endl;
		return false;
	}
		
}
/**
 *Check robot key.If key is true,access is close.
 *@returns true if the key is true or not false
 */
bool RobotControl::closeAccess(int access)
{
	if (rOperator->checkAccessCode(access)) {
		return true;
	}
	else
	{
		cout << "INVALID CODE" << endl;
		return false;
	}
}



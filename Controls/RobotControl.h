/**
 * @file RobotControl.h
 * @Author Alperen Biþkin
 * @date December, 2020
 * @brief  This  class is responsible for control the operation such as turn left,turn right and move etc.
 */
#ifndef RobotControl_H
#define RobotControl_H
#include"../API/PioneerRobotAPI.h"
#include"../Position/Pose.h"
#include"../Path/Path.h"
#include "../Operators/RobotOperator.h"
#include"../API/RobotInterface.h"
#include"../Records/Record.h"
#include "../API/PioneerRobotInterface.h"
class RobotControl
{
public:
	RobotControl(PioneerRobotAPI*, Pose*);
	~RobotControl() { delete rOperator; }
	void turnLeft();
	void turnRight();
	void forward(float);
	void print();
	void backward(float);
	Pose getPose();
	void setPose(Pose);
	void stopTurn();
	void stopMove();
	bool addToPath();
	bool clearPath();
	bool recordPathToFile();
	bool openAccess(int);
	bool closeAccess(int);
private:
	Path path;
	RobotOperator *rOperator=new RobotOperator(1200,"Robot","AI");
	RobotInterface* robotInterface;
};
#endif

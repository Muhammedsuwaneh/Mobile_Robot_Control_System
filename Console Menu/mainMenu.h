/**
* @file	mainMenu.h
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date last updated January 24th, 2021
* @brief Path class declaration
*
*
* This file declares the MainMenu class and all it's necessary functions
*/
#ifndef _MAINMENU_
#define _MAINMENU_
#include <iostream>
#include "../API/PioneerRobotAPI.h"
#include "../Controls/RobotControl.h"
#include"../Position/Pose.h"
#include"../Sensors/RangeSensor.h"
#include"../Sensors/LaserSensor.h"
#include"../Sensors/SonarSensor.h"
#include"../Records/Record.h"
#include"../Path/Path.h"

class MainMenu {

private:
	PioneerRobotAPI robotAPI;
	Pose pose;
	RobotControl* robotcontrol = new RobotControl(&robotAPI,&pose);
	float laserRange[724];
	float sonarRange[16];
	RangeSensor* lasers = new LaserSensor(&robotAPI,laserRange);
	RangeSensor* sonars = new SonarSensor(&robotAPI,sonarRange);
	Record record;
	RobotInterface* robotInterface = new PioneerRobotInterface(&pose,&robotAPI);
	bool connectionStatus = false;
public:
	void displayMainMenu();
	void connectionMenu();
	void motionMenu();
	void positionMenu();
	void sensorMenu();
	void print();
};

#endif //! _MAINMENU_

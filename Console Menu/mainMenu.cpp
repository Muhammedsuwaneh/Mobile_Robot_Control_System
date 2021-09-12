/**
* @file mainMenu.cpp
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date last updated January, 24th, 2021
* @brief Path class declaration
*
*
* This file defines the MainMenu's necessary functions
*/

#include <iostream>
#include "mainMenu.h"
#include "conio.h"

using namespace std;

/**
* displays the main menu
*/
void MainMenu::displayMainMenu() {

	int choice;

	do {

		cout << "\n\t\t\t---------------------------------" << endl;
		cout << "\t\t\t Main Menu" << endl;
		cout << "\t\t\t---------------------------------" << endl;
		cout << "\t\t\t1. Connections" << endl;
		cout << "\t\t\t2. Motion" << endl;
		cout << "\t\t\t3. Sensor" << endl;
		cout << "\t\t\t4. Position" << endl;
		cout << "\t\t\t5. Quit" << endl;
		cout << "\t\t\tChoose One: ";
		cin >> choice;
		system("cls");

		if (choice == 1) {
			connectionMenu();
		}

		else if (choice == 2) {
			motionMenu();
		}

		else if (choice == 3) {
			sensorMenu();
		}
		else if (choice == 4)
		{
			positionMenu();
		}
		else if (choice == 5) {
			break;
		}

		else {
			cout << "\t\t\tInvalid Input" << endl;
		}

	} while (1);

	cout << "\n\t\t\tSystem terminated" << endl;
}

/*
*  displays the connection Menu
*/
void MainMenu::connectionMenu() {

	do {

		int choice;

		cout << "\n\t\t\t---------------------------------" << endl;
		cout << "\t\t\t Connection Menu" << endl;
		cout << "\t\t\t---------------------------------" << endl;
		cout << "\t\t\t1. Connect Robot" << endl;
		cout << "\t\t\t2. Disconnect Robot" << endl;
		cout << "\t\t\t3. Back" << endl;
		cout << "\t\t\tChoose One: ";
		cin >> choice;
		system("cls");

		if (choice == 1) {
			//! connect robot
			int temp;
			cout << "Enter  the access code of the robot: ";
			cin >> temp;
			//if(robotcontrol->openAccess(temp))
				connectionStatus = robotAPI.connect();
			if (connectionStatus == true)
				cout << "\n\t\t\t< Robot is connected ........... >\n\n" << endl;
			else
				cout << "\n\t\t\t< Connection Error ....... >\n\n" << endl;
		}

		else if (choice == 2) {
			//! disconnect robot
			connectionStatus = false;
			int temp;
			cout << "Enter the access code of the robot: ";
			cin >> temp;
			if(robotcontrol->closeAccess(temp))
				connectionStatus = robotAPI.disconnect();
			if (connectionStatus == true)
				cout << "\n\t\t\t< Robot is disconnected ........ >\n\n" << endl;
			else
				cout << "\n\t\t\t< Robot could not be disconnected ........ >\n\n" << endl;
		}

		else if (choice == 3) {
			//! go back
			break;
		}

		else {
			//! trigger if choice is not in options
			break;
		}

	} while (1);

	system("cls");
}//!end-connectionMenu()

/**
* displays the motion menu
*/
void MainMenu::motionMenu() {
	float speed;
	do {

		int choice;
		cout << "\n\t\t\t---------------------------------" << endl;
		cout << "\t\t\t Motion Menu" << endl;
		cout << "\t\t\t---------------------------------" << endl;
		cout << "\t\t\t1. Move Robot" << endl;
		cout << "\t\t\t2. safe move robot" << endl;
		cout << "\t\t\t3. turn left" << endl;
		cout << "\t\t\t4. turn right" << endl;
		cout << "\t\t\t5. forward" << endl;
		cout << "\t\t\t6. backward" << endl;
		cout << "\t\t\t7. stop turn" << endl;
		cout << "\t\t\t8. stop move" << endl;
		cout << "\t\t\t9. back" << endl;
		cout << "\t\t\tChoose One: ";
		cin >> choice;
		system("cls");

		if (choice == 1 /*&& connectionStatus == true*/) {
			//! Move Robot with a specific speed

			cout << "Enter any speed: ";
			cin >> speed;
			if (speed > 0)
				robotcontrol->forward(speed);
			else if (speed < 0)
				robotcontrol->backward(speed);
			else if (speed == 0)
				robotcontrol->stopMove();
			else
				cout << "INVALID SPEED" << endl;

		}
		else if (choice == 2) {
			//! Safe Move Robot
		}
		else if (choice == 3) {
			//! Turn left
			robotcontrol->turnLeft();
		}
		else if (choice == 4) {
			//! Turn Right
			robotcontrol->turnRight();
		}
		else if (choice == 5) {
			//! Forward
			cout << "Enter any speed: ";
			cin >> speed;
			if (speed <= 0)
				cout << "INVALID SPEED:You entered a wrong velocity!!!";
			robotcontrol->forward(speed);
		}
		else if (choice == 6)
		{
			//!Backward
			cout << "Enter any speed: ";
			cin >> speed;
			if (speed >= 0)
				cout << "INVALID SPEED:You entered a wrong velocity!!!";
			robotcontrol->backward(speed);
		}
		else if (choice == 7)
		{
			robotcontrol->stopTurn();
		}
		else if (choice == 8)
		{
			robotcontrol->stopMove();
		}
		else if (choice == 9) {
			//! Back to main menu
			break;
		}

		else {
			//! trigger back 
			//! if choice is not in options
			break;
		}

	} while (1);

	//! go back
	system("cls");
}
/**
* displays the position menu
*/
void MainMenu::positionMenu()
{
	do {

		int choice;
		cout << "\n\t\t\t---------------------------------" << endl;
		cout << "\t\t\t Position Menu" << endl;
		cout << "\t\t\t---------------------------------" << endl;
		cout << "\t\t\t1.Update Position" << endl;
		cout << "\t\t\t2.Print Position Infos" << endl;
		cout << "\t\t\t3.Add Position to Path" << endl;
		cout << "\t\t\t4.Clear Path" << endl;
		cout << "\t\t\t5.Record Path" << endl;
		cout << "\t\t\t6. Back" << endl;
		cout << "\t\t\tChoose One: ";
		cin >> choice;
		system("cls");

		if (choice == 1) {
			float temp;
			cout << "Enter X value: "; cin >> temp; pose.setX(temp);
			cout << "Enter Y value: "; cin >> temp; pose.setY(temp);
			cout << "Enter Th value: "; cin >> temp; pose.setTh(temp);
			robotcontrol->setPose(pose);
			robotAPI.setRobot(&robotAPI);
		}

		else if (choice == 2) {
			//! print Position
			cout << "Robot PositionX: " << robotAPI.getX() << endl;
			cout << "Robot PositionY: " << robotAPI.getY() << endl;
			cout << "Robot PositionTh: " << robotAPI.getTh() << endl;
		}
		else if (choice == 3) {
			robotcontrol->addToPath();
			cout << "Pose was added" << endl;
		}
		else if (choice == 4)
		{
			robotcontrol->clearPath();
			cout << "Path was deleted" << endl;
		}
		else if (choice == 5) {
			try
			{
				robotcontrol->recordPathToFile();
			}
			catch (const std::exception& e)
			{
				cerr << e.what();
			}
			
		}
		else if (choice == 6) {
			//! go back
			break;
		}

		else {
			//! trigger if choice is not in options
			break;
		}

	} while (1);

	system("cls");
}
//!end-positionMenu()

/**
* displays the sensor menu
*/
void MainMenu::sensorMenu() {

	do {

		int choice;

		cout << "\n\t\t\t---------------------------------" << endl;
		cout << "\t\t\t Sensor Menu AND LaserMenu" << endl;
		cout << "\t\t\t---------------------------------" << endl;
		cout << "\t\t\t1.Print Sensor Details" << endl;
		cout << "\t\t\t2.Print Sensor and LaserRange" << endl;
		cout << "\t\t\t3.Print SonarMAX and LaserMAX, SonarMIN and LaserMIN" << endl;
		cout << "\t\t\t4.Print SonarAngle and LaserAngle" << endl;
		cout << "\t\t\t5.Print ClosestRange" << endl;
		cout << "\t\t\t6.Update Sensors" << endl;
		cout << "\t\t\t7. Back" << endl;
		cout << "\t\t\tChoose One: ";
		cin >> choice;
		system("cls");

		if (choice == 1) {
			//! sensor details
			cout << "\n\t\t\t< Print Sensor Details >" << endl;
			print();

		}

		else if (choice == 2) {
			//! range details
			int lIndex, sIndex;
			cout << "\n\t\t\t<Printed........ >" << endl;
			cout << "enter an index number for sonar range: "; cin >> sIndex;
			cout << "enter an index number for laser range: "; cin >> lIndex;
			cout << "Laser range value: " << lasers->getRange(lIndex) << endl;
			cout << "Sonar range value: " << sonars->getRange(sIndex) << endl;
		}
		else if (choice == 3) {
			int index;
			cout << "Laser Max Range: " << lasers->getMax(index) << endl;
			cout << "Laser Max Range index: " << index << endl;
			cout << "Laser Min Range: " << lasers->getMin(index) << endl;
			cout << "Laser Min Range index: " << index << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "Sonar Max Range: " << sonars->getMax(index) << endl;
			cout << "Sonar Max Range index: " << index << endl;
			cout << "Sonar Min Range: " << sonars->getMin(index) << endl;
			cout << "Sonar Min Range index: " << index << endl;
		}
		else if (choice == 4) {
			int lIndex, sIndex;
			cout << "Enter an index number for sonarAngle: "; cin >> sIndex;
			cout << "Enter an index number for laserAngle: "; cin >> lIndex;
			cout << "The sonar angle is: " << sonars->getAngle(sIndex)<<endl;
			cout << "The laser angle is: " << lasers->getAngle(lIndex)<<endl;
		}
		else if (choice == 5) {
			float sAngle, eAngle, angle;
			cout << "Enter a startAngle and endAngle: "; cin >> sAngle >> eAngle;
			cout << "Closest Range: " << lasers->getClosestRange(sAngle, eAngle, angle) << endl;
			cout << "Angle is: " << angle << endl;
		}
		else if (choice == 6)
		{
			robotInterface->updateSensors();
		}
		else if (choice == 7) 
		{
			//! go back
			break;
		}

		else {
			//! trigger if choice is not in options
			break;
		}

	} while (1);

	system("cls");
}
/**
* prints the sonar and laser sensor details
*/
void MainMenu::print()
{
	cout << "MyPose is (" << robotAPI.getX() << "," << robotAPI.getY() << "," << robotAPI.getTh() << ")" << endl;
	cout << "Sonar ranges are [ ";
	sonars->updateSensor(sonarRange);
	for (int i = 0; i < 16; i++) {
		cout << sonarRange[i] << " ";
	}
	cout << "]" << endl;
	cout << "Laser ranges are [ ";
	lasers->updateSensor(laserRange);
	for (int i = 0; i < 181; i++) {
		cout << laserRange[i] << " ";
	}
	cout << "]" << endl;
}
//!end-sensorMenu()

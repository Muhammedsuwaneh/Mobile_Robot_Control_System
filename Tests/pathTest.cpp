/**
* @file pathTest.cpp
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date January 1st, 2020
* @brief Path class test file
*
*
* This contains all the test attributed to the Path class
*/
#include "Path.h"
#include "Pose.h"
#include<iostream>
using namespace std;

/**
* main test function
*/

int main() {
	try {

		Path path;
		Pose pose;

		cout << "Adding 2, 3, 30 ........." << endl;
		pose.setX(2);
		pose.setY(3);
		pose.setTh(30);
		path.addPose(pose);

		cout << "Adding 5, 6, 60 ........." << endl;
		pose.setX(5);
		pose.setY(6);
		pose.setTh(60);
		path.addPose(pose);

		cout << "Adding 10, 7, 45 ........." << endl;
		pose.setX(10);
		pose.setY(7);
		pose.setTh(45);
		path.addPose(pose);

		cout << "Adding 8, 5, 120 ........." << endl;
		pose.setX(8);
		pose.setY(5);
		pose.setTh(120);
		path.addPose(pose);


		cout << "path.print()" << endl;
		path.print();
		cout << endl;
		cout << "path[2] ........." << endl;
		Pose pose1 = path[2];

		cout << "x: " << pose1.getX() << " y: " << pose1.getY() << " th: " << pose1.getTh() << endl;

		cout << "path.getPos(1) ........." << endl;
		Pose pose2 = path.getPos(1);
		cout << "x: " << pose2.getX() << " y: " << pose2.getY() << " th: " << pose2.getTh() << endl;


		cout << "path.removePose(0) ....." << endl;
		path.removePos(0);
		cout << "path.removePose(2) ....." << endl;
		path.removePos(2);

		Pose pose3, pose4, pose5;
		pose5.setPose(23, 13, 34);
		pose3.setPose(10, 20, 135);
		pose4.setPose(30, 60, 270);

		cout << "Inserting pose3 after index 0" << endl;
		path.insert(0, pose3);
		cout << "Inserting pose4after index 2" << endl;
		path.insert(2, pose4);


		cout << "cin >> pose5 ...." << endl;
		cout << path;
		cin >> path;
		cout << path;
	}
	catch (exception const& ex) {
		cerr << "Exception:  " << ex.what() << endl;
	}

	return 0;
}//!end-main
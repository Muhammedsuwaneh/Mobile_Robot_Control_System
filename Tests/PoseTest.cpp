#include<iostream>
#include"Pose.h"
using namespace std;
int main()
{
	Pose pose,pose1,poseSum,poseSub;
	float x, y, th;
	pose.setX(-3);
	pose.setY(-12);
	pose.setTh(60);
	pose1.setX(9);
	pose1.setY(4);
	pose1.setTh(30);
	pose == pose1 ? cout<<"Equal"<<endl : cout<<"Not Equal"<<endl;
	poseSum=pose + pose1;
	poseSub = pose - pose1;
	pose += pose1;
	cout << "Pose X: " << pose.getX()<<endl;
	cout << "Pose Y: " << pose.getY()<<endl;
	pose -= pose1;
	cout << "Pose X: " << pose.getX() << endl;
	cout << "Pose Y: " << pose.getY() << endl;
	cout<<"PoseSumX: "<<poseSum.getX()<<endl;
	cout << "PoseSumY: " << poseSum.getY() << endl;
	cout << "PoseSumTh: " << poseSum.getTh() << endl;
	cout <<"PoseSubX: "<<poseSub.getX() << endl;
	cout <<"PoseSubY: "<<poseSub.getY() << endl;
	cout <<"PoseSubTh: "<<poseSub.getTh() << endl;
	cout<<"Distance: "<<pose.findDistanceTo(pose1)<<endl;
	cout << "Angle: " << pose.findAngleTo(pose1)<<endl;
	pose.setPose(2, 5, 6);
	pose.getPose(x, y, th);
	cout << "x: " << x<<endl;
	cout << "y: " << y<<endl;
	cout << "th: " << th<<endl;
	return 0;
}
/**
 * @file Pose.h
 * @Author Yakupcan ERGEN
 * @date December, 2020
 * @brief This  class is responsible for holding location info and management of the robot.
 */
#ifndef POSE_H
#define POSE_H
class Pose
{
public:
	Pose() { x = 0; y = 0; th = 0; }
	Pose(float, float, float);
	float getX();
	void setX(float);
	float getY();
	void setY(float);
	void setTh(float);
	float getTh();
	bool operator ==(const Pose&);
	Pose operator +(const Pose&);
	Pose operator -(const Pose&);
	Pose& operator +=(const Pose&);
	Pose& operator -=(const Pose&);
	bool operator <(const Pose&);
	void getPose(float&, float&, float&);
	void setPose(float, float, float);
	float findDistanceTo(Pose);
	float findAngleTo(Pose);
private:
	float x;
	float y;
	float th;

};
#endif // !POSE_H


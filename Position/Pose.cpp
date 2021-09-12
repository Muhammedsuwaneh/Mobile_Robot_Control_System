#include "Pose.h"
#include<math.h>
/**
 * @file Pose.cpp
 * @Author Yakupcan ERGEN
 * @date December, 2020
 * @brief This  class is responsible for holding location info and management of the robot.
 */

Pose::Pose(float x, float y, float th)
{
	this->th = th;
	this->y = y;
	this->x = x;
}

//!getX returns the X
float Pose::getX()
{
	return x;
}
//!setX sets the X
/**
 *@param X an float argument.
 */
void Pose::setX(float x)
{
	this->x = x;
}
//!getY returns the Y
/**
 *@returns y
 */

float Pose::getY()
{
	return y;
}
//!setY sets the Y
/**
 *@param Y an float argument.
 */
void Pose::setY(float y)
{
	this->y = y;
}
//!setTh sets the th
/**
 *@param th an float argument.
 */
void Pose::setTh(float th)
{
	this->th = th;
}
/**
 *@returns y
 */
float Pose::getTh()
{
	return th;
}
//! == control whether is equal or not
/**
 *@param other is a Pose reference object.
 *@returns true or false as depending on condition.
 */
bool Pose::operator==(const Pose& other)
{
	return (other.x==this->x&&other.y==this->y&&other.th==this->th);
}
//! + sums two Position object
/**
 *@param other is a Pose reference object
 *@returns the temp object
 */
Pose Pose::operator+(const Pose& other)
{
	Pose temp;
	temp.x=other.x + this->x;
	temp.y = other.y + this->y;
	temp.th = (other.th + this->th);
	return temp;
}
//! - substracts two Position object
/**
 *@param other is a Pose reference object
 *@returns the temp object
 */
Pose Pose::operator-(const Pose& other)
{
	Pose temp;
	temp.x = other.x - this->x;
	temp.y = other.y - this->y;
	temp.th = (other.th - this->th);
	return temp;
}
//! += sums  this Object and Pose object
/**
 *@param other is a Pose reference object
 *@returns itself
 */
Pose& Pose::operator+=(const Pose&other)
{
	this->x += other.x;
	this->y += other.y;
	this->th += other.th;
	return *this;
}
//! -= substracts this object and Position object
/**
 *@param other is a Pose reference object
 *@returns itself
 */
Pose& Pose::operator-=(const Pose&other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->th -= other.th;
	return *this;
}
//! < compares this object and Pose object 
/**
 *@param other is a Pose reference object
 *@returns true or false as depending on case
 */
bool Pose::operator<(const Pose& other)
{
	return (this->x<other.x&&this->y<other.y&&this->th<other.th);
}
//! getPose assigns parameters
/**
 *@param x is a float reference argument.
 *@param y is a float reference argument.
 *@param th is a float reference argument.
 */
void Pose::getPose(float&x, float&y, float&th)
{
	x = this->x;
	y = this->y;
	th = this->th;
}
//!setPose sets taken arguments to this object's arguments
/**
 *@param x is a float reference argument.
 *@param y is a float reference argument.
 *@param th is a float reference argument.
 */
void Pose::setPose(float x, float y, float th){
	this->x = x;
	this->y = y;
	this->th = th;
}
//! findDistanceTo calculates the distance between two Pose objects
/**
 *@param p is a Pose object.
 *@returns the distance
 */
float Pose::findDistanceTo(Pose p)
{
	return pow(pow(p.x - this->x, 2) + pow(p.y - this->y, 2),0.5);
}
//! findDistanceTo calculates the distance between two Pose objects
/**
 *@param p is a Pose object.
 *@returns the angle
 */
float Pose::findAngleTo(Pose p)
{
	const double PI = 3.14;
	float result = atan((p.y - this->y)/(p.x - this->x)) * 180 / PI;
	return (result<0?180+result:result);
}

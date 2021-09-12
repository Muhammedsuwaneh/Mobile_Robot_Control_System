/**
* @file Path.h
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date December 30th, 2020
* @brief Path class declaration
*
*
* This file declares the Path class and all it's necessary functions
*/

#ifndef _PATH_
#define _PATH_
#include <iostream>
#include "pathNode.h"
#include "../Position/Pose.h"

using namespace std;

class Path
{
private:
	Node* tail;
	Node* head;
	int number;
public:
	Path();
	~Path();
	void addPose(Pose);
	void print();
	Pose& operator[](int);
	int size();
	Pose getPos(int);
	bool removePos(int);
	bool insert(int, Pose);
	friend ostream& operator <<(ostream&, Path&);
	friend istream& operator >>(istream&, Path&);
};

#endif //! _PATH_


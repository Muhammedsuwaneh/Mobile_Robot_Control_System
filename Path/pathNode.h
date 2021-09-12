/**
* @file pathNode.h
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date December 30th, 2020
* @brief PathNode struct declaration
*
*
* This file declares the PathNode declaration and all it's necessary
* pointers
*/
#ifndef _PATHNODE_
#define  _PATHNODE_
#include <iostream>
#include "../Position/Pose.h"

struct Node {

	Pose pose;
	struct Node* next;

	Node(Pose pose) {

		this->next = NULL;
		this->pose = pose;
	}
};

#endif //! _PATHNODE_
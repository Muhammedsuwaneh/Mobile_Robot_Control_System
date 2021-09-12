/**
* @file Path.cpp
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date December 30th, 2020
* @brief Path class definition file
*
*
* This contains all the Path class function definitions
*/

#include "Path.h"

using namespace std;
/**
* constructor
* @param initializes the head, tail node and number
*/
Path::Path() {

	this->head = this->tail = NULL;
	this->number = 0;
}//!end-Path()

/**
* destructor
* erases nodes
*/
Path::~Path() {
	//! erase nodes
	while (head) {
		Node* node = head;
		head = head->next;
		delete node;
		number--;
	}
}

/**
* adds a pose to the node
* @param pose is a Pose object
*/
void Path::addPose(Pose pose) {

	Node* temp, * curr;

	temp = curr = head;

	temp = new Node(pose);

	if (curr == NULL) {

		head = temp;
		tail = temp;
	}

	else {

		while (curr->next != NULL) {
			curr = curr->next;
		}//!end-while

		curr->next = temp;
		tail = curr->next;
	}
	print();
	number++;
}//!end-addPose()

/**
* prints node details
*/
void Path::print() {

	Node* temp = head;

	while (temp != NULL) {

		cout << "x: " << temp->pose.getX() << "  y: " << temp->pose.getY() << "  th: " << temp->pose.getTh() << endl;
		temp = temp->next;
	}//!end-while
	cout << "------------------------" << endl;

}//!end-print()

/**
*
* @param index -> index of node to return
* @returns pose object
*/
Pose& Path::operator[](int index) {

	//! throw errors
	if (index < 0 || index > number) {
		throw exception("Path::operator[] - Error ! Index is out of range");
	}

	//! perform [] operations
	Node* temp = head;
	int i = 0;

	while (i < index) {

		temp = temp->next;
		i++;
	}//!end-while

	return temp->pose;

}//!end-operator[]()

/**
* returns pose node found
* @param index -> index of node to return
* @returns pose object
*/
Pose Path::getPos(int index) {

	//! throw errors
	if (index < 0 || index > number) {
		throw exception("Pose getPos - Error ! Index is out of range");
	}
	//! perform getPos operations
	Node* temp = head;
	int i = 0;

	while (i < index) {

		temp = temp->next;
		i++;

	}//!end-while

	return temp->pose;

}
int Path::size()
{
	return number;
}
//!end-getPos()

/**
* removes node found on the given index
* @param index -> index of node to remove
* @returns returns a boolean
*/
bool Path::removePos(int index) {

	//! throw errors
	if (index < 0 || index > number) {
		throw exception("Path::removePos() - Error ! Index is out of range");
		return false;
	}

	//! perform removePos operations
	Node* curr, * prev;
	int i = 0;

	curr = prev = head;
	if (number == 0)
	{
		cout << "The path is empty.You can NOT delete any items!!!" << endl;
		return false;
	}
	else
	{
		while (curr != NULL) {

			if (i == index)
				break;

			prev = curr;
			curr = curr->next;
			i++;
		}

		if (curr == head)
			head = curr->next;
		else
			prev->next = curr->next;

		delete curr;

		number--;
	}
	return true;

}//!end-removePos

/**
* inserts a pose node after given index
* @param index -> index of node to print
* @param pose -> position object
* @returns returns a boolean
*/
bool Path::insert(int index, Pose pose) {

	//! throw errors
	if (index < 0 || index > number) {
		throw exception("Path::Insert() - Error ! Index is out of range");
		return false;
	}

	//! perform insert operations
	Node* temp, * curr, * prev;
	int i = 0;

	curr = head;
	temp = new Node(pose);


	while (curr != NULL) {

		if (index == i)
			break;

		prev = curr;
		curr = curr->next;
		i++;
	}

	//! insert after head
	if (curr == head) {

		temp->next = head->next;
		head->next = temp;
	}

	//! insert after ith pose Node
	else {

		temp->next = curr->next;
		curr->next = temp;
	}

	number++;
	return true;

}//!end-insert()

/**
*@param out -> cout operand
*@param path -> path object parameter
*@returns out -> cout operand
*/
ostream& operator<<(ostream& out, Path& path) {

	Node* temp = path.head;

	while (temp != NULL) {

		out << "x: " << temp->pose.getX() << "  y: " << temp->pose.getY() << "  th: " << temp->pose.getTh() << endl;
		temp = temp->next;
	}//!end-while
	return out;
}//!end-operator<<()

/**
*@param out -> cin operand
*@param path -> path object parameter
*@returns in -> cin operand
*/
istream& operator>>(istream& in, Path& path) {
	Pose pose;
	//! get entered values
	float x, y, th;

	cout << "Enter x, y and th in order: ";

	in >> x >> y >> th;
	pose.setPose(x, y, th);
	if (!in) {
		throw exception("istream& operator>> - Error ! One of the inputs is invalid");
	}
	//! add entered values to end of list

	path.addPose(pose);
	return in;
}//!end-operator>>()
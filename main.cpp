/**
* @file main.cpp
* @Author Muhammed Suwaneh (suwanehmuhammed1@gmail.com)
* @date last updated January, 24th, 2021
* @brief Path class declaration
*
*
* This file defines the MainMenu's necessary functions
*/

#include <iostream>
#include "Console Menu/mainMenu.h"

using namespace std;

/**
* mainMenu main function
*/
int main() {

	MainMenu menu;

	menu.displayMainMenu();

	cout << "\n\n";
	return 0;
}//!end-main
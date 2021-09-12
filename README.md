# Mobile Robot Control System

## Prerequisites 

This application requires some background work before running. The project is built in a Visual Studio Environment 
with C & C++ installed. A MobileSim Robot simulator software needs to be installed as well. 
MobileSim can be found here [`MobileSim-0.7.5.exe`](Map/MobileSim-0.7.5.exe). 

## About

The Mobile Robot Control System is C/C++ Console Application that controls the movement of a Robot in a simulation environment. It 
basically serves as the Robot controller. The MobileSim(The simulation environment) is connected to the Console Application via the Aria 
API and Libraries. The Console Application has classes and methods that help to facilitate the simulation process.
To run the application successfully, the MobileSim software needs to be opened. The simulator map can then be loaded to the MobileSim.
The simulator map can be found here [`office.map`](Map/office.map). 

## App Features 

### MobileSim Software & Map

This software & map serves as a simulation environment for the robot. 
The map is connected to the console application which serves as the controller.

![Screenshot](Screenshots/map.png)

### Main Console Menu 

![Screenshot](Screenshots/main.png)

### Connection

This menu connects the Console Application and the MobileSim using the [`PioneerRobotAPI`](API/PioneerRobotAPI.h) 

![Screenshot](Screenshots/connectionMenu.png)

When Robot is connected ...

![Screenshot](Screenshots/connection.png)

### Robot's Motion

![Screenshot](Screenshots/motion.png) 


### Robot's Movement 

![Screenshot](Screenshots/move.png) 

### Robot's Turning - Left/Right/Rotation

![Screenshot](Screenshots/turn.png) 

### Robot's Sensors 

![Screenshot](Screenshots/sensor.png) 

### Robot's Position

![Screenshot](Screenshots/position.png) 

## Technologies

C, C++, MobileSim, SWIG 

## Contributors 

1.Muhammed Suwaneh, Eskişehir Osmangazi University, Eskişehir, Turkey.
2.Yakupcan Ergen, Eskişehir Osmangazi University, Eskişehir, Turkey.
3.Kadirhan Kubat, Eskişehir Osmangazi University, Eskişehir, Turkey.
4.Alperen Bişkin, Eskişehir Osmangazi University, Eskişehir, Turkey.


## Project Supervisor 

1. Dr. Metin Özcan, Professor & Lecturer @Eskişehir Osmangazi University, Eskişehir, Turkey.

## Disclaimer 

The project was part develop as part of the requirement for the Object Oriented Programming Software Course.
It serves as one of the portfolio projects of the above contributors. The project in no way should be used 
for marketable or commercial purposes. 

## The Project is license under [`MIT`](LICENSE) Copyright 2020-21


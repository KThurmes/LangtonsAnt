/********************************************************************* 
** Author: Katheen Thurmes
** Date: 8 Oct., 2019
** Description: An ant object designed for use in the implementation 
of a Langton's Ant simulation. It keeps track of its location on the 
board and which direction it is facing. It can also turn 90 degrees 
to the left or right.
*********************************************************************/ 

#include "Ant.hpp"

Ant::Ant()
{
}

Ant::Ant(int row, int col, int orient)
{
    locationRow = row;
    locationCol = col;
    orientation = orient;
}

void Ant::setLocation(int row, int col)
{
    locationRow = row;
    locationCol = col;
}

void Ant::setOrientation(int orient)
{
    orientation = orient;
}

int Ant::getLocationRow()
{
    return locationRow;
}

int Ant::getLocationCol()
{
    return locationCol;
}

int Ant::getOrientation()
{
    return orientation;
}

/********************************************************************* 
** Description: Turns the ant to the right by modifying its 
orientation
*********************************************************************/ 
void Ant::turnRight()
{
    orientation = (orientation + 1) % 4;
}

/********************************************************************* 
** Description: Turns the ant to the left by modifying its 
orientation
*********************************************************************/ 
void Ant::turnLeft()
{
    orientation = (orientation + 3) % 4;
}
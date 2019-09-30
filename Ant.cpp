#include "Ant.hpp"

Ant::Ant()
{
    orientation = 0;
    locationRow = 0;
    locationCol = 0;
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

void Ant::turnRight()
{
    orientation = (orientation + 1) % 4;
}

void Ant::turnLeft()
{
    orientation = (orientation + 3) % 4;
}

int Ant::getOrientation()
{
    return orientation;
}
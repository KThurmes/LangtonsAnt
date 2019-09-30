#ifndef ANT_HPP
#define ANT_HPP

class Ant
{

private:
    int orientation;
    int locationRow;
    int locationCol;

public:
    Ant();
    Ant(int, int, int);
    void setLocation(int, int);
    int getLocationRow();
    int getLocationCol();
    void turnRight();
    void turnLeft();
    int getOrientation();
    void setOrientation(int);
};

#endif
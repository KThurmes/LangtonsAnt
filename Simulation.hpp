#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Ant.hpp"
#include "Board.hpp"

class Simulation
{

private:
    Board gameBoard;
    int totalMoves;
    Ant agentAnt;
    void antStep();
    void moveAnt();

public:
    Simulation();
    Simulation(int, int, int, int, int);
    void playGame();
};

#endif
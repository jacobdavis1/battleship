#ifndef OCEANGRID_H
#define OCEANGRID_H

#include <vector>
#include <random>
#include "GridRow.h"

using namespace std;

class OceanGrid
{
public:
    OceanGrid(int width, int height);
    virtual ~OceanGrid();

    void placeShip(int shipSize, uniform_int_distribution<std::mt19937::result_type> columnDisttribution,
                          uniform_int_distribution<std::mt19937::result_type> gridDist, mt19937 generator);
    bool fireOnSpace(int rowId, char columnId);
    bool checkAllShipsSunk();
    void resetBoard();

    void printGrid();

protected:

private:
    vector<GridRow> grid;
    vector<int> occupiedRows;
};

#endif // OCEANGRID_H

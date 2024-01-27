#include "OceanGrid.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

OceanGrid::OceanGrid(int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        grid.push_back(GridRow(width));
    }
}

OceanGrid::~OceanGrid()
{
    for (int rowId = 0; rowId < grid.size(); ++rowId)
    {
        for (int columnId; columnId < grid.at(rowId).getSize(); ++columnId)
        {
            delete grid.at(rowId).at(columnId);
        }
    }
}

bool OceanGrid::fireOnSpace(int rowId, char columnId)
{
    char filteredId = toupper(columnId);
    int asciiAnchor = (int)'A';
    int numericId = filteredId - asciiAnchor;

    if (numericId < 10)
    {
        grid.at(rowId).at(numericId)->fireOnSpace();
        return true;
    }
    else
    {
        cout << "Invalid attack command. Use fire row column, where row is 0-9 and column is A-J" << endl;
        return false;
    }
}

void OceanGrid::resetBoard() // Randomly assigns boats for both player and ai, rehides all spaces
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<mt19937::result_type> gridDist(0, 9);
    uniform_int_distribution<mt19937::result_type> smallBoatDist(0, 8);
    uniform_int_distribution<mt19937::result_type> mediumBoatDist(0, 7);
    uniform_int_distribution<mt19937::result_type> subDist(0, 6);
    uniform_int_distribution<mt19937::result_type> battleshipDist(0, 5);

    grid.clear();
    for (int i = 0; i < 10; ++i)
        grid.push_back(GridRow(10));

    placeShip(2, gridDist, smallBoatDist, generator);
    placeShip(3, gridDist, mediumBoatDist, generator);
    placeShip(4, gridDist, subDist, generator);
    placeShip(5, gridDist, battleshipDist, generator);
}

/*
This places one ship of each size on different rows. The ships will go horizontal,
and extend to the right
*/
void OceanGrid::placeShip(int shipSize, uniform_int_distribution<std::mt19937::result_type> columnDistribution,
                          uniform_int_distribution<std::mt19937::result_type> gridDist, mt19937 generator)
{
    int row = gridDist(generator);

    if (find(occupiedRows.begin(), occupiedRows.end(), row) == occupiedRows.end())
    {
        int column = (int)'A' + columnDistribution(generator);
        for (int i = 0; i < shipSize; ++i)
        {
            grid.at(row).at(column - (int)'A')->setOccupied();
        }
    }
}

/*
We check all ships have sunk by just scanning the entire grid
for any occupied space that is not destroyed
*/
bool OceanGrid::checkAllShipsSunk()
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.at(i).getSize(); ++i)
        {
            GridSpace* space = grid.at(i).at(j);
            if (space->getOccupied() && !space->getDestroyed())
                return false;

        }
    }

    return true;
}

void OceanGrid::printGrid()
{
    cout << "    A B C D E F G H I J" << endl;
    for (int rowId = 0; rowId < grid.size(); ++rowId)
    {
        cout << " " << rowId << "  ";
        for (int columnId = 0; columnId < grid.at(rowId).getSize(); ++columnId)
        {
            cout << grid.at(rowId).at(columnId)->getStatusChar() << " ";
        }
        cout << endl;
    }
}

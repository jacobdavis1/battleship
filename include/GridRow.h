#ifndef GRIDROW_H
#define GRIDROW_H

#include "GridSpace.h"
#include <vector>

using namespace std;

class GridRow
{
public:
    GridRow(int length);

    GridSpace* at(int index);
    int getSize();

private:
    vector<GridSpace*> row;

    friend class OceanGrid;
};

#endif // GRIDROW_H

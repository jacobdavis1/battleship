#include "GridRow.h"

GridRow::GridRow(int length)
{
    for (int i = 0; i < length; ++i)
    {
        row.push_back(new GridSpace());
    }
}

GridSpace* GridRow::at(int index)
{
    return row.at(index);
}

int GridRow::getSize()
{
    return row.size();
}

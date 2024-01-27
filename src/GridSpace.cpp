#include "GridSpace.h"

StatusName GridSpace::getStatus()
{
    if (hidden)
    {
        return StatusName::Hidden;
    }

    if (destroyed)
    {
        return StatusName::Destroyed;
    }

    return StatusName::Empty;
}

void GridSpace::setOccupied()
{
    occupied = true;
}

bool GridSpace::fireOnSpace()
{
    if (occupied)
    {
        destroyed = true;
    }

    hidden = false;
}

char GridSpace::getStatusChar()
{
    switch (getStatus())
    {
        case StatusName::Destroyed: return 'X';

        case StatusName::Empty: return ' ';

        case StatusName::Hidden: return '?';
    }
}

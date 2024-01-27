#ifndef GRIDSPACE_H
#define GRIDSPACE_H

enum StatusName { Hidden, Empty, Destroyed };

class GridSpace
{
public:
    StatusName getStatus();
    void setOccupied();
    bool fireOnSpace();
    char getStatusChar();

    bool getOccupied() { return occupied; }
    bool getHidden() { return hidden; }
    bool getDestroyed() { return destroyed; }

private:
    StatusName status = StatusName::Hidden;
    bool occupied = false, hidden = true, destroyed = false;
};

#endif // GRIDSPACE_H

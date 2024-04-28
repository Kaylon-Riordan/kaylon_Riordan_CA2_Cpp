#include "SuperBug.h"

SuperBug::SuperBug(int id, int x, int y, int direction, int size)
        : Bug(id, x, y, direction, size)
{this->type = "SuperBug";}

void SuperBug::move() {
    pair<int, int> pos = getPosition();

    switch(direction) {
        case 1: pos.second --; break;
        case 2: pos.first ++; break;
        case 3: pos.second ++; break;
        case 4: pos.first --; break;
        default: break; // default
    }

    setPosition(pos);
    list<pair<int,int>> newPath = getPath();
    newPath.push_back(pos);
    setPath(newPath);
}

SuperBug::~SuperBug() { cout << "~SuperBug() destructor called.\n"; }
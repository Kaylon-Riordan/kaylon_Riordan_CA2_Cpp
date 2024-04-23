#include "Hopper.h"
#include <iostream>
using namespace std;

Hopper::Hopper(int id, int x, int y, int direction, int size, int hopLength)
        : Bug(id, x, y, direction, size)
        {
            this->hopLength = hopLength;
        }

void Hopper::move() {
    pair<int, int> pos = getPosition();

    while(isWayBlocked()){
        direction = 1 + (rand() % 4);
    }

    switch(direction) {
        case 1:
            pos.second = pos.second - hopLength;
            if(pos.second < 0){pos.second = 0;}
            setPosition(pos);
            break;
        case 2:
            pos.first = pos.first + hopLength;
            if(pos.first > 9){pos.first = 9;}
            setPosition(pos);
            break;
        case 3:
            pos.second = pos.second + hopLength;
            if(pos.second > 9){pos.second = 9;}
            setPosition(pos);
            break;
        case 4:
            pos.first = pos.first - hopLength;
            if(pos.first < 0){pos.first = 0;}
            setPosition(pos);
            break;
        default:
            // default
    }

    setPosition(pos);
    getPath().push_back(pos);
}

int Hopper::getHopLength() const{
    return hopLength;
}
void Hopper::setHopLength(int hopLength){
    Hopper::hopLength = hopLength;
}

Hopper::~Hopper() { cout << "~Hopper() destructor called.\n"; }
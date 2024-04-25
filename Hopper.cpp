#include "Hopper.h"

Hopper::Hopper(int id, int x, int y, int direction, int size, int hopLength)
        : Bug(id, x, y, direction, size)
        {this->type = "Hopper";this->hopLength = hopLength;}

void Hopper::move() {
    if(alive){
        pair<int, int> pos = getPosition();

        while(isWayBlocked()){
            srand(time(NULL));
            direction = 1 + (rand() % 4);
        }

        switch(direction) {
            case 1:
                pos.second = pos.second - hopLength;
                if(pos.second < 0){pos.second = 0;}
                setPosition(pos); break;
            case 2:
                pos.first = pos.first + hopLength;
                if(pos.first > 9){pos.first = 9;}
                setPosition(pos); break;
            case 3:
                pos.second = pos.second + hopLength;
                if(pos.second > 9){pos.second = 9;}
                setPosition(pos); break;
            case 4:
                pos.first = pos.first - hopLength;
                if(pos.first < 0){pos.first = 0;}
                setPosition(pos); break;
            default: break; // default
        }

        setPosition(pos);
        getPath().push_back(pos);
    }
}

int Hopper::getHopLength() const{
    return hopLength;
}

void Hopper::setHopLength(int hopLength){
    Hopper::hopLength = hopLength;
}

string Hopper::toString(){
    string dir;
    switch(direction) {
        case 1: dir = "North"; break;
        case 2: dir = "East"; break;
        case 3: dir = "South"; break;
        case 4: dir = "West"; break;
        default: break; // default
    }
    string live = "Alive!";
    if(!alive){live = "Dead!";}

    string str = type + "\t\t" + to_string(id) + "\t<" + to_string(position.first) + "," + to_string(position.second)
                 + ">\t\t" + dir + "\t\t" + to_string(size) + "\t\t" + live + "\t\t" + to_string(hopLength);
    return str;
}

Hopper::~Hopper() { cout << "~Hopper() destructor called.\n"; }
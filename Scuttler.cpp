#include "Scuttler.h"

Scuttler::Scuttler(int id, int x, int y, int direction, int size)
        : Bug(id, x, y, direction, size)
{this->type = "Scuttler\t";}

bool Scuttler::isWayBlocked(){ // change is way blocked to check diagonals
    if(direction == 1 && (position.second == 0 || position.first == 9)){
        return true;
    }
    else if(direction == 2 && (position.first == 9 || position.second == 9)){
        return true;
    }
    else if(direction == 3 && (position.second == 9 || position.first == 0)){
        return true;
    }
    else if(direction == 4 && (position.first == 0 || position.second == 0)){
        return true;
    }
    else{
        return false;
    }
}

void Scuttler::move() {
    if(alive){
        pair<int, int> pos = getPosition();

        while(isWayBlocked()){
            srand(time(NULL));
            direction = 1 + (rand() % 4);
        }

        switch(direction) { // move one space diagonally
            case 1: pos.second --; pos.first ++; break;
            case 2: pos.first ++; pos.second ++; break;
            case 3: pos.second ++; pos.first --; break;
            case 4: pos.first --; pos.second --; break;
            default: break; // default
        }

        setPosition(pos);
        list<pair<int,int>> newPath = getPath();
        newPath.push_back(pos);
        setPath(newPath);
    }
}

string Scuttler::toString(){ // change to sting to show diagonal directions
    string dir;
    switch(direction) {
        case 1: dir = "North-East"; break;
        case 2: dir = "South-East"; break;
        case 3: dir = "South-West"; break;
        case 4: dir = "North-West"; break;
        default: break; // default
    }
    string live = "Alive!";
    if(!alive){live = "Dead!";}

    string str = type + to_string(id) + "\t<" + to_string(position.first) + "," + to_string(position.second)
                 + ">\t\t" + dir + "\t" + to_string(size) + "\t\t" + live + "\t\tN/A";
    return str;
}

Scuttler::~Scuttler() { cout << "~Scuttler() destructor called.\n"; }
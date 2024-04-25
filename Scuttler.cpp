#include "Scuttler.h"

Scuttler::Scuttler(int id, int x, int y, int direction, int size)
        : Bug(id, x, y, direction, size)
{this->type = "Scuttler";}

bool Scuttler::isWayBlocked(){
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
            direction = 1 + (rand() % 4);
        }

        switch(direction) {
            case 1: pos.second --; pos.first ++; break;
            case 2: pos.first ++; pos.second ++; break;
            case 3: pos.second ++; pos.first --; break;
            case 4: pos.first --; pos.second --; break;
            default: break; // default
        }

        setPosition(pos);
        getPath().push_back(pos);
    }
}

string Scuttler::toString(){
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

    string str = type + "\t" + to_string(id) + "\t<" + to_string(position.first) + "," + to_string(position.second)
                 + ">\t\t" + dir + "\t" + to_string(size) + "\t\t" + live + "\t\tN/A";
    return str;
}

string Scuttler::historyToString(){
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

    string str = type + "\t" + to_string(id) + "\t\t" + live + "\t\t[";
    for(pair<int, int> pos : path){
        str += "<" + to_string(pos.first) + "," + to_string(pos.second) + ">,";
    }
    str += "]";
    return str;
}

Scuttler::~Scuttler() { cout << "~Scuttler() destructor called.\n"; }
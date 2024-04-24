#include "Crawler.h"

Crawler::Crawler(int id, int x, int y, int direction, int size)
    : Bug(id, x, y, direction, size) {}

void Crawler::move() {
    pair<int, int> pos = getPosition();

    while(isWayBlocked()){
        direction = 1 + (rand() % 4);
    }

    switch(direction) {
        case 1: pos.second --; break;
        case 2: pos.first ++; break;
        case 3: pos.second ++; break;
        case 4: pos.first --; break;
        default: break; // default
    }

    setPosition(pos);
    getPath().push_back(pos);
}

string Crawler::toString(){
    string dir;
    switch(direction) {
        case 1: dir = "North"; break;
        case 2: dir = "East"; break;
        case 3: dir = "South"; break;
        case 4: dir = "West"; break;
        default: break; // default
    }

    string str = "class: crawler, id: " + to_string(id) + ", position: <" + to_string(position.first) + "," + to_string(position.second)
            + ">, direction: " + dir + ", size: " + to_string(size) + ", alive: " + to_string(alive) + ", path: [";
    for(pair<int, int> pos : path){
        str += "<" + to_string(pos.first) + "," + to_string(pos.second) + ">,";
    }
    str += "]";
    return str;
}

Crawler::~Crawler() { cout << "~Crawler() destructor called.\n"; }
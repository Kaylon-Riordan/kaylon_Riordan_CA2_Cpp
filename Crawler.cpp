#include "Crawler.h"

Crawler::Crawler(int id, int x, int y, int direction, int size)
    : Bug(id, x, y, direction, size)
    {this->type = "Crawler\t\t";}

void Crawler::move() {
    if(alive){
        pair<int, int> pos = getPosition();

        while(isWayBlocked()){
            srand(time(NULL));
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
        list<pair<int,int>> newPath = getPath();
        newPath.push_back(pos);
        setPath(newPath);
    }
}

Crawler::~Crawler() { cout << "~Crawler() destructor called.\n"; }
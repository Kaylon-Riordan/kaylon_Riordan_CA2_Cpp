#include "Crawler.h"

Crawler::Crawler(int id, int x, int y, int direction, int size)
    : Bug(id, x, y, direction, size)
    {this->type = "Crawler";}

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
        getPath().push_back(pos);
    }
}

Crawler::~Crawler() { cout << "~Crawler() destructor called.\n"; }
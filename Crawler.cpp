#include "Crawler.h"
#include <iostream>
using namespace std;

Crawler::Crawler(int id, int x, int y, int direction, int size)
    : Bug(id, x, y, direction, size) {}

void Crawler::move() {
    pair<int, int> pos = getPosition();

    while(isWayBlocked()){
        direction = 1 + (rand() % 4);
    }

    switch(direction) {
        case 1:
            pos.second --;
            break;
        case 2:
            pos.first ++;
            break;
        case 3:
            pos.second ++;
            break;
        case 4:
            pos.first --;
            break;
        default:
            // default
    }

    setPosition(pos);
    getPath().push_back(pos);
}

Crawler::~Crawler() { cout << "~Crawler() destructor called.\n"; }
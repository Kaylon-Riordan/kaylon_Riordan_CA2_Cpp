#include "Crawler.h"
#include <iostream>
using namespace std;

Crawler::Crawler(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int,int>> path)
    : Bug(id, position, direction, size, alive, path) {}

void Crawler::move() {
    pair<int, int> pos = getPosition();
    getPath().push_back(pos);


    switch(direction) {
        case 1:
            pos.second --;
            setPosition(pos);
            break;
        case 2:
            pos.first ++;
            setPosition(pos);
            break;
        case 3:
            pos.second ++;
            setPosition(pos);
            break;
        case 4:
            pos.first --;
            setPosition(pos);
            break;
        default:
            // default
    }
}

Crawler::~Crawler() { cout << "~Crawler() destructor called.\n"; }
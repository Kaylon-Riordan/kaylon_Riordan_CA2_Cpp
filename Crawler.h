#ifndef KAYLON_RIORDAN_CA3_CPP_CRAWLER_H
#define KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

#include "Bug.h"
#include <utility>
#include <list>
#include <iostream>

class Crawler : public Bug {
protected:
    Crawler(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path);
    void move();

public:
    ~Crawler();
};

#endif //KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

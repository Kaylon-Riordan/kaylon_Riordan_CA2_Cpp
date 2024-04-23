#ifndef KAYLON_RIORDAN_CA3_CPP_CRAWLER_H
#define KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

#include "Bug.h"
#include <utility>
#include <list>
#include <iostream>

class Crawler : public Bug {
protected:
    void move();

public:
    Crawler(int id, int x, int y, int direction, int size);
    ~Crawler();
};

#endif //KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

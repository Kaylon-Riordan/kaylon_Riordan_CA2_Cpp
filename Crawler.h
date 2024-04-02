#ifndef KAYLON_RIORDAN_CA3_CPP_CRAWLER_H
#define KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
protected:
    void move();

public:
    Crawler(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int,int>> path){
        this->id = id;
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = alive;
        this->path = path;
    }

    ~Crawler();
};

#endif //KAYLON_RIORDAN_CA3_CPP_CRAWLER_H

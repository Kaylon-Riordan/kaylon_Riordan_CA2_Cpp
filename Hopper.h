#ifndef KAYLON_RIORDAN_CA3_CPP_HOPPER_H
#define KAYLON_RIORDAN_CA3_CPP_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

protected:
    void move();

public:
    Hopper(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int,int>> path, int hopLength){
        this->id = id;
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = alive;
        this->path = path;
        this->hopLength = hopLength;
    }

    ~Hopper();
};

#endif //KAYLON_RIORDAN_CA3_CPP_HOPPER_H

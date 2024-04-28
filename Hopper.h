#ifndef KAYLON_RIORDAN_CA3_CPP_HOPPER_H
#define KAYLON_RIORDAN_CA3_CPP_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, int direction, int size, int hopLength);
    void move();
    int getHopLength() const;
    void setHopLength(int hopLength);
    string toString();

    ~Hopper();
};

#endif //KAYLON_RIORDAN_CA3_CPP_HOPPER_H

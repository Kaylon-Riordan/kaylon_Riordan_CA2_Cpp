#ifndef KAYLON_RIORDAN_CA3_CPP_SUPERBUG_H
#define KAYLON_RIORDAN_CA3_CPP_SUPERBUG_H

#include "Bug.h"

class SuperBug : public Bug  {
public:
    SuperBug(int id, int x, int y, int direction, int size);
    void move();

    ~SuperBug();
};

#endif //KAYLON_RIORDAN_CA3_CPP_SUPERBUG_H

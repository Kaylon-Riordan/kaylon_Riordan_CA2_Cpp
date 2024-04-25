#ifndef KAYLON_RIORDAN_CA3_CPP_SCUTTLER_H
#define KAYLON_RIORDAN_CA3_CPP_SCUTTLER_H

#include "Bug.h"

class Scuttler : public Bug {
protected:
    void move();
    bool isWayBlocked();

public:
    Scuttler(int id, int x, int y, int direction, int size);
    string toString();
    string historyToString();

    ~Scuttler();
};

#endif //KAYLON_RIORDAN_CA3_CPP_SCUTTLER_H

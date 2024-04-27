#ifndef KAYLON_RIORDAN_CA3_CPP_BUG_H
#define KAYLON_RIORDAN_CA3_CPP_BUG_H

#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Bug {
protected:
    Bug(int id, int x, int y, int direction, int size);

    string type;
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>> path;
    int eatenBy;
    virtual bool isWayBlocked();

public:
    string getType() const;
    void setType(string Type);
    int getId() const;
    void setId(int id);
    pair<int, int> getPosition() const;
    void setPosition(pair<int, int> position);
    int getDirection() const;
    void setDirection(int direction);
    int getSize() const;
    void setSize(int size);
    bool getAlive() const;
    void setAlive(bool alive);
    list<pair<int,int>> getPath() const;
    void setPath(list<pair<int,int>> path);
    int getEatenBy() const;
    void setEatenBy(int eatenBy);
    virtual void move() = 0;
    virtual string toString();
    string historyToString();

    virtual ~Bug();
};

#endif //KAYLON_RIORDAN_CA3_CPP_BUG_H
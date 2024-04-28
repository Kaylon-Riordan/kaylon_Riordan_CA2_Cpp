#ifndef KAYLON_RIORDAN_CA3_CPP_BUG_H
#define KAYLON_RIORDAN_CA3_CPP_BUG_H

#include <list> // put most includes in bug.h as every file is connected back to this one
#include <string>
#include <utility>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class Bug {
protected:
    Bug(int id, int x, int y, int direction, int size); // constructor

    string type; // attributes of bug
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>> path;
    int eatenBy;

public:
    string getType() const; // getters and setters
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
    virtual bool isWayBlocked(); // virtual methods that can be overwritten
    virtual void move() = 0; // true virtual method that has to be overwritten
    virtual string toString();
    string historyToString();

    virtual ~Bug();
};

#endif //KAYLON_RIORDAN_CA3_CPP_BUG_H
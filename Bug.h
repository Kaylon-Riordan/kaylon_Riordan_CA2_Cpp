#ifndef KAYLON_RIORDAN_CA3_CPP_BUG_H
#define KAYLON_RIORDAN_CA3_CPP_BUG_H

#include <list>
using namespace std;

class Bug {
protected:
    Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path);

    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int,int>> path;
    virtual void move();
    bool isWayBlocked();

public:
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

    virtual ~Bug();
};

#endif //KAYLON_RIORDAN_CA3_CPP_BUG_H
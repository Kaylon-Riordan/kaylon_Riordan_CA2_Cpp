#include "Bug.h"
#include <iostream>
using namespace std;

Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int,int>> path)
{
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;
    this->alive = alive;
    this->path = path;
}

bool Bug::isWayBlocked(){
    if(direction == 1 && position.second == 0){
        return true;
    }
    else if(direction == 2 && position.first == 9){
        return true;
    }
    else if(direction == 3 && position.second == 9){
        return true;
    }
    else if(direction == 4 && position.first == 0){
        return true;
    }
    else{
        return false;
    }
}

int Bug::getId() const{
    return id;
}
void Bug::setId(int id){
    Bug::id = id;
}

pair<int, int> Bug::getPosition() const{
    return position;
}
void Bug::setPosition(pair<int, int> position){
    Bug::position = position;
}

int Bug::getDirection() const{
    return direction;
}
void Bug::setDirection(int direction){
    Bug::direction = direction;
}

int Bug::getSize() const{
    return size;
}
void Bug::setSize(int size){
    Bug::size = size;
}

bool Bug::getAlive() const{
    return alive;
}
void Bug::setAlive(bool alive){
    Bug::alive = alive;
}

list<pair<int,int>> Bug::getPath() const{
    return path;
}
void Bug::setPath(list<pair<int,int>> path){
    Bug::path = path;
}

Bug::~Bug() { cout << "~Bug() destructor called.\n"; }
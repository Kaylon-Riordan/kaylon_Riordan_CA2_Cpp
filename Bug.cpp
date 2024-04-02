#include "Bug.h"

//Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int,int>> path)
//{
//    this->id = id;
//    this->position = position;
//    this->direction = direction;
//    this->size = size;
//    this->alive = alive;
//    this->path = path;
//}

bool isWayBlocked() {

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
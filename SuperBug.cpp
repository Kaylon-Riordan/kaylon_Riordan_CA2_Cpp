#include "SuperBug.h"

SuperBug::SuperBug(int id, int x, int y, int direction, int size)
        : Bug(id, x, y, direction, size)
{this->type = "SuperBug";}

void SuperBug::move() {}

SuperBug::~SuperBug() { cout << "~SuperBug() destructor called.\n"; }
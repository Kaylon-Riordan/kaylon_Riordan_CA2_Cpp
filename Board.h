#ifndef KAYLON_RIORDAN_CA3_CPP_BOARD_H
#define KAYLON_RIORDAN_CA3_CPP_BOARD_H

#include <sstream>
#include <fstream>
#include "Crawler.h"
#include "Hopper.h"

class Board {
private:
    list<Bug*> bugs;

    void parseLine(const string &strLine, list<Bug*> &bugs);
    list<Bug*> inputFileStream(string fileName);

public:
    Board();

    void displayAllBugs();

    ~Board();
};

#endif //KAYLON_RIORDAN_CA3_CPP_BOARD_H
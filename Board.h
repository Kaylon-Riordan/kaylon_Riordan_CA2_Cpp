#ifndef KAYLON_RIORDAN_CA3_CPP_BOARD_H
#define KAYLON_RIORDAN_CA3_CPP_BOARD_H

#include <windows.h>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Crawler.h"
#include "Hopper.h"
#include "Scuttler.h"

class Board {
private:
    list<Bug*> bugs;

    void parseLine(const string &strLine, list<Bug*> &bugs);

public:
    Board();

    void displayAllBugs();
    void displayAllHistory();
    void displayBugByID(int id);
    void displayAllCells();
    void movementPhase();
    void fightPhase();
    void runSimulation();
    const list<Bug *> &getBugs() const;
    void setBugs(const list<Bug*> &bugs);
    list<Bug*> inputFileStream(string fileName);
    void OutputFileStream();
    void Graphics();

    ~Board();
};

#endif //KAYLON_RIORDAN_CA3_CPP_BOARD_H
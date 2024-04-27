#include "Board.h"
#include <stdio.h>
#include <time.h>

Board::Board()
{
    this->bugs = inputFileStream("bugs.txt");
}

void Board::displayAllBugs() {
    cout << "\nClass:\t\tID:\tPosition:\tDirection:\tSize:\t\tStatus:\t\tHop Length:" << endl;
    for(Bug* bugP : bugs){
        cout << bugP->toString() << endl;
    }
}

void Board::displayAllHistory() {
    cout << "\nClass:\t\tID:\tPath:" << endl;
    for(Bug* bugP : bugs){
        cout << bugP->historyToString() << endl;
    }
}

void Board::displayBugByID(int id) {
    bool found = false;
    for(Bug* bugP : bugs){
        if(bugP->getId() == id){
            cout << "\nClass:\t\tID:\tPosition:\tDirection:\tSize:\t\tStatus:\t\tHop Length:" << endl;
            cout << bugP->toString() << endl;
            found = true;
        }
    }
    if(!found){
        cout << "No bug was found with the ID " + id << endl;
    }
}

void Board::displayAllCells(){
    int x = 0; int y; pair<int, int> cell; bool empty;
    while(x < 10){
        y = 0;
        while(y < 10){
            empty = true;
            cell.first = x;
            cell.second = y;
            cout << "\n(" << x << "," << y << "):";
            for(Bug* bugP : bugs){
                if(bugP->getPosition() == cell){
                    cout << " ," << bugP->getType() << " " << bugP->getId();
                    empty = false;
                }
            }
            if(empty){
                cout << " empty";
            }
            y++;
        }
        x++;
    }
}

void Board::movementPhase() {
    for(Bug* bugP : bugs){
        bugP->move();
    }
    fightPhase();
}

void Board::fightPhase() {
    int x = 0; int y; int biggest; int total; int winner;
    pair<int, int> cell; list<Bug*> inCell; list<Bug*> contenders;
    while(x < 10){
        y = 0;
        while(y < 10){
            cell.first = x; cell.second = y;
            biggest = 0; total = 0; inCell.clear(); contenders.clear();
            for(Bug* bugP : bugs){
                if(bugP->getPosition() == cell && bugP->getAlive()){
                    inCell.push_back(bugP);
                    total += bugP->getSize();
                    if(bugP->getSize() > biggest){
                        biggest = bugP->getSize();
                        contenders.clear();
                        contenders.push_back(bugP);
                    }
                    else if(bugP->getSize() == biggest){
                        contenders.push_back(bugP);
                    }
                }
            }
            if(contenders.size() > 0){
                // source for getting random numbers: https://stackoverflow.com/questions/13896450/rand-returns-the-same-number-each-time-the-program-is-run
                srand(time(NULL));
                int win = rand() % contenders.size();
                for(Bug* bugP : contenders){
                    if(win == 0){
                        winner = bugP-> getId();
                        bugP->setSize(total);
                    }
                    win--;
                }
            }
            for(Bug* bugP : inCell){
                if(bugP->getSize() < total){
                    bugP->setEatenBy(winner);
                    bugP->setAlive(false);
                }
            }
            y++;
        }
        x++;
    }
}

void Board::runSimulation(){ //Code for running method every second from: https://stackoverflow.com/questions/10807681/loop-every-10-second
    int living =100;
    double time_counter = 0;
    clock_t this_time = clock();
    clock_t last_time = this_time;
    while(true)
    {
        if(living <= 1){break;}
        this_time = clock();
        time_counter += (double)(this_time - last_time);
        last_time = this_time;
        if(time_counter > (double)(CLOCKS_PER_SEC))
        {
            time_counter -= (double)(CLOCKS_PER_SEC);
            living = 0;
            movementPhase();
            for(Bug* bugP : bugs){if(bugP->getAlive()){living++;}}
            displayAllBugs();
        }
    }
    int winner;
    for(Bug* bugP : bugs){if(bugP->getAlive()){winner = bugP->getId();}}
    cout << "Winner is " << to_string(winner) << endl;
}

const list<Bug *> &Board::getBugs() const {
    return bugs;
}

void Board::setBugs(const list<Bug *> &bugs) {
    Board::bugs = bugs;
}

void Board::parseLine(const string &strLine, list<Bug*> &bugs) { // Code for parsing lines from: https://github.com/logued/cpp-file-IO-text-file-demo
    stringstream strStream(strLine);

    const char DELIMITER = ';'; // as this is specified in the specification

    string bug_type;
    getline(strStream, bug_type, DELIMITER);
    string strTemp; // temporary string

    try {
        getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
        int id = stoi(strTemp); // convert string to int conversion (may throw exceptions)

        getline(strStream, strTemp, DELIMITER);
        int x = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        int y = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        int direction = stoi(strTemp);

        getline(strStream, strTemp, DELIMITER);
        int size = stoi(strTemp);

        if (bug_type == "C") { // if it is Crawler, then read the Crawler fields
            // now, instantiate a Crawler and add to list
            bugs.push_back(new Crawler(id, x, y, direction, size));
        }
        else if (bug_type == "H") { // if it is Hopper, then read the Hopper fields
            getline(strStream, strTemp, DELIMITER);
            int hopLength = stoi(strTemp);

            // now, instantiate a Hopper and add to list
            bugs.push_back(new Hopper(id, x, y, direction, size, hopLength));
        }
        if (bug_type == "S") { // if it is Crawler, then read the Crawler fields
            // now, instantiate a Crawler and add to list
            bugs.push_back(new Scuttler(id, x, y, direction, size));
        }
    }
    catch (std::invalid_argument const &e) {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e) {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
}

list<Bug*> Board::inputFileStream(string fileName) { // code for taking file input from: https://github.com/logued/cpp-file-IO-text-file-demo
    list<Bug*> bugs;
    ifstream inFileStream(fileName); // open file as input file stream (from working directory)

    if ( inFileStream.good() )  // if file opened successfully, and not empty
    {
        string line;            // create a string object to store a line of text
        while ( getline(inFileStream, line) )   // read a line until false returned , getline() from <string> library
        {
            parseLine(line, bugs);  // pass the line of text to have it parsed
        }
        inFileStream.close();
    }
    else{
        cout << "Unable to open file, or file is empty.";
    }
    return bugs;
}

void Board::OutputFileStream(){ //cod for outputting to file from: https://github.com/logued/cpp-file-IO-text-file-demo
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    string date, time;
    date = to_string(now->tm_mday) + "-" + to_string((now->tm_mon + 1)) + "-" + to_string((now->tm_year + 1900));
    time = to_string(now->tm_hour) + "-" + to_string(now->tm_min);

    ofstream outFileStream("bugs_life_history_" + date + "_" + time + ".txt");

    if ( outFileStream )
    {
        for(Bug* bugP : bugs){
            outFileStream <<  bugP->historyToString() << endl;
        }
        outFileStream.close();
    }
    else
        cout << "Unable to open file" << endl;
}

Board::~Board() { cout << "~Board() destructor called.\n"; }
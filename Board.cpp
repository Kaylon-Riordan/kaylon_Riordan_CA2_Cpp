#include "Board.h"

Board::Board()
{
    this->bugs = inputFileStream("bugs.txt");
}

void parseLine(const string &strLine, list<Bug*> &bugs) {
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
    }
    catch (std::invalid_argument const &e) {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e) {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
}

list<Bug*> inputFileStream(string fileName) {
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
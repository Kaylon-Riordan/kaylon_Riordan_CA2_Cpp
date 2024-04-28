#include "Board.h"

Board::Board()
{
    this->bugs = inputFileStream("bugs.txt");
}

void Board::displayAllBugs() { //display all bugs in a formated table
    cout << "\nClass:\t\tID:\tPosition:\tDirection:\tSize:\t\tStatus:\t\tHop Length:" << endl;
    for(Bug* bugP : bugs){
        cout << bugP->toString() << endl;
    }
}

void Board::displayAllHistory() { //display all bugs IDs and the path they have taken, ending in their current status
    cout << "\nClass:\t\tID:\tPath:" << endl;
    for(Bug* bugP : bugs){
        cout << bugP->historyToString() << endl;
    }
}

void Board::displayBugByID(int id) { // display a single bugs details taking a user inputed ID
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

void Board::displayAllCells(){ // go through each cell on the bard and display its contents
    pair<int, int> cell; bool empty;
    for(int x = 0; x < 10; x++){ // use 2 for loops to go through every x and y position on the board
        for(int y = 0; y < 10; y++){
            empty = true;
            cell.first = x;
            cell.second = y; // fill a pair with the current x and y positions
            cout << "\n(" << x << "," << y << "):";
            for(Bug* bugP : bugs){
                if(bugP->getPosition() == cell){ // check every bug and display them on this row if they are in this cell
                    cout << " ," << bugP->getType() << " " << bugP->getId();
                    empty = false;
                }
            }
            if(empty){
                cout << " empty";
            }
        }
    }
}

void Board::movementPhase() { //call all the bugs movement methods then
    for(Bug* bugP : bugs){
        bugP->move();
    }
    fightPhase(); // check for bugs eating each other after all moves are finished
}

void Board::fightPhase() { // make bugs on same square fight after moving
    int biggest; int total; int winner;
    pair<int, int> cell; list<Bug*> inCell; list<Bug*> contenders; // initiate variables used in method
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            cell.first = x; cell.second = y;
            biggest = 0; total = 0; inCell.clear(); contenders.clear(); // reset variables every loop
            for(Bug* bugP : bugs){
                if(bugP->getPosition() == cell && bugP->getAlive()){
                    inCell.push_back(bugP); // create a list of all living bugs inside the current cell
                    total += bugP->getSize(); // keep track of the total size the winner will be after eating all other bugs in this cell
                    if(bugP->getSize() > biggest){ // if the current bug is bigger than the previous biggest, then clear the list of biggest bugs and added current bug to the list
                        biggest = bugP->getSize();
                        contenders.clear();
                        contenders.push_back(bugP);
                    }
                    else if(bugP->getSize() == biggest){ // if the current bug is tied with the biggest add him to the list of biggest bugs
                        contenders.push_back(bugP);
                    }
                }
            }
            if(contenders.size() > 0){ // go through the list of bugs tied for biggest and randomly choose a winner
                // source for getting random numbers: https://stackoverflow.com/questions/13896450/rand-returns-the-same-number-each-time-the-program-is-run
                srand(time(NULL));
                int win = rand() % contenders.size(); // generate a random number between 0 and number of contenders -1
                for(Bug* bugP : contenders){ // for each contender check if the counter has rached 0, if so they win and sizeis set tp tpta;, if not reduce the counter
                    if(win == 0){
                        winner = bugP-> getId();
                        bugP->setSize(total);
                    }
                    win--;
                }
            }
            for(Bug* bugP : inCell){ // for all bugs in the current cell kill them off, except the winner
                if(bugP->getSize() < total){
                    bugP->setEatenBy(winner);
                    bugP->setAlive(false);
                }
            }
        }
    }
}

void Board::runSimulation(){ //Code for running method every second from: https://stackoverflow.com/questions/10807681/loop-every-10-second
    int living =100;
    while(living > 1) // loop until one bug has one
    {
        living = 0;
        movementPhase(); // move and fight all bugs
        for(Bug* bugP : bugs){if(bugP->getAlive()){living++;}} // count living bugs
        displayAllBugs(); // display bugs
        Sleep(1000); //wait 1 second before going again (if many bugs turn, generating random numbers for direction lags the program and wait will be more than 1 second)
    }
    int winner;
    for(Bug* bugP : bugs){if(bugP->getAlive()){winner = bugP->getId();}}
    cout << "Winner is " << to_string(winner) << endl; // ding living bug and display them as winner
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
            getline(strStream, strTemp, DELIMITER);// get hop length variable
            int hopLength = stoi(strTemp);
            // now, instantiate a Hopper and add to list
            bugs.push_back(new Hopper(id, x, y, direction, size, hopLength));
        }
        if (bug_type == "S") { // if it is Scuttler, then read the Scuttler fields
            // now, instantiate a Scuttler and add to list
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
    time = to_string(now->tm_hour) + "-" + to_string(now->tm_min); // create strings for current date and time

    ofstream outFileStream("bugs_life_history_" + date + "_" + time + ".txt"); // create file name and attempt to create file

    if ( outFileStream )
    {
        for(Bug* bugP : bugs){ //if file is created successfully then write all bugs to the file
            outFileStream <<  bugP->historyToString() << endl;
        }
        outFileStream.close();
    }
    else
        cout << "Unable to open file" << endl;
}

void Board::Graphics(){// code for sfml window based on: https://github.com/delboy8080/SFML_Sample2/blob/master/main.cpp
    srand(time(NULL));
    bugs.push_back(new SuperBug(500,5,2,1,500)); // add the player super bug to the bug list, make him big enough to eat all other bugs
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!"); // crate a 1000p square window
    vector<sf::CircleShape> characters; // crate lists for bugs and grid squares
    vector<sf::RectangleShape> squares;
    for(int x = 0; x < 10; x ++)
    {
        for(int y=0; y<10; y++)
        {
            sf::RectangleShape cell(sf::Vector2f(100,100));
            cell.setPosition(x*100, y*100);
            cell.setOutlineThickness(5);
            cell.setOutlineColor(sf::Color::Black);
            squares.push_back(cell); // add a square with black outline to grid at current position
        }
    }

    while (window.isOpen()) // start game loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased) // read inputs from 4 arrow keys and face player bug in matching direction
            {                                        // if their way isn't blocked then move all bugs on the board
                if(event.key.code == sf::Keyboard::Up)
                {
                    for(Bug* bugP : bugs){
                        if(bugP->getType() == "SuperBug") {
                            bugP->setDirection(1);
                            if(!bugP->isWayBlocked()){
                                movementPhase();
                            }
                        }
                    }
                }
                if(event.key.code == sf::Keyboard::Down)
                {

                    for(Bug* bugP : bugs){
                        if(bugP->getType() == "SuperBug") {
                            bugP->setDirection(3);
                            if(!bugP->isWayBlocked()){
                                movementPhase();
                            }
                        }
                    }
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    for(Bug* bugP : bugs){
                        if(bugP->getType() == "SuperBug") {
                            bugP->setDirection(4);
                            if(!bugP->isWayBlocked()){
                                movementPhase();
                            }
                        }
                    }
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    for(Bug* bugP : bugs){
                        if(bugP->getType() == "SuperBug") {
                            bugP->setDirection(2);
                            if(!bugP->isWayBlocked()){
                                movementPhase();
                            }
                        }
                    }
                }
            }
        }
        characters.clear();// clear the list of bug circles from their old positions
        for(Bug* bugP : bugs){ // go through each bug, get and print a circle in the center of their cell if they are alive
            if(bugP->getAlive()){
                sf::CircleShape O(40);
                O.setPosition(bugP->getPosition().first*100+7.5,bugP->getPosition().second*100+7.5);
                if(bugP->getType() == "Crawler\t\t"){
                    O.setFillColor(sf::Color::Yellow);
                }
                else if(bugP->getType() == "Hopper\t\t"){
                    O.setFillColor(sf::Color::Green);
                }
                else if(bugP->getType() == "Scuttler\t"){
                    O.setFillColor(sf::Color::Red);
                }
                else {
                    O.setFillColor(sf::Color::Blue);
                }
                characters.push_back(O);
            }
        }
        window.clear(sf::Color::White);
        for(sf::RectangleShape sh:squares) // draw in all squares
        {
            window.draw(sh);
        }
        for(sf::CircleShape O:characters) // draw in all bug circles
        {
            window.draw(O);
        }
        window.display(); // print everything to window
    }
}

Board::~Board() { cout << "~Board() destructor called.\n"; }
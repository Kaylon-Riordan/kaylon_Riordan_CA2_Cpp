#include "Board.h"

int main() {
    Board board;
    int in = 0;

    while(in != 9){
        cout << "\n\nWhat function would you like to run:\n1. Display all Bugs." << endl;
        cin >> in; cout << "\n";

        switch(in) {
            case 1:
                board.displayAllBugs();
                break;
            case 9:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Unrecognised input" << endl;
                break;
        }
    }
}
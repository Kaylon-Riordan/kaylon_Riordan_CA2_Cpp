#include "Board.h"

int main() {
    Board board;
    int in = 0;

    while(in != 8){
        cout << "\n\nWhat function would you like to run?:\n1. Initialize Bug Board\n2. Display all Bugs"
                "\n3. Find a Bug\n4. Tap the Bug Board\n5. Display Life History of all Bugs"
                "\n6. Display all Cells listing their Bugs\n7. Run simulation\n8. Exit program\nInput:";
        cin >> in;

        switch(in) {
            case 1:
                board.setBugs(board.inputFileStream("bugs.txt"));
                break;
            case 2:
                board.displayAllBugs();
                break;
            case 3:
                int id;
                cout << "Input ID:";
                cin >> id;
                board.displayBugByID(id);
                break;
            case 4:
                board.moveAll();
                break;
            case 5:
                board.displayAllHistory();
                break;
            case 6:
                board.displayAllBugs();
                break;
            case 7:
                board.displayAllBugs();
                break;
            case 8:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Unrecognised input" << endl;
                break;
        }
    }
}
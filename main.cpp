#include "Board.h"
#include <SFML/Graphics.hpp>

int main() {
    Board board;
    int in = 0;

    while(in != 8){
        cout << "\n\nWhat function would you like to run?:\n1. Initialize Bug Board\n2. Display all Bugs"
                "\n3. Find a Bug\n4. Tap the Bug Board\n5. Display Life History of all Bugs"
                "\n6. Display all Cells listing their Bugs\n7. Run simulation\n8. Exit program"
                "\n9. Run SFML graphics\nInput:";
        cin >> in; // display options menu and take user input, then run matching method in board

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
                board.movementPhase();
                break;
            case 5:
                board.displayAllHistory();
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                board.runSimulation();
                break;
            case 8:
                board.OutputFileStream();
                break;
            case 9:
                board.Graphics();
            default:
                cout << "Unrecognised input" << endl;
                break;
        }
    }
}
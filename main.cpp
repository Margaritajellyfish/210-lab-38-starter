#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Insert a code\n";
    cout << "2. Delete a code\n";
    cout << "3. Search for a code\n";
    cout << "4. Display codes (In-Order)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");
    string code;

    
    if (inputFile) {
        while (inputFile >> code) {
            tree.insertNode(code);
        }
        inputFile.close();
    } else {
        cout << "Error opening file.\n";
    }

    int choice;
    string userInput;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter code to insert: ";
                cin >> userInput;
                tree.insertNode(userInput);
                cout << "Code inserted.\n";
                break;
            case 2:
                cout << "Enter code to delete: ";
                cin >> userInput;
                tree.remove(userInput);
                cout << "Code deleted (if it existed).\n";
                break;
            case 3:
                cout << "Enter code to search: ";
                cin >> userInput;
                if (tree.searchNode(userInput)) {
                    cout << "Code found.\n";
                } else {
                    cout << "Code not found.\n";
                }
                break;
            case 4:
                cout << "Codes in the tree (in-order):\n";
                tree.displayInOrder();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

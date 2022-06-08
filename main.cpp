#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

/**
 * @brief Main method which starts the whole program
 * 
 * @return int status of the program
 */
int main() {
    string command; //Command used to start the proper binary tree's method
    string treeType; //Type of tree
    string output_info; //Output information from binary tree's methods

    //Creating tree for each type
    Tree<int, TreeNode<int>>* treeInteger = new Tree<int, TreeNode<int>>();
    Tree<double, TreeNode<double>>* treeDouble = new Tree<double, TreeNode<double>>();
    Tree<string, TreeNode<string>>* treeString = new Tree<string, TreeNode<string>>();

    cout << "Enter type of tree (Integer | Double | String): ";
    cin >> treeType;

    while(true) {
        printf("Enter command (search | insert | delete | draw | end): ");
        cin >> command;

        if(treeType == "Integer") {
            int paramInteger; //Parameter given by user

            if(command == "search") {
                cout << "Enter parameter: ";
                cin >> paramInteger;

                output_info = treeInteger->search(paramInteger);
                cout << output_info << endl;
            } else if(command == "insert") {
                cout << "Enter parameter: ";
                cin >> paramInteger;

                treeInteger->insert(paramInteger);
            } else if(command == "delete") {
                cout << "Enter parameter: ";
                cin >> paramInteger;

                treeInteger->deleteNode(paramInteger);
            } else if(command == "draw") {
                treeInteger->draw();
            } else if(command == "end") {
                return 0;
            } else {
                cout << "Wrong type of command!\n";
            }

        } else if(treeType == "Double") {
            double paramDouble; //Parameter given by user

            if(command == "search") {
                cout << "Enter parameter: ";
                cin >> paramDouble;

                output_info = treeDouble->search(paramDouble);
                cout << output_info << endl;
            } else if(command == "insert") {
                cout << "Enter parameter: ";
                cin >> paramDouble;

                treeDouble->insert(paramDouble);
            } else if(command == "delete") {
                cout << "Enter parameter: ";
                cin >> paramDouble;

                treeDouble->deleteNode(paramDouble);
            } else if(command == "draw") {
                treeDouble->draw();
            } else if(command == "end") {
                return 0;
            } else {
                cout << "Wrong type of command!\n";
            }

        } else if(treeType == "String") { 
            string paramString; //Parameter given by user

            if(command == "search") {
                cout << "Enter parameter: ";
                cin >> paramString;

                output_info = treeString->search(paramString);
                cout << output_info << endl;
            } else if(command == "insert") {
                cout << ("Enter parameter: ");
                cin >> paramString;

                treeString->insert(paramString);
            } else if(command == "delete") {
                cout << "Enter parameter: ";
                cin >> paramString;

                treeString->deleteNode(paramString);
            } else if(command == "draw") {
                treeString->draw();
            } else if(command == "end") {
                return 0;
            } else {
                cout << "Wrong type of command!\n";
            }

        } else {
            cout << "Wrong type of tree!\n";
            return 1;
        }
    }

    return 0;
}

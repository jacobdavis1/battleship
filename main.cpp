#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include "OceanGrid.h"

using namespace std;

void printMenu();
void processCommand(string command, string arg1, string arg2);
void fireOnSpace(int rowId, char columnId);
void startNewGame();

OceanGrid grid(10, 10);
bool inGame = false;

int main()
{
    cout << "Welcome to Battleship." << endl;

    printMenu();

    while (true)
    {
        string command;
        string commandTokens[3];

        getline(cin, command);
        stringstream ss(command);
        for (int i = 0; i < 3; ++i)
        {
            if (ss.str() != "")
                getline(ss, commandTokens[i], ' ');
            else break;
        }

        processCommand(commandTokens[0], commandTokens[1], commandTokens[2]);
    }

    return 0;
}

void printMenu()
{
    cout << "Please select on of the following options." << endl;
    cout << "start - Start a new game." << endl;
    cout << "quit - Exit the application." << endl;
}

void processCommand(string command, string arg1, string arg2)
{
    if (command == "fire")
    {
        try
        {
            int row = stoi(arg1);
            char column = arg2[0];
            fireOnSpace(row, column);

            cout << "Fired!" << endl;
        }
        catch (exception e)
        {
            cout << "There was a problem with your command. Error: " << e.what() << endl;
        }

        grid.printGrid();
    }
    else if (command == "start")
    {
        startNewGame();
    }
    else
    {
        cout << "Command not recognized." << endl;
    }
}

void startNewGame()
{
    inGame = true;
    grid.resetBoard();

    cout << "Ocean generated! Use the command fire row column to reveal a cell and potentially hit a ship." << endl;
    grid.printGrid();
}

void fireOnSpace(int rowId, char columnId)
{
    bool valid = grid.fireOnSpace(rowId, columnId);
}

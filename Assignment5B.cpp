/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 5B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string maze[5][5] = {
            {"_", "N", "_", "N", "N"},
            {"_", "N", "_", "N", "_"},
            {"_", "_", "_", "N", "_"},
            {"N", "N", "_", "_", "W"},
            {"_", "_", "_", "N", "N"}
    };

    int startRow = 4, startCol = 0;
    maze[startRow][startCol] = "P";
    bool ended = false;
    while (ended != true) {
        // prints a map of the maze
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << maze[i][j] << ".";
            }
            cout << endl;
        }
        cout << "Which direction do you want to move? ";
        string direction;
        cin >> direction;
        int playerRow = startRow;
        int playerCol = startCol;
        // manage direction
        if (direction == "Left" || direction == "left") {
            playerCol--;
        }
        else if (direction == "Right" || direction == "right") {
            playerCol++;
        }
        else if (direction == "Up" || direction == "up") {
            playerRow--;
        }
        else if (direction == "Down" || direction == "down") {
            playerRow++;
        }
        else {
            cout << "That's not a valid direction!\n";
            continue;
        }
        //bounds check
        if (playerRow < 0 || playerRow > 4 || playerCol < 0 || playerCol > 4) {
            cout << "You can't move there - it's out of bounds!\n";
        }
        // wall check
        else if (maze[playerRow][playerCol] == "N") {
            cout << "You hit a wall - Game Over!\n";
            ended = true;
        }
        // win check
        else if (maze[playerRow][playerCol] == "W") {
            cout << "\nYou win!\n";
            ended = true;
        }
        //move P to the new spot and update old spot back to _
        else {
            maze[startRow][startCol] = "_";
            startRow = playerRow;
            startCol = playerCol;
            maze[startRow][startCol] = "P";
        }
    }
    return 0;
}


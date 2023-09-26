/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 2C
*/
#include <iostream>
using namespace std;

int main() {
    int xCoord, yCoord, boxWidth, boxHeight;
    int topLeft, bottomRight;
    cout << "X coordinate (bottom-left corner): ";
    cin >> xCoord;
    cout << "Y coordinate (bottom-left corner): ";
    cin >> yCoord;
    cout << "Hit box width: ";
    cin >> boxWidth;
    cout << "Hit box height: ";
    cin >> boxHeight;
    cout << "\n[Sprite Hit Box Coordinates]\n";
    topLeft = yCoord + boxHeight;
    bottomRight = xCoord + boxWidth;
    cout << "Bottom-Left: " << xCoord << ", " << yCoord;
    cout << "\nTop-Left: " << xCoord << ", " << topLeft;
    cout << "\nBottom-Right: " << bottomRight << ", " << yCoord;
    cout << "\nTop-Right: " << bottomRight << ", " << topLeft << endl;
    return 0;
}

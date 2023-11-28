/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 4B
*/
#include <iostream>
using namespace std;

int main() {
    int fontSize, fontWeight;
    cout << "[Plus Sign ASCII Art]" << endl;
    cout << "Font-size: ";
    cin >> fontSize;
    cout << "Font-weight: ";
    cin >> fontWeight;
    cout << "Drawing with text...\n";
    // calculate the final size
    int finalRows = (fontSize*2)+fontWeight;
    // row counter
    for (int row = 0; row < finalRows; row++) {
        // verts are directly connected to rows
        for (int vert = 0; vert < finalRows; vert++) {
            // puts the dashes in the middle
            if (row >= (finalRows-fontWeight)/2 && row < (finalRows+fontWeight)/2) {
                cout << "–";
            }
            // puts the verts in the middle
            else if (vert >= (finalRows-fontWeight)/2 && vert < (finalRows+fontWeight)/2) {
                cout << "|";
            }
            else {
                // spaces
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

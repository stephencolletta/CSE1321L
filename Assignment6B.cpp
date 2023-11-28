/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 6B
*/

#include <iostream>
#include <string>
using namespace std;

void printXPixMap(string** imagePix, string colorMap[], int width, int height){
    // presuming these do not actually need to be defined and are just so the .xpm file works if copied in
    cout << "#define image_format 1" << endl;
    cout << "#define image_width" << width << endl;
    cout << "#define image_height" << height << endl;
    cout << "#define image_ncolors" << 4 << endl;
    cout << "#define image_chars_per_pixel 1" << endl;
    cout << "static char *image_colors[] = {\n";
    // alternates between the letter and the hex
    for(int i=0; i<8; i+=2) {
        cout << "\"" << colorMap[i+1] << "\", " << "\"" << colorMap[i] << "\"," << endl;
    }
    cout << "};" << endl;
    cout << "static char *image_pixels[] = {\n";
    for(int i=0; i<height; i++) {
        cout << "\"";
        for(int j=0; j<width; j++) {
            cout << imagePix[i][j];
        }
        cout << "\"," << endl;
    }
    cout << "};" << endl;
}

bool checkIfValidColor(string colorMap[], string colorInput){
    for(int i = 1; i < 8; i+=2){
        if(colorMap[i] == colorInput){
            return true;
        }
    }
    return false;
}

void replaceColor(string** imagePix, int width, int height, string oldColor, string newColor){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(imagePix[i][j] == oldColor){
                imagePix[i][j] = newColor;
            }
        }
    }
}

int main() {
    string colorMap[8];
    int width, height, menuChoice;
    bool isRunning = true;
    // this could be a for loop
    cout << "Enter a hexadecimal color for color 1: ";
    cin >> colorMap[0];
    cout << "Enter a letter to represent this color: ";
    cin >> colorMap[1];
    cout << "Enter a hexadecimal color for color 2: ";
    cin >> colorMap[2];
    cout << "Enter a letter to represent this color: ";
    cin >> colorMap[3];
    cout << "Enter a hexadecimal color for color 3: ";
    cin >> colorMap[4];
    cout << "Enter a letter to represent this color: ";
    cin >> colorMap[5];
    cout << "Enter a hexadecimal color for color 4: ";
    cin >> colorMap[6];
    cout << "Enter a letter to represent this color: ";
    cin >> colorMap[7];
    cout << "\nEnter a width: ";
    cin >> width;
    cout << "Enter a height: ";
    cin >> height;

    //memory allocation , this is required to make the methods work
    string **pixels;
    pixels = new string*[height];
    for (int i = 0; i < height; i++) {
        pixels[i] = new string[width];
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            pixels[i][j] = colorMap[1];
        }
    }

    while(isRunning){
        cout << "\nOptions:\n";
        cout << "1) Set a color\n";
        cout << "2) Replace colors\n";
        cout << "3) Print X PixMap\n";
        cout << "4) Quit\n";
        cout << "Choice: ";
        cin >> menuChoice;
        if(menuChoice == 1){
            int rowInd, colInd;
            string colorInput;
            cout << "\nEnter a row index: ";
            cin >> rowInd;
            cout << "Enter a column index: ";
            cin >> colInd;
            cout << "Enter a color: ";
            cin >> colorInput;
            // feed colors in to method
            if(checkIfValidColor(colorMap, colorInput)){
                pixels[rowInd][colInd] = colorInput;
                cout << "Color updated!\n";
            }
            else{
                cout << "Invalid color.\n";
            }
        }
        else if(menuChoice == 2){
            string oldColor, newColor;
            cout << "Enter the color to replace: ";
            cin >> oldColor;
            cout << "Enter the new color: ";
            cin >> newColor;
            // feed colors to method and check for both
            if(checkIfValidColor(colorMap, newColor) && checkIfValidColor(colorMap, oldColor)){
                replaceColor(pixels, width, height, oldColor, newColor);
            }
            else{
                cout << "Color is not in the color map!\n";
            }
        }
        else if(menuChoice == 3){
        printXPixMap(pixels, colorMap, width, height);
        }
        else if(menuChoice == 4){
            cout << "\n[Closing...]";
            // delete allocated memory from above
            for (int i = 0; i < height; i++) {
                delete[] pixels[i];
            }
            delete[] pixels;
            isRunning = false;
        }
        else{
            cout << "\nInvalid menu choice.\n";
        }
    }
    return 0;
}
/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 6A
*/
#include <iostream>
using namespace std;

// simple nested loops to print - note the ** which is required to make this work
void printArray(float** array, int width, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << array[i][j] << ", ";
        }
        cout << endl;
    }
}

// same thing as above for the **, many inputs but it has to be done this way
bool updateRow(float** array, int width, int height, int rowInd, int colInd, int rowLen, float inVal){
    if(rowInd >= height || colInd >= width || (rowLen + colInd) > width){
        return false;
    }
    for(int i = colInd; i < (colInd + rowLen); i++){
        array[rowInd][i] = inVal;
    }
    return true;
}

int main() {
    int width, height, rowIndex, colIndex, length;
    float startVal, newVal;
    cout << "[Building Character]\n";
    cout << "Enter an array width: ";
    cin >> width;
    cout << "Enter an array height: ";
    cin >> height;
    cout << "Enter an initial value: ";
    cin >> startVal;
    cout << "\nCreating an array with " << height << " row(s) and " << width << " column(s)\n\n";

    // allocate memory for array
    float** array = new float*[height];
    for (int i = 0; i < height; i++) {
        array[i] = new float[width];
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            array[i][j] = startVal;
        }
    }
    printArray(array, width, height);

    cout << "\nMaking the first row negative\n\n";
    for (int j = 0; j < width; j++){
        array[0][j] = -startVal;
    }

    printArray(array, width, height);

    cout << "\nEnter a row index: ";
    cin >> rowIndex;
    cout << "Enter a column index: ";
    cin >> colIndex;
    cout << "Enter a value: ";
    cin >> newVal;
    cout << endl;

    // many inputs
    if(!updateRow(array, width, height, rowIndex, colIndex, 1, newVal)){
        cout << "Invalid information! Try again.\n";
    }

    printArray(array, width, height);

    for(int i=0; i<height; i++) {
        if(i % 2 == 0){
            updateRow(array, width, height, i, 0, width, 12.78);
        }
        else{
            updateRow(array, width, height, i, 0, width, 87.21);
        }
    }

    cout << "\nAlternating rows\n\n";
    printArray(array, width, height);

    while(true){
        cout << "\nEnter a row index: ";
        cin >> rowIndex;
        cout << "Enter a column index: ";
        cin >> colIndex;
        cout << "Enter a length: ";
        cin >> length;
        cout << "Enter a value: ";
        cin >> newVal;
        cout << endl;

        if(updateRow(array,width,height,rowIndex,colIndex,length,newVal)){
            break;
        }
        else{
            cout << "Invalid information! Try again.\n";
        }
    }

    printArray(array, width, height);

    cout << "\n[Finally done!]";

    // frees the memory allocated earlier
    for (int i = 0; i < height; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}


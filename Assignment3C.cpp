/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 3C
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int userChannels, userBPC;
    string imageFormat, TIFF, PNG;
    TIFF = "TIFF";
    PNG = "PNG";
    cout << "[Guess the Color Mode]" << endl;
    cout << "How many channels does your image have? ";
    cin >> userChannels;
    if (userChannels <= 2){
        cout << "It is a Grayscale image.";
    }
    else if (userChannels == 3){
        cout << "It is an RGB image.";
    }
    else if (userChannels == 5){
        cout << "It is a CMYK image.";
    }
    else if (userChannels == 4){
        cout << "What is its BPC value? ";
        cin >> userBPC;
        if (userBPC == 32){
            cout << "It is an RGB image.";
        }
        else if (userBPC == 8 || userBPC == 16){
            cout << "What image format is it? ";
            cin >> imageFormat;
            if (imageFormat == TIFF){
                cout << "It is a CMYK image.";
            }
            else if (imageFormat == PNG){
                cout << "It is an RGB image.";
            }
            else{
                cout << "This image's color mode can not be determined.";
            }
        }
    }
    else{
        cout << "This is invalid input. Please run the program again.";
    }
    return 0;
}

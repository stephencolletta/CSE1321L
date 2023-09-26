/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 2B
*/
#include <iostream>
using namespace std;

int main() {
    int secondsInput, secondsFinal, minutesFinal, hoursFinal;
    cout << "Time in seconds: ";
    cin >> secondsInput;
    cout << "Converting...\n";
    secondsFinal = secondsInput % 60;
    minutesFinal = (secondsInput/60) % 60;
    hoursFinal = (secondsInput/3600) % 60;
    cout << secondsInput << " seconds == " << hoursFinal << " hour(s), " << minutesFinal << " minute(s), and " << secondsFinal << " second(s).";
    return 0;
}

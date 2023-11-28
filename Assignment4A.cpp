/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 4A
*/
#include <iostream>
using namespace std;

int main() {
    double userSpeed, userDecel, distance, totalDistance;
    int userUpdate;
    cout << "[Stopping Time]\n";
    cout << "How fast are you going (miles/hour)? ";
    cin >> userSpeed;
    cout << "How quickly can you decelerate (miles)? ";
    cin >> userDecel;
    cout << "How often do you want to see updates (in seconds)? ";
    cin >> userUpdate;
    cout << "\nYou are going " << userSpeed << " MPH when you slam on the brakes!\n";
    int seconds = 1;
    while (userSpeed > 0){
        distance = userSpeed * 1.4666667;
        totalDistance += distance;
        userSpeed -= userDecel;
        if (seconds % userUpdate == 0){
            cout << "At " << seconds << " seconds, you have traveled " << totalDistance << " feet and are now moving at " << userSpeed << " MPH.\n";
        }
        seconds++;
    }
    seconds -= 1;
    cout << "\nYou took " << seconds << " seconds to stop and traveled " << totalDistance << " feet during that time!";
    return 0;
}

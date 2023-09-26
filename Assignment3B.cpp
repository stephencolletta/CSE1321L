/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 3B
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string Africa, Antarctica, Asia, Australia, Europe, NorthAmerica, SouthAmerica;
    int continentsValue;
    continentsValue = 0;
    cout << "[World Traveler Checklist]" << endl;
    cout << "Have you been to Africa? ";
    cin >> Africa;
    if (Africa == "Y" || Africa == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to Antarctica? ";
    cin >> Antarctica;
    if (Antarctica == "Y" || Antarctica == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to Asia? ";
    cin >> Asia;
    if (Asia == "Y" || Asia == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to Australia? ";
    cin >> Australia;
    if (Australia == "Y" || Australia == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to Europe? ";
    cin >> Europe;
    if (Europe == "Y" || Europe == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to North America? ";
    cin >> NorthAmerica;
    if (NorthAmerica == "Y" || NorthAmerica == "y"){
        continentsValue = continentsValue + 1;
    }
    cout << "Have you been to South America? ";
    cin >> SouthAmerica;
    if (SouthAmerica == "Y" || SouthAmerica == "y"){
        continentsValue = continentsValue + 1;
    }
    switch(continentsValue){
        case 0:
            cout << "You have visited " << continentsValue << " continents: How is that possible? Are you living in space?";
        break;
        case 1:
            cout << "You have visited " << continentsValue << " continent: That's a good start. Time to explore the world!";
        break;
        case 2:
            cout << "You have visited " << continentsValue << " continents: You've just started your journey to see the world.";
        break;
        case 3:
            cout << "You have visited " << continentsValue << " continents: You've just started your journey to see the world.";
        break;
        case 4:
            cout << "You have visited " << continentsValue << " continents: You're an experienced traveler now.";
        break;
        case 5:
            cout << "You have visited " << continentsValue << " continents: You're an experienced traveler now.";
        break;
        case 6:
            cout << "You have visited " << continentsValue << " continents: Wow, you've been almost everywhere!";
        break;
        case 7:
            cout << "You have visited " << continentsValue << " continents: You're a true world traveler!";
        break;
    }
    return 0;
}

/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 5A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "[Top 10 Friend's List]" << endl;
    string friendsList[10];
    int userChoice, indexReplacer;
    string nameInput;
    bool running = true;
    bool invalid;
    int count = 0;
    while(running != false){
            cout << "\nWhat would you like to do?\n";
            cout << "1) Enter a friend's name\n";
            cout << "2) Replace a friend's name\n";
            cout << "3) Display your friends list\n";
            cout << "4) Quit\n";
            cout << "Your choice: ";
            cin >> userChoice;
            invalid = false;
            switch(userChoice){
                // name insertion forced incrementally from 1-10
                case 1:
                    cout << "\nEnter a name: ";
                    cin >> nameInput;
                    // check list for presence of name
                    for(int check = 0; check < 10; check++){
                        if(friendsList[check] == nameInput){
                            cout << "Sorry, they're already on the list!\n";
                            invalid = true;
                            break;
                        }
                    }
                    // ensure entry cannot occur after list is full
                    if (count < 10 && invalid != true){
                        friendsList[count] = nameInput;
                        count++;
                    }
                    else if(count>9){
                        cout << "Sorry, your friends list is full!\n";
                    }
                    break;
                // replacer of names
                case 2:
                    cout << "Enter a name: ";
                    cin >> nameInput;
                    cout << "Enter an index: ";
                    cin >> indexReplacer;
                    // using count so you can't replace an empty spot
                    // in other words replace can only apply to filled spots
                    // it also prevents filling the list out of order
                    if(indexReplacer >= 0 && indexReplacer < count){
                        cout << nameInput << " has replaced " << friendsList[indexReplacer] << " on your friends list!\n";
                        friendsList[indexReplacer] = nameInput;
                    }
                    else{
                        cout << "Sorry, that's an invalid command!\n";
                    }
                    break;
                // print list
                case 3:
                    cout << "Friend's List: \n";
                    for(int var = 0; var < 10; var++){
                        cout << var+1 << ")  " << friendsList[var] << endl;
                    }
                    break;
                // exit program with message for courtesy
                case 4:
                    cout << "Exiting...\n";
                    running = false;
                    break;
                default:
                    cout << "Invalid command. Please try again.\n";
                    break;
            }
    }
    return 0;
}

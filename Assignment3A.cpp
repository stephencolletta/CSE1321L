/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 3A
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    //declarations
    string userIllness, hgpsCheck, bokterCheck, sailorCheck;
    cout << "[WebMD Checker]\n";
    cout << "What is your suspected illness? ";
    //getline used so bokter syndrome doesnt break it later
    getline(cin, userIllness);
    // nested ifs for hgps check
    if (userIllness == "HGPS") {
        cout << "Do you have brittle bones? " ;
        cin >> hgpsCheck;
        if (hgpsCheck == "Y" || hgpsCheck == "y") {
            cout << "It is possible that you have HGPS";
        }
        else if (hgpsCheck == "N" || hgpsCheck == "n") {
            cout << "It is not likely that you have HGPS";
        }
    }
    // the same thing but for bokter
    if (userIllness == "Bokter Syndrome"){
        cout << "Do you have a Vitamin C deficiency? ";
        cin >> bokterCheck;
        if (bokterCheck == "N" || bokterCheck == "n"){
            cout << "It is not likely that you have Bokter Syndrome";
        }
        //nested sailor checks following the bokter check
        else if (bokterCheck == "Y" || bokterCheck == "y"){
            cout << "Are you a sailor? ";
            cin >> sailorCheck;
            if (sailorCheck == "y" || sailorCheck == "Y"){
                cout << "It is possible that you have Bokter Syndrome";
            }
            else if (sailorCheck == "N" || sailorCheck == "n"){
                // on the assignment sample, this statement outputs without the word "that". seemed wrong so i didn't do it here
                cout << "It is not likely that you have Bokter Syndrome";
            }
        }
    }
    if (userIllness == "Lupus"){
        cout << "It is not likely that you have Lupus";
    }
    return 0;
}
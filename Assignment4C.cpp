#include <iostream>

using namespace std;

int main() {
    // create 3 and 5 gallon cans, respectively
    int can3 = 0;
    int can5 = 0;
    int choice;

    cout << "[4 Gallons of Water]\n";
    while (can5 != 4) {
        cout << "The 3 gallon can has " << can3 << " gallons of water. The 5 gallon can has " << can5 << " gallons of water.\n";
        cout << "\nOptions\n";
        cout << "1) Fill the 5-gallon can from the fountain\n";
        cout << "2) Fill the 3-gallon can from the fountain\n";
        cout << "3) Pour the 5-gallon can into the 3-gallon jug\n";
        cout << "4) Pour the 3-gallon can into the 5-gallon jug\n";
        cout << "5) Empty the 5-gallon can into the fountain\n";
        cout << "6) Empty the 3-gallon can into the fountain\n";
        cout << "What will you do? ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1: // Fill the 5-gallon can from the fountain
                can5 = 5;
                break;
            case 2: // Fill the 3-gallon can from the fountain
                can3 = 3;
                break;
            case 3: // Pour the 5-gallon can into the 3-gallon jug
                if (can3 < 3 && can5 > 0) {
                    int spaceIn3 = 3 - can3;
                    int pourAmount = min(spaceIn3, can5);
                    can3 += pourAmount;
                    can5 -= pourAmount;
                }
                break;
            case 4: // Pour the 3-gallon can into the 5-gallon jug
                if (can5 < 5 && can3 > 0) {
                    int spaceIn5 = 5 - can5;
                    int pourAmount = min(spaceIn5, can3);
                    can5 += pourAmount;
                    can3 -= pourAmount;
                }
                break;
            case 5: // Empty the 5-gallon can into the fountain
                can5 = 0;
                break;
            case 6: // Empty the 3-gallon can into the fountain
                can3 = 0;
                break;
            default:
                cout << "Your choice is invalid. Please enter a number from 1 to 6." << endl;
        }
    }
    cout << "You saved Bruce Willis and Samuel L. Jackson! You win!";
    return 0;
}

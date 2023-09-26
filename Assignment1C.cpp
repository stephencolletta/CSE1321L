#include <iostream>
#include <string>
using namespace std;

int main() {
    // declare suitable types for each variable
    string AnimalThird;
    float Subtotal;
    int Number;
    char Letter;
    cout << "[XKCD Passphrase Generator] \n" << endl;
    cout << "Enter your third favorite animal: ", cin >> AnimalThird;
    cout << "Enter the subtotal from your last take-out meal: ", cin >> Subtotal;
    cout << "Enter a whole number less than |32767|: ", cin >> Number;
    cout << "Enter a single letter: ", cin >> Letter;
    string NumberStr = Number
    string FirstPass = AnimalThird + " " << Subtotal << " " << Number << " " << Letter;
    cout << "Your passphrase is: " << FirstPass;
    cout << "Other variations are:\n" << Letter << " " << Number << " " << AnimalThird << " " << Subtotal << "\n";
    cout << Subtotal << " " << Letter << " " << AnimalThird << " " << Number << "\n";
    cout << Number << " " << AnimalThird << " " << Letter << " " << Subtotal << "\n";
    return 0;
}

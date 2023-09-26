#include <iostream>
using namespace std;

int main() {
    // declare each variable as a suitable type
    float brighten, red, green, blue, redDiff, greenDiff, blueDiff;
    // read user input for each variable in respective order
    cout << "Enter a red value (0-255): ", cin >> red;
    cout << "Enter a green value (0-255): ", cin >> green;
    cout << "Enter a blue value (0-255): ", cin >> blue;
    cout << "Percentage to brighten color: ", cin >> brighten;
    // acquire the difference between each given value and 255
    redDiff = 255 - red;
    greenDiff = 255 - green;
    blueDiff = 255 - blue;
    // multiply the difference by the percentage
    redDiff = redDiff*brighten;
    greenDiff = greenDiff*brighten;
    blueDiff = blueDiff*brighten;
    // add the product of the multiplication to the original RGB values
    redDiff = redDiff + red, greenDiff = greenDiff + green, blueDiff = blueDiff + blue;
    //multiplying brightness to display like in the sample output
    brighten = brighten*100;
    //output to user
    cout << "A " << brighten << ".0% brighter tint of RGB (" << red << ", " << green << ", " << blue;
    cout << ") is RGB (" << redDiff << ", " << greenDiff <<  ", " << blueDiff << ").";
    return 0;
}

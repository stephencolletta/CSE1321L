/*
Class: CSE 1321L
Section: E03
Term: Fall 2023
Instructor: Ilia Jahanshahi
Name: Stephen Colletta
Assignment#: 2A
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // declarations of octagon variables
    float octagonArea, octagonSide, octagonPerimeter, sqrtval;
    // declarations of cylinder variables
    float cylinderRadius, cylinderHeight, cylinderPerimeter, cylinderArea, cylinderDiameter;
    // sqrt 2 here so the bottom eq is cleaner
    sqrtval = sqrt(2);
    cout << "[Octagon Calculator]\n";
    cout << "Enter the length of one side: ";
    // get user input, only one is needed!
    cin >> octagonSide;
    // run calculations
    octagonPerimeter = octagonSide * 8;
    octagonArea = 2*(1+sqrtval)*(octagonSide*octagonSide);
    // output to user
    cout << "Octagon Perimeter = " << octagonPerimeter;
    cout << "\nOctagon Area = " << octagonArea;

    //BEGIN CYLINDER CALCULATOR
    cout << "\n\n[Cylinder Calculator]";
    // get user inputs
    cout << "\nEnter the radius: ";
    cin >> cylinderRadius;
    cout << "Enter the height: ";
    cin >> cylinderHeight;
    // run calculations, introduce cylinderDiameter so the equation for perimeter is cleaner
    cylinderDiameter = cylinderRadius*2;
    cylinderPerimeter = (2*cylinderDiameter)+(2*cylinderHeight);
    cylinderArea = 2*M_PI*cylinderRadius*cylinderHeight+2*M_PI*(cylinderRadius*cylinderRadius);
    cout << "Cylinder Perimeter = " << cylinderPerimeter;
    cout << "\nCylinder Area = " << cylinderArea << endl;
    return 0;
}

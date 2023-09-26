#include <iostream>
using namespace std;

int main() {
    float MealPrice, LocalTax, ServiceCharge, Subtotal, TotalTen, TotalTw, TenTip, TwFiveTip;
    // have user input the values needed
    cout << "[What to Tip]" << endl;
    cout << "Enter the total price of the meal: ", cin >> MealPrice;
    cout << "Enter the local tax rate: ", cin >> LocalTax;
    cout << "Enter the service charge: ", cin >> ServiceCharge;
    // run calculations for each variable
    LocalTax = LocalTax * MealPrice;
    Subtotal = MealPrice + ServiceCharge;
    TenTip = Subtotal * 0.10;
    TwFiveTip = Subtotal * 0.25;
    TotalTen = TenTip + Subtotal + LocalTax;
    TotalTw = TwFiveTip + Subtotal + LocalTax;
    // output variable results to user with clean format
    cout << "\nThe subtotal is $" << Subtotal << endl;
    cout << "\nA 10% tip would be $" << TenTip << endl;
    cout << "The total would be $" << TotalTen << endl;
    cout << "\nA 25% tip would be $" << TwFiveTip << endl;
    cout << "The total would be $" << TotalTw << endl;
    return 0;
}

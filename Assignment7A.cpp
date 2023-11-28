#include <iostream>
#include <string>
using namespace std;

class SVGRect{
private:
    // private attribs
    float width, height, strokeWidth, offsetX, offsetY;
    std::string fillColor, strokeColor;

public:
    // default constructor - is not used in this code ultimately
    SVGRect(){
        width = 1;
        height = 1;
        fillColor = "#0000FF";
        strokeColor = "#0F0F0F";
        strokeWidth = 1.0;
        offsetX = 0;
        offsetY = 0;
    }

    // overloaded constructor, fills in the default values for what is not inputed
    SVGRect(float inWidth, float inHeight, std::string inFill, std::string inStroke){
        width = inWidth;
        height = inHeight;
        fillColor = inFill;
        strokeColor = inStroke;
        strokeWidth = 1.0;
        offsetX = 0;
        offsetY = 0;
    }

    // sets dimensions, returns a bool, usual
    bool setDimensions(float firstIn, float secondIn){
        if(firstIn > 0 && secondIn > 0){
            width = firstIn;
            height = secondIn;
            return true;
        }
        else{
            return false;
        }
    }

    // sets offsets, like above but no bools, always accepts it
    void setOffsets(float firstFloat, float secondFloat){
        offsetX = firstFloat;
        offsetY = secondFloat;
    }

    // like setdimensions but with strings instead
    bool setFillStroke(std::string firstString, std::string secondString, float validCheck){
        if(validCheck > 0){
            fillColor = firstString;
            strokeColor = secondString;
            strokeWidth = validCheck;
            return true;
        }
        else{
            return false;
        }
    }

    // matches the xml format
    void printXML(){
        cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        cout << "<svg" << endl;
        cout << "   xmlns=\"http://www.w3.org/2000/svg\"" << endl;
        cout << "   xmlns:svg=\"http://www.w3.org/2000/svg\">" << endl;
        cout << "   <rect" << endl;
        cout << "     style=\"fill:" << fillColor << "; stroke:" << strokeColor << "; stroke-width:" << strokeWidth << "\"" << endl;
        cout << "     width=\"" << width << "\"" << endl;
        cout << "     height=\"" << height << "\"" << endl;
        cout << "     x=\"" << offsetX << "\"" << endl;
        cout << "     y=\"" << offsetY << "\" />" << endl;
        cout << "</svg>";
    }
};

class Assignment7A{
public:
    static void main(){
        float userWidth, userHeight;
        std::string userFill, userStroke;
        // for the while loop
        bool isRunning = true;

        cout << "[SVG Class]\n";
        cout << "Rectangle width: ";
        cin >> userWidth;
        cout << "Rectangle height: ";
        cin >> userHeight;
        cout << "Fill color: ";
        cin.ignore();
        getline(cin, userFill);
        cout << "Stroke color: ";
        cin.ignore();
        getline(cin, userStroke);

        //create the svg used for the entire rest of this assignment
        SVGRect firstSVG(userWidth, userHeight, userFill, userStroke);
        while(isRunning){
            int userInput;
            // for everything done within the while, weird names
            float widthInput, heightInput, strokewInput, xoffInput, yoffInput;
            std:;string fillInput, strokecInput;
            cout << "\nWhat would you like to do?";
            cout << "\n1) Change the Rectangle size\n";
            cout << "2) Update the Fill and Stroke settings\n";
            cout << "3) Move the Rectangle\n";
            cout << "4) Print valid XML\n";
            cout << "5) Quit\n";
            cout << "Option: ";
            cin >> userInput;
            switch(userInput){
                case 1:
                    cout << "\nEnter a width: ";
                    cin >> widthInput;
                    cout<< "Enter a height: ";
                    cin >> heightInput;
                    // call setdimensions method
                    if(firstSVG.setDimensions(widthInput, heightInput)){
                        cout << "\nRectangle updated!\n";
                    }
                    else{
                        cout << "\nInvalid input - rectangle not changed.\n";
                    }
                    break;
                case 2:
                    cout << "\nEnter a new fill color: ";
                    cin.ignore();
                    getline(cin, fillInput);
                    cout << "Enter a new stroke color: ";
                    cin.ignore();
                    getline(cin, strokecInput);
                    cout << "Enter a new stroke width: ";
                    cin >> strokewInput;
                    // call fillstroke method
                    if(firstSVG.setFillStroke(fillInput, strokecInput, strokewInput)){
                        cout << "Rectangle updated!\n";
                    }
                    else{
                        cout << "Invalid input - rectangle not changed.\n";
                    }
                    break;
                case 3:
                    cout << "\nEnter a new offset x: ";
                    cin >> xoffInput;
                    cout << "Enter a new offset y: ";
                    cin >> yoffInput;
                    // call setoffsets method - no if statement because all inputs for this are valid
                    firstSVG.setOffsets(xoffInput, yoffInput);
                    cout << "Rectangle updated!\n";
                    break;
                case 4:
                    // call printxml method
                    firstSVG.printXML();
                    break;
                case 5:
                    cout << "\nClosing!";
                    isRunning = false;
                    break;
                default:
                    // just in case
                    cout << "\nInvalid input. Please try again";
                    break;
            }
        }
    }
};

int main() {
    // i still wonder why
    Assignment7A::main();
    return 0;
}

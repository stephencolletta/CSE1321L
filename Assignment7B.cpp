#include <iostream>
#include <string>
using namespace std;

class Player{
private:
    int width, height, depth, xPos, yPos, zPos;
public:
    // constructor to fill the values
    Player(int inX, int inY, int inZ, int inWidth, int inHeight, int inDepth){
        xPos = inX;
        yPos = inY;
        zPos = inZ;
        width = inWidth;
        height = inHeight;
        depth = inDepth;
    }
    // getters
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
    int getDepth(){
        return depth;
    }
    int getxPos(){
        return xPos;
    }
    int getyPos(){
        return yPos;
    }
    int getzPos(){
        return zPos;
    }
    // setters
    void moveX(int xDelta){
        xPos += xDelta;
    }
    void moveY(int yDelta){
        yPos += yDelta;
    }
    void moveZ(int zDelta){
        zPos += zDelta;
    }
    // big ugly if statement for the check of collisions
    bool collideCheck(Player secondPlayer){
        if(xPos < (secondPlayer.getWidth() + secondPlayer.getxPos()) &&
        (width + xPos) > secondPlayer.getxPos() &&
        yPos < (secondPlayer.getHeight() + secondPlayer.getyPos()) &&
        (height+yPos) > secondPlayer.getyPos() &&
        zPos < (secondPlayer.getDepth() + secondPlayer.getzPos()) &&
        (depth + zPos) > secondPlayer.getzPos()){
            // removed the cout that's seen in the example because it interfered with the print order when using the method
            return true;
        }
        else{
            return false;
        }
    }
};

class Assignment7B{
public:
    static void main(){
        int userX, userY, userZ, userWidth, userHeight, userDepth;
        cout << "[3D Collision Tester]\n" << endl;
        cout << "Create Player 1" << endl;
        cout << "Enter X position: ";
        cin >> userX;
        cout << "Enter Y position: ";
        cin >> userY;
        cout << "Enter Z position: ";
        cin >> userZ;
        cout << "Enter Player Hitbox Width: ";
        cin >> userWidth;
        cout << "Enter Player Hitbox Height: ";
        cin >> userHeight;
        cout << "Enter Player Hitbox Depth: ";
        cin >> userDepth;
        // inputs for first
        Player firstPlayer(userX, userY, userZ, userWidth, userHeight, userDepth);

        cout << "\nCreate Player 2" << endl;
        cout << "Enter X position: ";
        cin >> userX;
        cout << "Enter Y position: ";
        cin >> userY;
        cout << "Enter Z position: ";
        cin >> userZ;
        cout << "Enter Player Hitbox Width: ";
        cin >> userWidth;
        cout << "Enter Player Hitbox Height: ";
        cin >> userHeight;
        cout << "Enter Player Hitbox Depth: ";
        cin >> userDepth;
        // inputs for second
        Player secondPlayer(userX, userY, userZ, userWidth, userHeight, userDepth);

        // for while
        bool isRunning = true;

        while(isRunning) {
            int moveChoice, moveDistance;
            string userDir;
            cout << "\nPlayer 1 is at (" << firstPlayer.getxPos() << "," << firstPlayer.getyPos() << ","
                 << firstPlayer.getzPos() << ")";
            cout << " and Player 2 is at (" << secondPlayer.getxPos() << "," << secondPlayer.getyPos() << ","
                 << secondPlayer.getzPos() << ")" << endl;

            cout << "Which one do you want to move?" << endl;
            cin >> moveChoice;
            cout << "Which direction should Player " << moveChoice << " move (up, down, left, right, forward, or backward)?" << endl;
            cin.ignore();
            getline(cin, userDir);
            cout << "How far should Player " << moveChoice << " move?" << endl;
            cin >> moveDistance;

            // for when choosing first player
            if(moveChoice == 1){
                // all of this is just processing the string input to the relevant method
                // it makes it negative for down/left/backward directions
                if(userDir == "Up" || userDir == "up"){
                    firstPlayer.moveY(moveDistance);
                }
                else if(userDir == "Down" || userDir == "down"){
                    moveDistance *= -1;
                    firstPlayer.moveY(moveDistance);
                }
                else if(userDir == "Right" || userDir == "right"){
                    firstPlayer.moveX(moveDistance);
                }
                else if(userDir == "Left" || userDir == "left"){
                    moveDistance *= -1;
                    firstPlayer.moveX(moveDistance);
                }
                else if(userDir == "Forward" || userDir == "forward"){
                    firstPlayer.moveZ(moveDistance);
                }
                else if(userDir == "Backward" || userDir == "backward"){
                    moveDistance *= -1;
                    firstPlayer.moveZ(moveDistance);
                }
            }
            // identical to the above, but for when selecting player 2 instead
            else if(moveChoice == 2){
                if(userDir == "Up" || userDir == "up"){
                    secondPlayer.moveY(moveDistance);
                }
                else if(userDir == "Down" || userDir == "down"){
                    moveDistance *= -1;
                    secondPlayer.moveY(moveDistance);
                }
                else if(userDir == "Right" || userDir == "right"){
                    secondPlayer.moveX(moveDistance);
                }
                else if(userDir == "Left" || userDir == "left"){
                    moveDistance *= -1;
                    secondPlayer.moveX(moveDistance);
                }
                else if(userDir == "Forward" || userDir == "forward"){
                    secondPlayer.moveZ(moveDistance);
                }
                else if(userDir == "Backward" || userDir == "backward"){
                    moveDistance *= -1;
                    secondPlayer.moveZ(moveDistance);
                }
            }

            // repeating the Player 1 print here as otherwise the program stops before it prints from the top
            if(firstPlayer.collideCheck(secondPlayer)){
                cout << "Player 1 is at (" << firstPlayer.getxPos() << "," << firstPlayer.getyPos() << ","
                     << firstPlayer.getzPos() << ")";
                cout << " and Player 2 is at (" << secondPlayer.getxPos() << "," << secondPlayer.getyPos() << ","
                     << secondPlayer.getzPos() << ")" << endl;
                cout << "They collided!";
                isRunning = false;
            }
        }
    }
};

int main() {
    // yep
    Assignment7B::main();
    return 0;
}

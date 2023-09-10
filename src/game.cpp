#include <iostream>
#include <string>
#include "desk.cpp"
#include "player.cpp"

using namespace std;

class Game
{
private:
    Desk desk;
    PlayerHuman p1;
    PlayerPC p2;

    bool checkWin(char symb) {
        for(int i = 0; i < 3; ++i) {
            if(desk.getSymbByPos(i,0) == symb && 
               desk.getSymbByPos(i,1) == symb && 
               desk.getSymbByPos(i,2) == symb) return true;
            if(desk.getSymbByPos(0,i) == symb && 
               desk.getSymbByPos(1,i) == symb && 
               desk.getSymbByPos(2,i) == symb) return true;
        }
        if(desk.getSymbByPos(0,0) == symb && 
           desk.getSymbByPos(1,1) == symb && 
           desk.getSymbByPos(2,2) == symb) return true;
        if(desk.getSymbByPos(0,2) == symb && 
           desk.getSymbByPos(1,1) == symb && 
           desk.getSymbByPos(2,0) == symb) return true;
        return false;
    }    
public:
    Game() {
        string name;
        char symb;
        cout << "Enter your name: ";
        cin >> name;
        while(true){
            cout << "Choose symbol (X or 0): ";
            cin >> symb;
            if(symb == 'X' || symb == '0') break;
            else cout << "Bad symbol!" << endl;
        }       

        p1.setName(name);
        p1.setSymb(symb);

        if(symb == '0') symb = 'X';
        else symb = '0';

        p2.setName("PC");
        p2.setSymb(symb);
    }

    void startGame() {
        int stepNum = 0;
        cout << "Game started!" << endl;
        desk.printDesk();

        while(true){
            pair<int,int> step;
            cout << "Step player " << p1.getName() << endl;
            while(true) {
                step = p1.whereToGo();
                step.first -= 1;
                step.second -= 1;
                if(desk.getSymbByPos(step.first, step.second) == ' ') {
                    desk.setSymbToPos(step.first, step.second, p1.getSymb());
                    stepNum++;
                    break;
                } else {
                    cout << "Position busy, try again!" << endl;
                }
            } 
            desk.printDesk();

            if(checkWin(p1.getSymb())) {
                cout << "Player: " << p1.getName() << " wins!";
                return;
            }

            if(stepNum == 9) {
                cout << "Draw!";
                return;
            }

            cout << "Step player " << p2.getName() << endl;
            while(true) {
                step = p2.whereToGo();
                if(desk.getSymbByPos(step.first, step.second) == ' ') {
                    desk.setSymbToPos(step.first, step.second, p2.getSymb());
                    stepNum++;
                    break;
                }
            }
            desk.printDesk();

            if(checkWin(p2.getSymb())) {
                cout << "Player: " << p2.getName() << " wins!";
                return;
            }

            if(stepNum == 9) {
                cout << "Draw!";
                return;
            } 
        }
    }
};

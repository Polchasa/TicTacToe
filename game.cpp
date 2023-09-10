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
        cout << "Введите свое имя: ";
        cin >> name;
        while(true){
            cout << "Введите символ которым хотите играть (X или 0): ";
            cin >> symb;
            if(symb == 'X' || symb == '0') break;
            else cout << "Неверный символ!" << endl;
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
        cout << "Игра началась!" << endl;
        desk.printDesk();

        while(true){
            pair<int,int> step;
            cout << "Ход игрока " << p1.getName() << endl;
            while(true) {
                step = p1.whereToGo();
                step.first -= 1;
                step.second -= 1;
                if(desk.getSymbByPos(step.first, step.second) == ' ') {
                    desk.setSymbToPos(step.first, step.second, p1.getSymb());
                    stepNum++;
                    break;
                } else {
                    cout << "Позиция занята, попробуйте еще раз!" << endl;
                }
            } 
            desk.printDesk();

            if(checkWin(p1.getSymb())) {
                cout << "Игрок: " << p1.getName() << " победил!";
                return;
            }

            if(stepNum == 9) {
                cout << "Ничья!";
                return;
            }

            cout << "Ход игрока " << p2.getName() << endl;
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
                cout << "Игрок: " << p2.getName() << " победил!";
                return;
            }

            if(stepNum == 9) {
                cout << "Ничья!";
                return;
            } 
        }
    }
};

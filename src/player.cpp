#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player {
private:
    string name;
    char gameSymb;
public:
    void setName(string n) { name = n; }
    void setSymb(char s)   { gameSymb = s; }
    string getName() { return name; }
    char getSymb() { return gameSymb; }
    virtual pair<int, int> whereToGo() { return make_pair(0,0); }
};

class PlayerHuman : public Player
{
public:
    pair<int, int> whereToGo() override {
        int x, y;
        while(true) {  
            cout << "Enter row and column numbers (1, 2, 3) for step: ";
            cin >> x >> y;
            if((x >= 1 && x <= 3) && (y >= 1 && y <= 3)) return {x, y};
            else cout << "Bad row/column, try again!" << endl;
        }
    }
};

class PlayerPC : public Player
{
private:
    random_device rdX;
    random_device rdY;
public:
    pair<int, int> whereToGo() override {        
        mt19937 genX(rdX());
        mt19937 genY(rdY());
        uniform_int_distribution<> dis(0, 2);
        int x, y;
        x = dis(genX);
        y = dis(genY);
        return {x, y};
    }
};



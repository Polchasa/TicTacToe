#include <iostream>
#include <vector>

using namespace std;

class Desk {
private:
    vector<vector<char>> crossZerosPos;
public:
    Desk();
    bool setSymbToPos(int line, int column, char symb);
    char getSymbByPos(int line, int column);
    void printDesk();
    ~Desk();
};

Desk::Desk(){
    for(int i = 0; i != 3; ++i) {
        vector<char> temp(3, ' ');
        crossZerosPos.push_back(temp);
    }
}

bool Desk::setSymbToPos(int line, int column, char symb) {
    if(getSymbByPos(line, column) != ' ') return false;
    crossZerosPos[line][column] = symb;
    return true;
}

char Desk::getSymbByPos(int line, int column) {
    return crossZerosPos[line][column];
}

void Desk::printDesk() {
    for(int i = 0; i != 5; ++i) {
        if(i % 2 > 0) {
            cout << "-----------";
        } else {
            for(int j = 0; j != 5; ++j) {
                if(j % 2 > 0) cout << "|";
                else {
                    cout << " " << getSymbByPos(i / 2, j / 2) << " ";
                }            
            }
        }
        cout << endl;
    }
    cout << endl;
}

Desk::~Desk()
{
}

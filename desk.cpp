#include <iostream>
#include <vector>

using namespace std;

class desk
{
private:
    vector<vector<char>> crossZerosPos;
public:
    desk();
    bool setSymbToPos(int line, int column, char symb);
    char getSymbByPos(int line, int column);
    void printDesk();
    ~desk();
};

desk::desk(){
    for(int i = 0; i != 3; ++i) {
        vector<char> temp(3, ' ');
        crossZerosPos.push_back(temp);
    }
}

bool desk::setSymbToPos(int line, int column, char symb) {
    if(getSymbByPos(line, column) != ' ') return false;
    crossZerosPos[line][column] = symb;
    return true;
}

char desk::getSymbByPos(int line, int column) {
    return crossZerosPos[line][column];
}

void desk::printDesk() {
    for(int i = 0; i != 5; ++i) {
        if(i % 2 > 0) {
            cout << "———————————";
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
}

desk::~desk()
{
}

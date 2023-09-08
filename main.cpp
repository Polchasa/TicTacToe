#include <iostream>
#include "desk.cpp"

using namespace std;

int main() { 
    desk de;
    for(int i = 0; i != 3; ++i) {
        for(int j = 0; j != 3; ++j) {
            de.setSymbToPos(i, j, 'X');
        }
    }
    de.printDesk();
}
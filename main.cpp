#include <iostream>
#include <clocale>
#include "game.cpp"

using namespace std;

int main() { 
    setlocale(LC_ALL,"Russian");
    Game game;
    game.startGame();
    return 0;
}
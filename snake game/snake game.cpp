#include <iostream>
#include <conio.h>
#include <windows.h>
#include "classes.h"

using namespace std;

int main() {
    Game game;
    Snake snake;
    while (!snake.getGameOver()) {
        snake.draw();
        snake.movement();
        snake.tailMovement();
        Sleep(150 - game.getSpeed());
    }

    cout << "You lose! The head touched the tail. Your score: " << snake.getScore() << endl;
    return 0;
}
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "classes.h"

using namespace std;


Snake::Snake() : gameOver(0), nTail(0), x(width / 2), y(height / 2), dir(STOP), grid(width, height) {
    gameOver = false;
    fruitX = rand() % width;
    fruitY = rand() % height;
    tailX = new int[100];
    tailY = new int[100];
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}
Snake::~Snake() {
    delete[] tailX;
    delete[] tailY;
}

bool Snake::getGameOver() {
    return gameOver;
}

void Snake::setColor(int color) {
    SetConsoleTextAttribute(console, color);
}

void Snake::draw() {
    system("CLS");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x) {
                setColor(10); // Green color for the snake head
                cout << "O";
                setColor(7); // Reset to default color
            }
            else if (i == fruitY && j == fruitX) {
                setColor(12); // Red color for the fruit
                cout << "*";
                setColor(7); // Reset to default color
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        setColor(10); // Green color for the snake body
                        cout << "o";
                        setColor(7); // Reset to default color
                        print = true;
                        break;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Snake::movement() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'A':
        case 'a':
        case (char)27:
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'S':
        case 's':
        case (char)25:
            if (dir != UP)
                dir = DOWN;
            break;
        case 'W':
        case 'w':
        case (char)24:
            if (dir != DOWN)
                dir = UP;
            break;
        case 'D':
        case 'd':
        case (char)26:
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'X':
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Snake::tailMovement() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (dir == LEFT) {
        x--;
    }
    else if (dir == RIGHT) {
        x++;
    }
    else if (dir == UP) {
        y--;
    }
    else if (dir == DOWN) {
        y++;
    }

    if (x >= width) x = 0;
    if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (x == tailX[i] && y == tailY[i]) {
            gameOver = true;
        }

    if (x == fruitX && y == fruitY) {
        score += 1;
        if (score % 10 == 0)
            speed += 20;
        nTail++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}


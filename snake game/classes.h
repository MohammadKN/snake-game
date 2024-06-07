
template<typename T>
class Grid {
private:
    T** grid;
    int width, height;
public:
    Grid(int w, int h) : width(w), height(h) {
        grid = new T * [height];
        for (int i = 0; i < height; ++i) {
            grid[i] = new T[width];
        }
    }

    ~Grid() {
        for (int i = 0; i < height; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    T& at(int x, int y) {
        return grid[y][x];
    }

    void clear() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                grid[i][j] = T();
            }
        }
    }
};

class Game {
protected:
    const int width = 20;
    const int height = 20;
    int score, speed;
public:
    Game() : score(0), speed(0) {};
    int getScore() {
        return score;
    }
    int getSpeed() {
        return speed;
    }
};

enum Direction { STOP = 0, RIGHT, LEFT, DOWN, UP };

class Snake : public Game {
private:
    bool gameOver;
    int x, y, fruitX, fruitY;
    Grid<char> grid;
    int* tailX;
    int* tailY;
    int nTail;
    Direction dir;
    HANDLE console;

public:
    Snake();
    ~Snake();
    bool getGameOver();
    void setColor(int color);
    void draw();
    void movement();
    void tailMovement();
};


#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Game.h"

const int s = 25;

using namespace std;
enum direction{up,down,left,right};

struct Point {
	int x;
	int y;
	int index;
};


class Snake : public Game
{
private:
	direction dir;
	int length;
	Point points[5];
	char body;
public:
	Snake();

	void display();
};



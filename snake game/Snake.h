#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>


using namespace std;

struct Point {
	int x;
	int y;
	int index;

};


class Game {
protected:
	int size;
	Point map[20][20];
	int score;
};
class Snake
{
protected:
	enum direction{up,down,left,right};
	direction dir;
	int length;
	Point points[5];
	string name;
public:
	


	Snake(int length, string name)
		: length(length), name(name)
	{

	}
};


class Coin {
public:
	int x;
	int y;



	Coin(){
		x = rand()%100;
		y = rand()%100;
		cout << x << " " << y;
	}
};

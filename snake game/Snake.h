#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Game.h"
#include<vector>

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
	char headS, bodyS;
	Point head;
	vector<Point> body;
	enum direction{up,down,left,right};
	direction dir;
	int length;
public:
	Snake(int x = 5, int y = 5) : headS('@'), bodyS('o'), dir(right), length(1) {
		Point Head(x + 1, y + 1);
		body.push_back(Head);

		head = body[0];
	
	};
	int get_head_x() {
		return head.x;
	};

	int get_head_y() {
		return head.y;
	};
	char get_headS() {
		return headS;
	};

	char get_bodyS() {
		return bodyS;
	};

	void get_movement() {
		if (GetAsyncKeyState(VK_up) && dir != down)
			dir = up;
		else if (GetAsyncKeyState(VK_down) && dir != up)
			dir = up;
		else if (GetAsyncKeyState(VK_left) && dir != right)
			dir = left;
		else if (GetAsyncKeyState(VK_right) && dir != left)
			dir = right;
	};
	void move() {
		position head_p(0, 0);
		if (dir == up)
			head_p.y = +1;
		else if (dir == down)
			head_p.y =1 ;
		else if (dir == right)
			head_p.x = +1;
		else if (dir == left)
			head_p.x =1 ;

		Point nhead(0, 0);
		nhead.x = body[0].x + head_p.x;
		nhead.y = body[0].y + head_p.y;

		for (int i = length + 1; i > 0; i++)
			body[i] = body[i + 1];
		head = new_p;
		body[0] = head;



	Snake();

	void display();
};



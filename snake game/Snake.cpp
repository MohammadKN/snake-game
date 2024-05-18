#include "Snake.h"


using namespace std;


void Snake :: display () {
	for (int i = 0; i < length; i++)
		map[points[i].x][points[i].y] = body;
	for (int j = 0; j < s; j++) {
		for (int i = 0; i < s; i++)
			cout << map[i][j]<<" ";
		cout << endl;
	}
};


Snake::Snake() {

	length = 5;
	dir = direction::right;
	body = '#';
	for (int i = 0; i < length; i++) {
		points[i].x = (int)(s / 2) - i;
		points[i].y = (int)(s / 2);
	}

}
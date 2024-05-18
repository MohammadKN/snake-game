#pragma once
#include "Snake.h"

class Game {
protected:
	char map[s][s];
	int score;
	char bg;
	Game() {
		score = 0;
		bg = '.';
		for (int j = 0; j < s; j++) {
			for (int i = 0; i < s; i++)
				map[i][j] = bg;
		}
	}
};

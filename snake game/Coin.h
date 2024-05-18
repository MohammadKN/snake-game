#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class Coin {
public:
	int x;
	int y;



	Coin() {
		x = rand() % 100;
		y = rand() % 100;
		cout << x << " " << y;
	}
};

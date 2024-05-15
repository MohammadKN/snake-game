#include <iostream>
#include <cstdlib> 
#include <time.h>
#include "Snake.h"

using namespace std;



int main()
{
	int x = rand() % 100;
	int y = rand() % 100;
	srand(time(0));

	Snake snake;
	snake.display();

}

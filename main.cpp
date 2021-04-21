#include <iostream>
#include <thread>

#include "Game.h"

/*

TODO: create classes

 
 */

int d20(int num_rolled);

int main()
{
	srand(time(NULL));
	
	Game die;
	
	std::cout << "Hello World" << std::endl;


	
	return 0;
}

int d20(int num_rolled)
{
	int result = rand() % 20 * num_rolled;
	
	return result;
}
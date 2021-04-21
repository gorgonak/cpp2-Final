#include <iostream>
#include <thread>
#include <ctime>


#include "Character.h"
#include "Game.h"

/*

TODO: create classes
TODO: create functions for getting name, race, and class.
TODO: add random switch case for race and class.
 
 */

void greeting();

int main()
{
	std::srand(time(nullptr));

	Character newchar;
	
	greeting();

	newchar.get_name();
	newchar.get_race();
	newchar.get_class();
	
	Game::char_display(&newchar.name, &newchar.race, &newchar.class_name);

	Character::get_stats();
	
	return 0;
}

void greeting()
{
	std::cout << "\n\n* Hello and Welcome to the D&D Character Generator. *\n" << std::endl;
}


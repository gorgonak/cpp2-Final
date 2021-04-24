#include <ctime>

#include "Character.h"
#include "File.h"
#include "Game.h"
#include "test.h"

/*

TODO: create classes
TODO: create functions for getting name, race, and class.
TODO: add random switch case for race and class.
 
 */

int main()
{
	std::srand(time(nullptr));

	Character newchar;
	newchar.name = "potatocannon";
	
	Game::greeting();

	newchar.get_name();
	newchar.get_race();
	newchar.get_class(); 
	newchar.set_stats();
	newchar.set_health();
	
	const auto health = newchar.get_health();
	
	system("pause");

	Game::char_display(&newchar.name, &newchar.race, &newchar.class_name,
		&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);


	File::char_display(&newchar.name, &newchar.race, &newchar.class_name,
		&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);
	
	
	return 0;
}
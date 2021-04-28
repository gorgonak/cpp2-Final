#include <ctime>

#include "Character.h"
#include "File.h"
#include "Game.h"
// #include "test.h" used to test functions and debug

int main()
{
	std::srand(time(nullptr));  // random seed for all my randomization features
	auto loop = false;  // loop for multiple character creation opportunities
	
	Game::greeting(); // greeting the user
	
	while (!loop) {
	
		Character newchar;  // creating an object from Character class

		newchar.get_name();  // running my class functions to get info
		newchar.get_race();
		newchar.get_class();
		newchar.set_stats();
		newchar.set_health();

		const auto health = newchar.get_health(); // converting my private member variable into a usable variable

		Game::char_display(&newchar.name, &newchar.race, &newchar.class_name,
			&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);  // displaying all the character info

		File::save_char(&newchar.name, &newchar.race, &newchar.class_name,
			&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);  // giving user the option to save all the character info into a .txt

		loop = Game::repeat(loop);  // giving the user the option to make another character

	}
	
	return 0;
}


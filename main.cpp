#include <ctime>

#include "Character.h"
#include "File.h"
#include "Game.h"
// #include "test.h" used to test functions and debug

int main()
{
	std::srand(time(nullptr));
	auto loop = false;
	
	Game::greeting();
	
	while (!loop) {
	
		Character newchar;  // creating an object from Character class

		newchar.get_name();
		newchar.get_race();
		newchar.get_class();
		newchar.set_stats();
		newchar.set_health();

		const auto health = newchar.get_health();

		Game::char_display(&newchar.name, &newchar.race, &newchar.class_name,
			&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);

		File::save_char(&newchar.name, &newchar.race, &newchar.class_name,
			&newchar.str, &newchar.dex, &newchar.con, &newchar.ine, &newchar.wis, &newchar.cha, health);

		loop = Game::repeat(loop);

	}
	
	return 0;
}


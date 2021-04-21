#include "Game.h"

int Game::die(int pip_num, int num_rolled)
{
	auto const result = rand() % pip_num + 1 * num_rolled;

	return result;
}

void Game::char_display(const std::string *name, const std::string *race, const std::string *class_name)
{
	system("CLS");
	std::cout << "\n\nCharacter Name: " << *name << "\nRace: " << *race << "\nClass: " << *class_name << std::endl;
}

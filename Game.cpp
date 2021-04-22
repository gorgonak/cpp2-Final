#include "Game.h"

int Game::die(int pip_num, int num_rolled)
{
	auto const result = rand() % pip_num + 1 * num_rolled;

	return result;
}

void Game::char_display(const std::string *name, const std::string *race, const std::string *class_name,
	const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha)
{
	system("CLS");
	std::cout << "\n\n Character Name: " << *name << "\n Race: " << *race << "\n Class: " << *class_name << std::endl;

	std::cout << " STR: " << *str << std::endl;
	std::cout << " DEX: " << *dex << std::endl;
	std::cout << " CON: " << *con << std::endl;
	std::cout << " INT: " << *ine << std::endl;
	std::cout << " WIS: " << *wis << std::endl;
	std::cout << " CHA: " << *cha << std::endl;

}

#include "Game.h"

void Game::greeting()
{
	std::cout << "\n\n* Hello and Welcome to the D&D Character Generator. * \n\n ";
	system("pause");
}

int Game::die(const int pip_num, const int num_rolled)
{
	auto const result = rand() % pip_num + 1 * num_rolled;

	return result;
}

void Game::char_display(const std::string* name, const std::string* race, const std::string* class_name,
	const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health)
{
	system("CLS");
	
	std::cout << "\n\n\n Name: " << *name << "\n Health: " << health <<
		"\n Race: " << *race << "\n Class: " << *class_name << "\n" << std::endl;

	if (*race == "ELF")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex + 2 << " [" << *dex << " + 2] " << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << std::endl;
	}
	else if (*race == "DWARF")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con + 2 << " [" << *con << " + 2] " << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << std::endl;
	}
	else if (*race == "TIEFLING")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine + 1 << " [" << *ine << " + 1] " << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha + 2 << " [" << *cha << " + 2] " << std::endl;
	}
	else if (*race == "GNOME")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine + 2 << " [" << *ine << " + 2] " << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << std::endl;
	}
	else if (*race == "DRAGONBORN")
	{
		std::cout << " STR: " << *str + 2 << " [" << *str << " + 2] " << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha + 1 << " [" << *cha << " + 1] " << std::endl;
	}
	else if (*race == "HALFLING")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex + 2 << " [" << *dex << " + 2] " << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << std::endl;
	}
	else if (*race == "HALF-ELF")
	{
		std::cout << " STR: " << *str << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha + 2 << " [" << *cha << " + 2] " << std::endl;
	}
	else if (*race == "HALF-ORC")
	{
		std::cout << " STR: " << *str + 2 << " [" << *str << " + 2] " << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con + 1 << " [" << *con << " + 1] " << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << std::endl;
	}
	else if (*race == "HUMAN")
	{
		std::cout << " STR: " << *str + 1 << " [" << *str << " + 1] " << std::endl;
		std::cout << " DEX: " << *dex + 1 << " [" << *dex << " + 1] " << std::endl;
		std::cout << " CON: " << *con + 1 << " [" << *con << " + 1] " << std::endl;
		std::cout << " INT: " << *ine + 1 << " [" << *ine << " + 1] " << std::endl;
		std::cout << " WIS: " << *wis + 1 << " [" << *wis << " + 1] " << std::endl;
		std::cout << " CHA: " << *cha + 1 << " [" << *cha << " + 1] " << std::endl;
	}
}

void Game::check_value(std::string arr[], const std::string& input)
{
	auto loop = false;
	auto correct = false;

	while (!loop) {
		system("CLS");

		for (auto i = 0; i < 5; i++) {
			if (input == arr[i])
			{
				std::cout << "You chose: " << input << std::endl;
				correct = true;
				loop = true;
			}
		}

		if (!correct)
		{
			std::cout << input << " was an Invalid Response, Try Again";
		}
	}
}

bool Game::repeat(bool loop)
{
	char user_choice;
	
	std::cout << "\n Would you like to make another character? [ Y / N ] \n ";
	std::cin >> user_choice;

	switch (user_choice)
	{

	case 'y':
	case 'Y':
		loop = false;
		break;

	default:
		
		system("CLS");
		std::cout << "\n\n\n Have a wonderful adventure! \n\n ";
		system("pause");
		loop = true;

	}

	clr_input();
	
	return loop;
}

void Game::clr_input()
{

	std::cin.clear(); // clear failed/error states of the stream if they are set
	if (std::cin.rdbuf()->in_avail()) // if there are any characters in the input buffer
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // throw them away
	}
	
}
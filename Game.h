#pragma once
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>

class Game
{
	
public:

	std::string race_list[9] = { "ELF", "DWARF", "TIEFLING",
								"GNOME", "DRAGONBORN", "HALFLING",
								"HALF-ELF", "HALF-ORC", "HUMAN" };
	
	std::string class_list[12] = { "BARBARIAN", "BARD", "CLERIC",
								"DRUID", "FIGHTER", "MONK",
								"PALADIN", "RANGER", "ROGUE",
								"SORCERER", "WARLOCK", "WIZARD" };

	static void greeting();	
	static int die(const int pip_num, const int num_rolled);
	
	static void char_display(const std::string* name, const std::string* race, const std::string* class_name,
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);

	static void check_value(std::string arr[], const std::string input);

private:
	
	
};


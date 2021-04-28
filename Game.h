#pragma once
#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>

class Game
{
	
public:

	// 2D Array (list) of possible races the user can choose from
	std::string race_list[9] = { "ELF", "DWARF", "TIEFLING",
								"GNOME", "DRAGONBORN", "HALFLING",
								"HALF-ELF", "HALF-ORC", "HUMAN" };

	// 2d Array (list) of possible classes the user can choose from
	std::string class_list[12] = { "BARBARIAN", "BARD", "CLERIC",
								"DRUID", "FIGHTER", "MONK",
								"PALADIN", "RANGER", "ROGUE",
								"SORCERER", "WARLOCK", "WIZARD" };

	static void greeting();

	// this function is made to be a random number generator based off die(dice) rolls.
	// you enter how many numbers to be on the die and then how many total die you want rolled.
	static int die(const int pip_num, const int num_rolled);

	// displays everything we have collected from the user to display one last time in one last place.
	static void char_display(const std::string* name, const std::string* race, const std::string* class_name,
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);

	// used to check against the elements in an array for validation
	static void check_value(std::string arr[], const std::string& input);

	// repeat the program based off user choice
	static bool repeat(bool loop);

	// used to clear the buffer of getline or cin before a new loop through the program
	static void clr_input();
	
private:

	// nothing private here 
	
};


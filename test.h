#pragma once
#include "Game.h"

#include <iostream>
#include <random>

// this entire header is just for testing various functions before implementing them into my program
// will be removed when finished and ready for deployment

int shuffle_array()
{
	int arr[6] = { 18, 14, 10, 8, 15, 11 };

	std::sort(arr, arr + 6);

	std::cout << "SORTED: ";

	for (int i : arr)
	{
		std::cout << i << " ";
	}

	unsigned const seed = 0;
	std::shuffle(arr, arr + 5, std::default_random_engine(seed));
	
	std::cout << "\nUNSORTED: ";

	for (int i : arr)
	{
		std::cout << i << " ";
	}

	return 0;
}

void check_val(int)
{
	int arr[4] = { 1, 2, 3, 4 };
	auto user_input = 0;
	bool loop = false;

	while (!loop) {

		std::cout << "\n Please enter a number between 1-4" << std::endl;
		std::cin >> user_input;
		system("CLS");

		for (int i = 0; i < 4; i++) {
			
			if (user_input == arr[i])
			{
				std::cout << "CORRECT " << user_input << " is between 1-4." << std::endl;
				loop = true;
			}
		}

		std::cout << "Invalid Response, Try Again";
	}
}

void switch_char(const std::string* name, const std::string* race, const std::string* class_name,
	const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, std::string* race_list)
{
	if (*race == "DRAGONBORN")
	{
		std::cout << " STR: " << *str << " [+2] " << std::endl;
		std::cout << " DEX: " << *dex << std::endl;
		std::cout << " CON: " << *con << std::endl;
		std::cout << " INT: " << *ine << std::endl;
		std::cout << " WIS: " << *wis << std::endl;
		std::cout << " CHA: " << *cha << " [+1] " << std::endl;
	}
}

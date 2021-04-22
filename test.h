#pragma once

#include <iostream>
#include <random>

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

#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class Game
{
	
public:
	static int die(int pip_num, int num_rolled);

	static void char_display(const std::string *name, const std::string *race, const std::string *class_name);

private:
	
};


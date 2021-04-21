#pragma once
#include "Game.h"

class Character :
	public Game
{
public:

	std::string name;
	std::string race;
	std::string class_name;

	void get_name();
	void get_race();
	void get_class();
	
	static int get_value();
	static int get_stats();
	
private:
	
};


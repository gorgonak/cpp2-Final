#pragma once
#include "Game.h"

class Character :
	public Game
{
public:

	std::string name;
	std::string race;
	std::string class_name;

	int str = 0;
	int dex = 0;
	int con = 0;
	int ine = 0;
	int wis = 0;
	int cha = 0;
	
	void get_name();
	void get_race();
	void get_class();
	void set_stats();
	void reroll_stat();
	void set_health();
	int get_health() const;
	
	static int get_value();
	static int* stat_gen();

	static void char_display();
	
private:

	int char_health = 0;
};


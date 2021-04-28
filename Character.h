#pragma once
#include "Game.h"

class Character :
	public Game
{
public:

	// initializing / creating the members of my Character class to be used
	// in the following methods
	
	std::string name;
	std::string race;
	std::string class_name;

	int str = 0;
	int dex = 0;
	int con = 0;
	int ine = 0;
	int wis = 0;
	int cha = 0;
	
	void get_name();  // gets name
	void get_race();  // gets race
	void get_class();  // gets class
	void set_stats();  // takes my generated stats and applies them to my stats
	void reroll_stat();  // gives user option to reroll one ability score
	void set_health();  // sets the character's health based off the class and other modifiers.
	int get_health() const;  // getter for the private member char_health
	
	static int get_value(); // gets the results from the Game::die function and puts them in an array then sorts and un sorts them for my needs.
	static int* stat_gen();  // generates the stats based off my algorithm using the get_value function

	static void char_display();
	
private:

	int char_health = 0;
};


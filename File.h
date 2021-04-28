#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Character.h"
class File :
	public Character
{
public:
	static void write_file(const std::string& character_name, std::string text);
	// static int read_file(std::string character_name); // not being used yet.. TODO: use read_file to check if there is a character already existing with the same name

	// using the same char_display from Game to grab all the information to be printed into a save file .txt
	static void char_display(const std::string* name, const std::string* race, const std::string* class_name, 
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);
	
	// asks the user if they want to save or not, if yes it wrties to a .txt file
	static void save_char(const std::string* name, const std::string* race, const std::string* class_name,
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);
	
private:
};


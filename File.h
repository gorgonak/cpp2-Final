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
	static int read_file(std::string character_name);

	static void char_display(const std::string* name, const std::string* race, const std::string* class_name, 
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);

	static void save_char(const std::string* name, const std::string* race, const std::string* class_name,
		const int* str, const int* dex, const int* con, const int* ine, const int* wis, const int* cha, const int health);
	
private:
};


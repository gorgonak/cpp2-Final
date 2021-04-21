#include "Character.h"

void Character::get_name()
{

	std::cout << "What is your character's name? ";
	std::cin >> name;
	
}

void Character::get_race()
{
	std::cout << "What race is " << name << "? ";
	std::cin >> race;

	if(race == "RANDOM")
	{
		int random_race = die(9, 1);
		
		switch(random_race)
		{
		case 1:
			race = "Elf";
			break;
		case 2:
			race = "Dwarf";
			break;
		case 3:
			race = "Tiefling";
			break;
		case 4:
			race = "Gnome";
			break;
		case 5:
			race = "Dragonborn";
			break;
		case 6:
			race = "Halfling";
			break;
		case 7:
			race = "Half-Elf";
			break;
		case 8:
			race = "Half-Orc";
			break;
		case 9:
			race = "Human";
			break;
		}
		
	}
	
}

void Character::get_class()
{

	std::cout << "What class would you like to be? ";
	std::cin >> class_name;

	if (class_name == "RANDOM")
	{
		const auto random_class = die(12, 1);

		switch (random_class)
		{
		case 1:
			class_name = "Barbarian";
			break;
		case 2:
			class_name = "Bard";
			break;
		case 3:
			class_name = "Cleric";
			break;
		case 4:
			class_name = "Druid";
			break;
		case 5:
			class_name = "Fighter";
			break;
		case 6:
			class_name = "Monk";
			break;
		case 7:
			class_name = "Paladin";
			break;
		case 8:
			class_name = "Ranger";
			break;
		case 9:
			class_name = "Rogue";
			break;
		case 10:
			class_name = "Sorcerer";
			break;
		case 11:
			class_name = "Warlock";
			break;
		case 12:
			class_name = "Wizard";
			break;
		}
	}

}



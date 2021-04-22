#include "Character.h"




void Character::get_name()
{

	std::cout << " What is your character's name? ";
	std::cin >> name;
	
}

void Character::get_race()
{
	std::cout << " What race is " << name << "? ";
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

	std::cout << " What class would you like to be? ";
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

int Character::get_value()
{
	int ability_array[4];

	for (auto& i : ability_array)
	{
		const auto ability_die = die(6, 1);
		i = {ability_die};
		// std::cout << ability_array[i] << " ";  // for debugging
	}
	
	std::sort(ability_array, ability_array+4);

	const auto result = ability_array[1] + ability_array[2] + ability_array[3];

	return result;

	/*
	// this was used for displaying the contents of our array from the random rolls
	for(int i = 0; i < 4; i++)
	{
		std::cout << ability_array[i] << " ";
	}

	// my original for-loop that was changed toa modern range-based for loop (thanks ReSharper)
	for (int i = 0; i < 4; i++)
	{
		int ability_die = die(6, 1);
		ability_array[i] = { ability_die };
		// std::cout << ability_array[i] << " ";  // for debugging
	}
	*/	
}

void Character::set_stats()
{
	auto* stat_rolls = stat_gen();
	
	auto const primary_stat = stat_rolls[5];
	auto const secondary_stat = stat_rolls[4];
	auto const tertiary_stat = stat_rolls[3];

	std::cout << "\n\nPRIMARY STAT: " << primary_stat << std::endl;
	std::cout << "SECONDARY STAT: " << secondary_stat << std::endl;
	std::cout << "TERTIARY STAT: " << tertiary_stat << std::endl;

	
	if(class_name == "Barbarian")
	{
		str = primary_stat;
		dex = stat_rolls[0];
		con = secondary_stat; 
		ine = stat_rolls[1];
		wis = stat_rolls[2];
		cha = stat_rolls[3];
	}if (class_name == "Bard")
	{
		str = stat_rolls[0];
		dex = secondary_stat; 
		con = stat_rolls[1];
		ine = stat_rolls[2];
		wis = stat_rolls[3];
		cha = primary_stat; 
	}if (class_name == "Cleric")
	{
		str = secondary_stat;
		dex = stat_rolls[0];
		con = tertiary_stat;
		ine = stat_rolls[1];
		wis = primary_stat; 
		cha = stat_rolls[2];
	}if (class_name == "Druid")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = tertiary_stat;
		wis = primary_stat;
		cha = stat_rolls[2];
	}if (class_name == "Fighter")
	{
		str = primary_stat;
		dex = secondary_stat;
		con = tertiary_stat;
		ine = stat_rolls[0];
		wis = stat_rolls[1];
		cha = stat_rolls[2];
	}if (class_name == "Monk")
	{
		str = tertiary_stat;
		dex = primary_stat; 
		con = stat_rolls[0];
		ine = stat_rolls[1];
		wis = secondary_stat;
		cha = stat_rolls[2];
	}if (class_name == "Paladin")
	{
		str = primary_stat; 
		dex = stat_rolls[0];
		con = stat_rolls[1];
		ine = stat_rolls[2];
		wis = tertiary_stat;
		cha = secondary_stat;
	}if (class_name == "Ranger")
	{
		str = secondary_stat;
		dex = primary_stat;
		con = stat_rolls[0];
		ine = stat_rolls[1];
		wis = tertiary_stat;
		cha = stat_rolls[2];
	}if (class_name == "Rogue")
	{
		str = stat_rolls[0];
		dex = primary_stat;
		con = stat_rolls[1];
		ine = tertiary_stat;
		wis = stat_rolls[2];
		cha = secondary_stat;
	}if (class_name == "Sorcerer")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = stat_rolls[2];
		wis = stat_rolls[3];
		cha = primary_stat;
	}if (class_name == "Warlock")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = stat_rolls[2];
		wis = tertiary_stat;
		cha = primary_stat;
	}if (class_name == "Wizard")
	{
		str = stat_rolls[0];
		dex = tertiary_stat;
		con = secondary_stat;
		ine = primary_stat;
		wis = stat_rolls[1];
		cha = stat_rolls[2];
	}
	
	/*char reroll_choice;
	int reroll_num;
	
	str = get_value();
	dex = get_value();
	con = get_value();
	ine = get_value();
	wis = get_value();
	cha = get_value();

	std::cout << " STR: " << str << std::endl;
	std::cout << " DEX: " << dex << std::endl;
	std::cout << " CON: " << con << std::endl;
	std::cout << " INT: " << ine << std::endl;
	std::cout << " WIS: " << wis << std::endl;
	std::cout << " CHA: " << cha << std::endl;

	std::cout << "Would you like to re-roll one of these stats? [ Y / N ] ";
	std::cin >> reroll_choice;

	if(reroll_choice == 'y')
	{
		std::cout << "Which stat would you like to re-roll?\
		\n [1] STR\n [2] DEX\n [3] CON\n [4] INT\n [5] WIS\n [6] CHA" << std::endl;

		std::cin >> reroll_num;
		
		switch(reroll_num)
		{
		case 1:
			str = get_value();
			std::cout << " STR: " << str << std::endl;
			break;
		case 2:
			dex = get_value();
			std::cout << " DEX: " << dex << std::endl;
			break;
		case 3:
			con = get_value();
			std::cout << " CON: " << con << std::endl;
			break;
		case 4:
			ine = get_value();
			std::cout << " INT: " << ine << std::endl;
			break;
		case 5:
			wis = get_value();
			std::cout << " WIS: " << wis << std::endl;
			break;
		case 6:
			cha = get_value();
			std::cout << " CHA: " << cha << std::endl;
			break;
			
		default:
			std::cout << "INVALID RESPONSE";
		}

		system("pause");
		
	}else if(reroll_choice == 'Y')
	{
		std::cout << "Which stat would you like to re-roll?\
		\n [1] STR\n [2] DEX\n [3] CON\n [4] INT\n [5] WIS\n [6] CHA" << std::endl;

		std::cin >> reroll_num;

		switch (reroll_num)
		{
		case 1:
			str = get_value();
			std::cout << " STR: " << str << std::endl;
			break;
		case 2:
			dex = get_value();
			std::cout << " DEX: " << dex << std::endl;
			break;
		case 3:
			con = get_value();
			std::cout << " CON: " << con << std::endl;
			break;
		case 4:
			ine = get_value();
			std::cout << " INT: " << ine << std::endl;
			break;
		case 5:
			wis = get_value();
			std::cout << " WIS: " << wis << std::endl;
			break;
		case 6:
			cha = get_value();
			std::cout << " CHA: " << cha << std::endl;
			break;

		default:
			std::cout << "INVALID RESPONSE";
		}

		system("pause");
	}*/
	
}

int* Character::stat_gen()
{
	static int rolls[6];

	std::cout << "RAW DATA: ";
	for (auto& roll : rolls)
	{
		roll = get_value();
	}
	for (int roll : rolls)
	{
		std::cout << roll << " ";
	}

	std::sort(rolls, rolls + 6);
	std::cout << "\n\nSORTED: ";
	for (auto roll : rolls)
	{
		std::cout << roll << " ";
	}

	unsigned const seed = 0;
	std::shuffle(rolls, rolls + 3, std::default_random_engine(seed));

	std::cout << "\nUNSORTED: ";
	for (auto roll : rolls)
	{
		std::cout << roll << " ";
	}

	auto const primary_stat = rolls[5];
	auto const secondary_stat = rolls[4];
	auto const tertiary_stat = rolls[3];

	std::cout << "\n\nPRIMARY STAT: " << primary_stat << std::endl;
	std::cout << "SECONDARY STAT: " << secondary_stat << std::endl;
	std::cout << "TERTIARY STAT: " << tertiary_stat << std::endl;

	return rolls;
} // TODO: clean up the couts


/* void Character::set_stats()
{

	char reroll_choice;
	int reroll_num;

	str = get_value();
	dex = get_value();
	con = get_value();
	ine = get_value();
	wis = get_value();
	cha = get_value();

	std::cout << " STR: " << str << std::endl;
	std::cout << " DEX: " << dex << std::endl;
	std::cout << " CON: " << con << std::endl;
	std::cout << " INT: " << ine << std::endl;
	std::cout << " WIS: " << wis << std::endl;
	std::cout << " CHA: " << cha << std::endl;

	std::cout << "Would you like to re-roll one of these stats? [ Y / N ] ";
	std::cin >> reroll_choice;

	if (reroll_choice == 'y')
	{
		std::cout << "Which stat would you like to re-roll?\
		\n [1] STR\n [2] DEX\n [3] CON\n [4] INT\n [5] WIS\n [6] CHA" << std::endl;

		std::cin >> reroll_num;

		switch (reroll_num)
		{
		case 1:
			str = get_value();
			std::cout << " STR: " << str << std::endl;
			break;
		case 2:
			dex = get_value();
			std::cout << " DEX: " << dex << std::endl;
			break;
		case 3:
			con = get_value();
			std::cout << " CON: " << con << std::endl;
			break;
		case 4:
			ine = get_value();
			std::cout << " INT: " << ine << std::endl;
			break;
		case 5:
			wis = get_value();
			std::cout << " WIS: " << wis << std::endl;
			break;
		case 6:
			cha = get_value();
			std::cout << " CHA: " << cha << std::endl;
			break;

		default:
			std::cout << "INVALID RESPONSE";
		}

		system("pause");

	}
	else if (reroll_choice == 'Y')
	{
		std::cout << "Which stat would you like to re-roll?\
		\n [1] STR\n [2] DEX\n [3] CON\n [4] INT\n [5] WIS\n [6] CHA" << std::endl;

		std::cin >> reroll_num;

		switch (reroll_num)
		{
		case 1:
			str = get_value();
			std::cout << " STR: " << str << std::endl;
			break;
		case 2:
			dex = get_value();
			std::cout << " DEX: " << dex << std::endl;
			break;
		case 3:
			con = get_value();
			std::cout << " CON: " << con << std::endl;
			break;
		case 4:
			ine = get_value();
			std::cout << " INT: " << ine << std::endl;
			break;
		case 5:
			wis = get_value();
			std::cout << " WIS: " << wis << std::endl;
			break;
		case 6:
			cha = get_value();
			std::cout << " CHA: " << cha << std::endl;
			break;

		default:
			std::cout << "INVALID RESPONSE";
		}

		system("pause");
	}

} */
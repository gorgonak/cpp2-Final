#include "Character.h"


void Character::get_name()
{
	system("CLS");
	
	std::cout << "\n\n What is your character's name? ";
	std::getline(std::cin, name);
}

void Character::get_race()
{
	auto loop = false;
	auto correct = false;

	while (!loop) {

		system("CLS");
		
	std::cout << "\n\n\n What race is " << name << "?\n\n";

	std::cout << " Choose from the following (please use all caps): \n [ ";
	for (const auto& i : race_list)
	{	
		std::cout << i << ", ";	
	}
	std::cout << "RANDOM ]\n\n ";
	std::cin >> race;
	
	if(race == "RANDOM")
	{
		const auto random_race = die(9, 1);
		
		switch(random_race)
		{
		case 1:
			race = "ELF";
			break;
		case 2:
			race = "DWARF";
			break;
		case 3:
			race = "TIEFLING";
			break;
		case 4:
			race = "GNOME";
			break;
		case 5:
			race = "DRAGONBORN";
			break;
		case 6:
			race = "HALFLING";
			break;
		case 7:
			race = "HALF-ELF";
			break;
		case 8:
			race = "HALF-ORC";
			break;
		case 9:
			race = "HUMAN";
			break;

		default:
			std::cout << "HUMANOID" << std::endl;
		}
		loop = true;
	}
	else if(race != "RANDOM")
	{
		system("CLS");

		for (const auto& i : race_list)
		{
			if (race == i)
			{
				correct = true;
				loop = true;
			}
		}
			if (!correct)
			{
				std::cout << race << " was an Invalid Response, Try Again\n\n";
				system("pause");
			}

		}
		
	}
}

void Character::get_class()
{
	auto loop = false;
	auto correct = false;

	while (!loop) {

		system("CLS");
		
		std::cout << "\n\n\n What class would you like to be? \n\n";

		std::cout << " Choose from the following (please use all caps): \n [ ";
		for (const auto& i : class_list)
		{
			std::cout << i << ", ";
		}
		std::cout << "RANDOM ]\n\n ";
		std::cin >> class_name;
		
		if (class_name == "RANDOM")
		{
			const auto random_class = die(12, 1);

			switch (random_class)
			{
			case 1:
				class_name = "BARBARIAN";
				break;
			case 2:
				class_name = "BARD";
				break;
			case 3:
				class_name = "CLERIC";
				break;
			case 4:
				class_name = "DRUID";
				break;
			case 5:
				class_name = "FIGHTER";
				break;
			case 6:
				class_name = "MONK";
				break;
			case 7:
				class_name = "PALADIN";
				break;
			case 8:
				class_name = "RANGER";
				break;
			case 9:
				class_name = "ROGUE";
				break;
			case 10:
				class_name = "SORCERER";
				break;
			case 11:
				class_name = "WARLOCK";
				break;
			case 12:
				class_name = "WIZARD";
				break;

			default:
				class_name = "unidentified";
			}
			
			loop = true;
		}
		else if(class_name != "RANDOM")
		{
			system("CLS");

			for (const auto& i : class_list)
			{
				if (class_name == i)
				{
					correct = true;
					loop = true;
				}
			}
			if (!correct)
			{
				std::cout << class_name << " was an Invalid Response, Try Again\n\n";
				system("pause");
			}

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

	system("CLS");
	
	std::cout << "\n\n\n " << class_name << "'s: " << std::endl;
	std::cout << " PRIMARY STAT: " << primary_stat << std::endl;
	std::cout << " SECONDARY STAT: " << secondary_stat << std::endl;
	std::cout << " TERTIARY STAT: " << tertiary_stat << std::endl;
	std::cout << std::endl;
	
	if(class_name == "BARBARIAN")
	{
		str = primary_stat;
		dex = stat_rolls[0];
		con = secondary_stat; 
		ine = stat_rolls[1];
		wis = stat_rolls[2];
		cha = stat_rolls[3];
	}if (class_name == "BARD")
	{
		str = stat_rolls[0];
		dex = secondary_stat; 
		con = stat_rolls[1];
		ine = stat_rolls[2];
		wis = stat_rolls[3];
		cha = primary_stat; 
	}if (class_name == "CLERIC")
	{
		str = secondary_stat;
		dex = stat_rolls[0];
		con = tertiary_stat;
		ine = stat_rolls[1];
		wis = primary_stat; 
		cha = stat_rolls[2];
	}if (class_name == "DRUID")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = tertiary_stat;
		wis = primary_stat;
		cha = stat_rolls[2];
	}if (class_name == "FIGHTER")
	{
		str = primary_stat;
		dex = secondary_stat;
		con = tertiary_stat;
		ine = stat_rolls[0];
		wis = stat_rolls[1];
		cha = stat_rolls[2];
	}if (class_name == "MONK")
	{
		str = tertiary_stat;
		dex = primary_stat; 
		con = stat_rolls[0];
		ine = stat_rolls[1];
		wis = secondary_stat;
		cha = stat_rolls[2];
	}if (class_name == "PALADIN")
	{
		str = primary_stat; 
		dex = stat_rolls[0];
		con = stat_rolls[1];
		ine = stat_rolls[2];
		wis = tertiary_stat;
		cha = secondary_stat;
	}if (class_name == "RANGER")
	{
		str = secondary_stat;
		dex = primary_stat;
		con = stat_rolls[0];
		ine = stat_rolls[1];
		wis = tertiary_stat;
		cha = stat_rolls[2];
	}if (class_name == "ROGUE")
	{
		str = stat_rolls[0];
		dex = primary_stat;
		con = stat_rolls[1];
		ine = tertiary_stat;
		wis = stat_rolls[2];
		cha = secondary_stat;
	}if (class_name == "SORCERER")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = stat_rolls[2];
		wis = stat_rolls[3];
		cha = primary_stat;
	}if (class_name == "WARLOCK")
	{
		str = stat_rolls[0];
		dex = stat_rolls[1];
		con = secondary_stat;
		ine = stat_rolls[2];
		wis = tertiary_stat;
		cha = primary_stat;
	}if (class_name == "WIZARD")
	{
		str = stat_rolls[0];
		dex = tertiary_stat;
		con = secondary_stat;
		ine = primary_stat;
		wis = stat_rolls[1];
		cha = stat_rolls[2];
	}
	
	reroll_stat();
}

void Character::reroll_stat()
{
	char reroll_choice;
	std::string user_stat;
	auto reroll = false;

	std::cout << "\n\n";
	std::cout << " STR: " << str << std::endl;
	std::cout << " DEX: " << dex << std::endl;
	std::cout << " CON: " << con << std::endl;
	std::cout << " INT: " << ine << std::endl;
	std::cout << " WIS: " << wis << std::endl;
	std::cout << " CHA: " << cha << std::endl;

	std::cout << "\n\n Would you like to re-roll one of these stats? [ Y / N ] ";
	std::cin >> reroll_choice;

	switch (reroll_choice)
	{
	case 'y':
	case 'Y':
		while (!reroll)
		{
			std::cout << "\n\n Which stat would you like to re-roll [ STR, DEX, CON, INT, WIS, CHA, NEVERMIND ] ? \n ";

			std::cin >> user_stat;

			if (user_stat == "STR")
			{
				str = get_value();
				std::cout << " STR: " << str << std::endl;
				reroll = true;
			}
			else if (user_stat == "DEX")
			{
				dex = get_value();
				std::cout << " DEX: " << dex << std::endl;
				reroll = true;
			}
			else if (user_stat == "CON")
			{
				con = get_value();
				std::cout << " CON: " << con << std::endl;
				reroll = true;
			}
			else if (user_stat == "INT")
			{
				ine = get_value();
				std::cout << " INT: " << ine << std::endl;
				reroll = true;
			}
			else if (user_stat == "WIS")
			{
				wis = get_value();
				std::cout << " WIS: " << wis << std::endl;
				reroll = true;
			}
			else if (user_stat == "CHA")
			{
				cha = get_value();
				std::cout << " CHA: " << cha << std::endl;
				reroll = true;
			}
			else if (user_stat == "NEVERMIND")
			{
				reroll = true;
			}
			else
			{
				Game::clr_input();
				system("CLS");
			}
		}
	default:
		break;
	}
}
	
	/*if(reroll_choice == 'y')
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


int* Character::stat_gen()
{
	static int rolls[6];

	for (auto& roll : rolls)
	{
		roll = get_value();
	}
	/*std::cout << "RAW DATA: ";
	for (int roll : rolls)
	{
		std::cout << roll << " ";
	}
	*/

	std::sort(rolls, rolls + 6);
	/*std::cout << "\n\nSORTED: ";
	for (auto roll : rolls)
	{
		std::cout << roll << " ";
	}*/

	unsigned const seed = 0;
	std::shuffle(rolls, rolls + 3, std::default_random_engine(seed));

	/*std::cout << "\nUNSORTED: ";
	for (auto roll : rolls)
	{
		std::cout << roll << " ";
	}*/


	return rolls;
} // TODO: clean up the couts

int Character::get_health() const
{	
	return char_health;
}

void Character::set_health()
{
	auto health = 0;

	if(class_name == "BARBARIAN")
	{
		health = 12;
	}
	else if (class_name == "BARD")
	{
		health = 8;
	}
	else if (class_name == "CLERIC")
	{
		health = 8;
	}
	else if (class_name == "DRUID")
	{
		health = 8;
	}
	else if (class_name == "FIGHTER")
	{
		health = 10;
	}
	else if (class_name == "MONK")
	{
		health = 8;
	}
	else if (class_name == "PALADIN")
	{
		health = 10;
	}
	else if (class_name == "RANGER")
	{
		health = 10;
	}
	else if (class_name == "ROGUE")
	{
		health = 8;
	}
	else if (class_name == "SORCERER")
	{
		health = 6;
	}
	else if (class_name == "WARLOCK")
	{
		health = 8;
	}
	else if (class_name == "WIZARD")
	{
		health = 6;
	}
	
	switch(con)
	{
	case 12:
	case 13:
		health = (health + 1);
		break;
	case 14:
	case 15:
		health = (health + 2);
		break;
	case 16:
	case 17:
		health = (health + 3);
		break;
	case 18:
	case 19:
		health = (health + 4);
		break;
	case 20:
		health = (health + 5);
		
	default:
		break;
	}

	char_health = health;

}

void Character::char_display()
{
	
}
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
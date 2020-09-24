#include <iostream>
#include "Character.h"

void logCharacterParameters(Character &, Character&);

void game(Character&, Character&);

int main(int argc, char* argv[])
{
	if (argc != 7) { 
		std::cout << "Wrong input! " << std::endl;
		std::cout << "A suitable input: ./a.out Maple 150 10 Sally 45 30 " << std::endl;
		return 1;
	}
	else 
	{
		Character player1(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
		Character player2(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

		game(player1, player2);

	}

	return 0;
}

void logCharacterParameters(Character & ply1, Character & ply2)
{
	std::cout << ply1.getName() << ": HP: " << ply1.getHealthPoint() << ", DMG: " << ply1.getDamage() << std::endl;
	std::cout << ply2.getName() << ": HP: " << ply2.getHealthPoint() << ", DMG: " << ply2.getDamage() << std::endl;
}

void game(Character &pl1, Character &pl2)
{
	//Log players parameters 
	logCharacterParameters(pl1,pl2);

	while (pl1.isDead() == 0 && pl2.isDead() == 0 ) 
	{
		//1->2
		//Log attack order 
		std::cout << pl1.getName() << " -> " << pl2.getName() << std::endl;
		//Player1 attacks 
		pl2.injure(pl1.getDamage());
		//Log players parameters 
		logCharacterParameters(pl1, pl2);
		//Check pl2's hp
		if(pl2.isDead())
		{
			std::cout << pl2.getName() << " died. " << pl1.getName() << " wins." << std::endl;
			break;
		}

		//2->1
		//Log attack order 
		std::cout << pl2.getName() << " -> " << pl1.getName() << std::endl;
		//Player2 attacks 
		pl1.injure(pl2.getDamage());
		//Log players parameters 
		logCharacterParameters(pl1, pl2);
		//Check pl1's hp
		if (pl1.isDead())
		{
			std::cout << pl1.getName() << " died. " << pl2.getName() << " wins." << std::endl;
			break;
		}

	}

}




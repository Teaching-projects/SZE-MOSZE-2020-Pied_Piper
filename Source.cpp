#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "Character.h"

void game(Character&, Character&);

static void parseUnit(const std::string&, std::vector<std::string>&);


int main(int argc, char* argv[])
{
	std::vector<std::string> words;

	if (argc != 3) { 
		std::cout << "Wrong input! " << std::endl;
		std::cout << "A suitable input: ./a.out Garfield.txt SpongeBob.txt " << std::endl;
		return 1;
	}
	else 
	{
		parseUnit(argv[1], words);
		Character player1(words[0], std::stoi(words[1]), std::stoi(words[2]));

		parseUnit(argv[2], words);
		Character player2(words[0], std::stoi(words[1]), std::stoi(words[2]));

		game(player1, player2);

	}

	return 0;
}

void game(Character &pl1, Character &pl2)
{
	while (pl1.isDead() == 0 && pl2.isDead() == 0 ) 
	{
		//1->2
		//Player1 attacks 
		pl2.injure(pl1.getDamage());
		//Check pl2's hp
		if(pl2.isDead())
		{
			std::cout << pl1.getName()<< " wins. Remaining HP: " << pl1.getHealthPoint() << std::endl;
			break;
		}

		//2->1
		//Player2 attacks 
		pl1.injure(pl2.getDamage());
		//Check pl1's hp
		if (pl1.isDead())
		{
			std::cout << pl2.getName() << " wins. Remaining HP: " << pl2.getHealthPoint() << std::endl;
			break;
		}

	}

}

static void parseUnit(const std::string& fileName, std::vector<std::string> &words)
{
	words.clear();
	std::ifstream file(fileName);
	std::string currentLine;


	//Checking wrong input 
	if (file.fail()) {

		const std::string error("Error: The System doesn't find this file: " + fileName);
		throw error;

	}

	else
	{
		while (std::getline(file, currentLine))
		{
			words.push_back(currentLine);
		}

		words.erase(words.end());
		words.erase(words.begin());

		for (size_t i = 0; i < words.size(); i++)
		{
			words[i].erase(remove(words[i].begin(), words[i].end(), ' '), words[i].end());
			words[i].erase(remove(words[i].begin(), words[i].end(), '"'), words[i].end());
			words[i].erase(remove(words[i].begin(), words[i].end(), ','), words[i].end());
			words[i].erase(remove(words[i].begin(), words[i].end(), '\r'), words[i].end());
		}

		for (size_t i = 0; i < words.size(); i++)
		{
			size_t pos = 0;
			while ((pos = words[i].find(':')) != std::string::npos)
			{
				words[i].erase(0, pos + 1);
			}
		}

		// words[0], 
		// stoi(words[1]) 
		// stoi(words[2])

	}
}

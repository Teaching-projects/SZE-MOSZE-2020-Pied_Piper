#pragma once
#include<string>
class Character
{
	const std::string name;
	const int dmg;
	int healthPoint;

public:
	Character(std::string, const int, const int);

	std::string getName() const;
	int getHealthPoint() const;
	int getDamage() const;
	bool isDead();


	void injure(int);
	void attack(Character &);

};


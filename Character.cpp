#include "Character.h"

Character::Character(std::string name, const int hp, const int dmg) : name(name),healthPoint(hp),dmg(dmg){}

std::string Character::getName() const
{
	return name;
}

int Character::getHealthPoint() const
{
	return healthPoint;
}

int Character::getDamage() const
{
	return dmg;
}

bool Character::isDead()
{
	if (healthPoint <= 0) {
		return true;
	}
	return false;

}

void Character::injure(int damageValue)
{
	healthPoint -= damageValue;
	if (healthPoint < 0) { healthPoint = 0; }

}

void Character::attack(Character& character)
{
	character.injure(dmg);
}

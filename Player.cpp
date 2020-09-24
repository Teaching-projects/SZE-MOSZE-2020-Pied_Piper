#include "Player.h"

Player::Player(std::string name, float hp, float dmg) : name(name),hp(hp),dmg(dmg){}

void Player::GetPlayerStatus()
{
	std::cout << name << ": HP: "<< this->hp<<", DMG: "<<this->dmg<< "\n";
}

const std::string Player::GetName()
{
	return this->name;
}

const float Player::GetHp()
{
	return this->hp;
}

const float Player::GetDmg()
{
	return this->dmg;
}

void Player::SetInjury(float damage)
{
	this->hp -= damage;
	if (this->hp < 0) { this->hp = 0; }
}









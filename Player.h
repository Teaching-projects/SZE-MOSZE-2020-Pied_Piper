#pragma once
#include<iostream>

class Player
{
public:
	//Constructor 
	Player(std::string,float,float);

	//Return informations about player
	void GetPlayerStatus();
	
	//Return players name
	const std::string GetName();

	//Return players hp 
	const float GetHp();

	//Return players damage 
	const float GetDmg();

	//Set players hp
	void SetInjury(float);

private:
	std::string name;
	float hp, dmg;

};


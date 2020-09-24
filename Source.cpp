#include<iostream>
#include"Player.h"

//DECLARATION
void Fight(Player*, Player*);
void PrintAllStatus(Player*, Player*);
void CheckHp(Player*, Player*, bool &);



int main() 
{
	//Creating players 	
	Player* player1 = new Player("Maple",150,10);
	Player* player2 = new Player("Sally",45,30);
	
	//Start fight 
	Fight(player1,player2);

	//Deleting pointers
	delete player1;
	delete player2;

	return 0;
}

//DEFINITION
void Fight(Player* player1, Player* player2)
{
	//fip = fight in progress
	bool fip = true;
	bool playerSwap = true;
	
	//Printng all starting status 
	PrintAllStatus(player1, player2);

	//Fight scene 
	while (fip)
	{
		//1th->2th
		if(playerSwap)
		{
			std::cout << player1->GetName() << " -> " << player2->GetName()<< "\n";

			//Attack
			player2->SetInjury(player1->GetDmg());
		
			//Status after the round 
			PrintAllStatus(player1, player2);
			//Check players hp
			CheckHp(player1, player2, fip);
			//Swap players
			playerSwap = false;
		}
		//2th->1th
		else
		{
			std::cout << player2->GetName() << " -> " << player1->GetName() << "\n";

			//Attack
			player1->SetInjury(player2->GetDmg());

			//Status after the round 
			PrintAllStatus(player1, player2);
			//Check players hp
			CheckHp(player1, player2, fip);
			//Swap players
			playerSwap = true;
		}
		
	}

}

void PrintAllStatus(Player* player1, Player* player2)
{
	player1->GetPlayerStatus();
	player2->GetPlayerStatus();
}

void CheckHp(Player* player1, Player* player2, bool & fip)
{
	if (player1->GetHp() <= 0)
	{
		std::cout << player1->GetName() << " died. " << player2->GetName() << " wins.";
		fip = false;
	}
	else if (player2->GetHp() <= 0)
	{
		std::cout << player2->GetName() << " died. " << player1->GetName() << " wins.";
		fip = false;
	}
}



#pragma once
#include "Player.h"
#include <iostream>
#include <vector>

class AttackPhase {
private:
	Player* thePlayer;
	vector<Country*> eligibleCountries;



public:
	AttackPhase();
	~AttackPhase();

	AttackPhase(Player &player);

	void prompt();


	void attackCountry(int fromCountry);
	int displayAndChooseCountry();
};
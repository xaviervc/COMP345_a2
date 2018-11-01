#pragma once
#include <vector>
#include "Player.h"
#include "Map.h"
#include <cmath>
#include <math.h>


using namespace std;

class ReinforcePhase {
public:
	ReinforcePhase();
	~ReinforcePhase();
	ReinforcePhase(Player &Player);

	void getArmies();
	void getContinentBonus(Map* map);

	void placeArmies(int numOfArmies, int countryChoice);
	void prompt();
	void displayOwnedCountries();


private:
	Player* thePlayer;
};
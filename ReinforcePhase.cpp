#include "ReinforcePhase.h"

using namespace std;

ReinforcePhase::ReinforcePhase(){}
ReinforcePhase::~ReinforcePhase(){}

ReinforcePhase::ReinforcePhase(Player &Player) : thePlayer(&Player)   {}

void ReinforcePhase::getArmies() {
	int size = thePlayer->numberOfCountriesOwned();

	if (size > 0) {
		if (size < 9) {
			thePlayer->addArmiesToPlaceOnBoard(3);
		}
		else {
			int temp = floor(size / 3);
			thePlayer->addArmiesToPlaceOnBoard(temp);
		}
	}
}

void ReinforcePhase::getContinentBonus(Map* map) {

	int playerID = thePlayer->getId();
	int totalBonus = 0;


	for (int i = 0; i < map->getContinentList().size(); i++) {
		
		int count = 0;
		string continentName = map->getContinentList()[i].getName();


		for (int j = 0; j < map->getContinentSize(i); j++) {
			//note maybe strcmp better
			if (thePlayer->getCountriesOwned()[j]->getContinentName() == continentName) {
				count++;
			}
		}

		if (count == map->getContinentSize(i)) {
			totalBonus += map->getContinentList()[i].getBonus();
		}
		
	}

	thePlayer->addArmiesToPlaceOnBoard(totalBonus);
}

void ReinforcePhase::placeArmies(int numOfArmies, int countryChoice) {
	//place the armies on the selected country
	thePlayer->getCountriesOwned()[countryChoice]->addArmies(numOfArmies);

	//subract armies held by player by the amount you placed
	thePlayer->addArmiesToPlaceOnBoard(-numOfArmies);
}

void ReinforcePhase::displayOwnedCountries() {

	//displays all the countries owned with the i+1 for a menu choice
	for (int i = 0; i < thePlayer->numberOfCountriesOwned(); i++) {
		cout << i+1 << thePlayer->getCountriesOwned()[i]->getName() << endl;
	}
}

void ReinforcePhase::prompt() {
	cout << "How many armies would you like to place?" << endl;
	cout << endl;
	int numOfArmies;
	cin >> numOfArmies;

	//need to be a while loop
	if (numOfArmies > thePlayer->getTotalArmies()) {
		cout << "That number exceeds the total number of armies you have, please input a value less than or equal to " << thePlayer->getTotalArmies() << endl;
		cin >> numOfArmies;
	}

	cout << "On which country would you like to place these armies on?" << endl;
	cout << endl;
	int countryChoice;

	//display owned countries
	displayOwnedCountries();

	cin >> countryChoice;

	//need to be a while loop
	if (countryChoice > thePlayer->numberOfCountriesOwned()) {
		cout << "Invalid input must be in range of 1 to" << thePlayer->numberOfCountriesOwned();
		cin >> countryChoice;
	}


	
}
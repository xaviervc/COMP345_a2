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
		cout << i+1 <<"."<< thePlayer->getCountriesOwned()[i]->getName() << endl;
	}
}

void ReinforcePhase::prompt() {

	int numOfArmies;
	int countryChoice;
	
	cout << "How many armies would you like to place?" << endl;
	cin >> numOfArmies;
		while (numOfArmies > thePlayer->getTotalArmies() || numOfArmies < 0) {
			cout << "Invalid input try again." << endl;
			cin >> numOfArmies;
		}

	cout << "On which country would you like to place these armies on?" << endl;
	cout << endl;

	displayOwnedCountries();
	cout << endl;
	cin >> countryChoice;

		while (countryChoice > thePlayer->numberOfCountriesOwned() || countryChoice < 1) {
			cout << "Invalid input must be in range of 1 to" << thePlayer->numberOfCountriesOwned() << "try again." << endl;
			cin >> countryChoice;
		}

	//subtract 1 from countryChoice so you don't go out of bounds
	placeArmies(numOfArmies, countryChoice-1);
}

void ReinforcePhase::cardExchange(Deck d,Hand h) {

	if (h.returnHand().size() >= 5)
	{
		int armies = h.exchange(d);
		thePlayer->addArmiesToPlaceOnBoard(armies);
	}
	
}
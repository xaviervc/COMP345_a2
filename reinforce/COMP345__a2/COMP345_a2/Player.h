#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Country.h"
#include "Hand.hpp"

using namespace std;

class Player{

private:
	vector <string> countries;
	string dice;
	int id;

	//Added for reinforce phase by Xavier Vani-Charron
	vector<Country*> countriesOwned;
	int totalNumberOfArmies;
	Hand hand;
	//************************************************


public:
	Player();
	~Player();

	Player(int Id);

	//Added for reinforce phase by Xavier Vani-Charron
	int numberOfCountriesOwned();
	vector<Country*> getCountriesOwned();
	int getTotalArmies();
	void addArmiesToPlaceOnBoard(int armies);
	void setCountries(vector<Country*> countryList);
	int getId();
	//************************************************

	void diceImp();

	void reinforce();
	void attack();

	void fortify();
	void setHand(Hand h);
	
};


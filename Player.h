#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Country.h"

using namespace std;

class Player{

private:
	vector <string> countries;
	vector <string> hand;
	string dice;
	int id;

	//Added for reinforce phase by Xavier Vani-Charron
	vector<Country*> countriesOwned;
	int totalNumberOfArmies;
	//************************************************


public:
	Player();
	~Player();
	Player(vector <string> cont, vector <string> hd, string diceObj, int Id);
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

};


#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Country
{
public:
	Country();
	Country(std::string countryName,int x, int y, std::string continentName, std::string border);
    Country(std::string line);

	int getOwner() const;
	int getNumberOfBorderingCountries() const;
	std::string getContinentName() const;
	std::string getName() const;
	std::string getBorderString() const;

	Country travel(int index);
	Country travel(std::string name);
	void addCountryToBorder(Country* otherCountry);

	bool nextTo(Country otherCountry);

	void displayBorderCountries();
    
    void display();

	//assignment #2 added by Xavier VC
	void setOwner(int id);
	void addArmies(int armies);
	int getArmies();
	//***********************************

private:
	std::string name;
	std::string continent;
    std::string borderString;
    int posX;
    int posY;
	int armyCount;
	int owner;
	int linkedCountries;
	std::vector<Country*> borderCountries;
	int totalArmies;
};


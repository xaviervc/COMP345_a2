#pragma once
#include <vector>
#include "Continent.h"

class Map
{
public:
	Map();
	Map(std::vector<std::string> lineList);
	Map(std::string file);
    Country* getCountry(int i);
    int size();
    void addContinent(Continent cont);
    void addCountry(Country coun);
    void connectObjects();
    bool validGraph();
	bool connectedMap(Country start);
	bool connectedSubGraph(Continent target);
	void display();

	//Added by Xavier for reinforcement phase
	std::vector<Continent> getContinentList();
	int getContinentSize(int loc);
	//*****************************************

	//Added by Xavier for game loop
	std::vector<Country> getAllCountries();
	//*****************************************

private:
	std::vector<Continent> continent;
	std::vector<Country> country;

	bool inVectorList(std::vector<Country> list, Country count);
};


// Driver_MapClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Card.hpp"

using namespace std;

int main()
{
	//The following section of code test the MapClass

	//Open and load file
	std::string line;
	std::vector<std::string> lineList;
	std::ifstream inputFile;
	inputFile.open("Alabama.map");

	while (!inputFile.eof()) {
		getline(inputFile, line);
		lineList.push_back(line);
	}

	//Test constructor using a vector
	Map validMap = Map(lineList);
	inputFile.close();

	//Test constructor using a file path
	Map validMap2 = Map("Alabama.map");

	//Build and invalid map (with 1 unreachable country)
	Map invalidMap1 = Map();
	invalidMap1.addCountry((std::string)"Ter1,2,3,Cont,Ter2");
	invalidMap1.addCountry((std::string)"Ter2,2,3,Cont,Ter1");
	invalidMap1.addCountry((std::string)"Ter3,2,3,Cont,");
	invalidMap1.addContinent((std::string)"Cont=8");
	invalidMap1.addContinent((std::string)"Con2=4");

	//Build invalid map (with 2 disconected countries)
	Map invalidMap2 = Map();
	invalidMap2.addCountry((std::string)"Ter1,2,3,Cont,Ter2");
	invalidMap2.addCountry((std::string)"Ter2,2,3,Cont,Ter1");
	invalidMap2.addCountry((std::string)"Ter3,2,3,Cont2,Ter4");
	invalidMap2.addCountry((std::string)"Ter4,2,3,Cont2,Ter3");
	invalidMap2.addContinent((std::string)"Cont=8");
	invalidMap2.addContinent((std::string)"Con2=4");

	//Connect the nodes of every map
	validMap.connectObjects();
	validMap2.connectObjects();
	invalidMap1.connectObjects();
	invalidMap2.connectObjects();

	//Display the full map breakdown
	validMap.display();
	invalidMap1.display();
	invalidMap2.display();

	//Test for validity (1 true, 0 false)
	std::cout << validMap2.validGraph()<<" "<< invalidMap1.validGraph()<<" "<< invalidMap2.validGraph()<<std::endl;
	
	std::cout <<endl<< validMap2.allLinksAreTwoWay()<<endl;

	char response, response1;

	vector <Card> deck;
	vector<string> names;

	Hand h;

	for (int i = 0; i<validMap.size(); i++)
	{
		names.push_back(validMap.getCountry(i).getName());
	}

	//Initialize deck
	Deck d;
	d.initializeDeck(names);

	//create deck
	cout << "deck created\n";

	//shuffle

	d.shuffleDeck();
	d.shuffleDeck();
	d.shuffleDeck();
	d.shuffleDeck();

	d.displayDeck();

	int infCount = 0;
	int calvCount = 0;
	int artCount = 0;
	Card hold;

	//Output totals of each card type
	for (int i = 0; i < names.size(); i++) {
	
		hold = d.draw();

		if (hold.getType().compare("infantry") == 0)
			infCount++;
		if (hold.getType().compare("cavalry") == 0)
			calvCount++;
		if (hold.getType().compare("artillery") == 0)
			artCount++;

		d.addCard(hold);

	}

	//Put all cards back into deck from discard
	d.replenishDeck();

	cout <<" "<< infCount << " " << calvCount << " " << artCount<<endl;

	//Draw and exchange loop
	do {
		//Replenish the deck if it's empty
		if (d.isEmpty())
		{
			d.replenishDeck();
			d.shuffleDeck();
		}
		cout << "Press any key to draw a card. Enter q or Q at any time to quit.\n";
		cin >> response;

		//Exit if no card needs to be drawn
		if (response == 'q'|| response == 'Q')
		{
			cout << "thanks for playing\n";
			exit(1);
		}

		Card card = d.draw();// draw from deck
		h.newCard(card);//save in hand

		cout << "you drew: " << card.getName() << "," << card.getType() << endl;

		h.displayHand();

		cout << "exchange a card?(any key for yes and n for no)\n";
		cin >> response1;

		if (response1 == 'n' || response1 == 'N')
			continue;

		cout << "You received: "<<h.exchange(d)<<" armies."<< endl;

	} while (response != 'q' && response != 'Q');

	system("pause");
    return 0;
}


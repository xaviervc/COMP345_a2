#include "GameLoop.h"
#include "ReinforcePhase.h"
#include "Map.h"
#include "Continent.h"
#include "Country.h"
#include "Deck.hpp"
#include <vector>

using namespace std;


/*
//game loop driver
int main() {
	//load a map
	Map testMap = Map("Alabama.map");

	//create vec of player objects
	vector<Player> players;

	//instanciate players
	for (int i = 0; i < 4; i++) {
		players.push_back(Player(i));
	}

	//start the game
	GameLoop newGame(players, testMap);

	//start the loop
	newGame.gameLoop();

	//give all countries
	cin.get();
}
*/

int main() {


	//load map
	Map testMap("Alabama.map");
	testMap.connectObjects();
	vector<Country*> testCountries = testMap.getContinentList()[0].getCountryList();

	//create a deck
	Deck testDeck;
	vector<string> contNames;

	for (auto i : testMap.getContinentList())
		contNames.push_back(i.getName());

	testDeck.initializeDeck(contNames);

	/*create a player with ID 1 and give it some countries*/
	Player testPlayer(1);
	testPlayer.addArmiesToPlaceOnBoard(100);
	testPlayer.setCountries(testCountries);

	//give hand to player
	Hand testHand;
	vector <Card> testCard;

	for(int i=0;i<5;i++)
	{
		Card draw = testDeck.draw();
		testCard.push_back(draw);
	}
	testHand.setHand(testCard);
	testPlayer.setHand(testHand);

	//create reinforce object to test
	ReinforcePhase testPhase(testPlayer);
	testPhase.cardExchange(testDeck,testHand);
	testPhase.prompt();

	//print the countries armies
	for (auto i : testPlayer.getCountriesOwned())
		cout << i->getName() << " " << i->getArmies() << endl;
	cout << endl;
	cout << testPlayer.getTotalArmies() << endl;



	system("pause");
}
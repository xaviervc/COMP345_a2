#include "GameLoop.h"
#include "Map.h"
#include "Continent.h"
#include "Country.h"
#include <vector>

using namespace std;




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


//int main() {
//	Map testMap("Alabama.map");
//
//	//NEED TO SET UP HOW THE PLAYER GETS A COUNRY LIST
//	//testMap.getContinentList[0].
//
//	Player testPlayer;
//}
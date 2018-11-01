#include "GameLoop.h"

using namespace std;

GameLoop::GameLoop() {}
GameLoop::~GameLoop() {}

//initializer needs to be used
GameLoop::GameLoop(vector<Player> Players, Map &Map) : currentPlayer(0), turnsPlayed(0), map(&Map) {

	//fill vector of players
	for (auto i : Players) {
		players.push_back(i);
	}
}

void GameLoop::gameLoop() {

	//position in the players vector is the turn sequence
	for (currentPlayer; currentPlayer < players.size(); currentPlayer++) {

		//check to see if player won
		if (playerWon()) {
			cout << "Player " << players[currentPlayer].getId() << " won." << endl;
			return;
		}

		//reach last player then restart to continue playing
		if (currentPlayer == players.size()-1) {
			//prompt for last player
			prompt();
			currentPlayer = 0;
		}
		prompt();
		
		//simple stopping mechanism for testing purposes
		if (turnsPlayed == 10)
			giveAllCountries(currentPlayer);


		turnsPlayed++;
	}
}

bool GameLoop::playerWon() {
	return players[currentPlayer].numberOfCountriesOwned() == map->size();
}

void GameLoop::prompt() {
	cout << "Player " << currentPlayer+1 << " is currently playing" << endl;

	//bizarre syntax if pointer of vectors is passed the pointer dereference needs to happen before the [] operator
	players[currentPlayer].reinforce();
	players[currentPlayer].attack();
	players[currentPlayer].fortify();
}


//testing purpose
void GameLoop::giveAllCountries(int playerLoc) {

	vector<Country*> temp;

	for (int i = 0; i < map->size(); i++) {
		temp.push_back(map->getCountry(i));
		temp[i]->setOwner(players[playerLoc].getId());
	}

	players[playerLoc].setCountries(temp);
}
#include "Player.h"
#include "ReinforcePhase.h"

using namespace std;

Player::Player() : totalNumberOfArmies(0) {}
Player::~Player() {}

Player::Player (vector<string> count, vector<string> hnd, string diceObj, int Id) {
	countries=count;
	hand = hnd;
	dice = diceObj;
	id = Id;
}

Player::Player(int Id) {
	id = Id;
}

void Player::diceImp()
{
	//Dice Thing
	cout<<"diceroll: "<< dice <<endl;
}

void Player::reinforce()
{
	cout << "reinforced" << endl;

	/* Used for Reinforcement phase part
	ReinforcePhase reinforce(*this);
	reinforce.prompt();
	*/
}

void Player::attack()
{
	cout << "attacked" << endl;
}

void Player::fortify()
{
	cout << "fortify" << endl;
}

void Player::setCountries(vector<Country*> countryList) {

	for (int i = 0; i < countryList.size(); i++) {
		countriesOwned.push_back(countryList[i]);
	}
}

int Player::getId() {
	return id;
}

vector<Country*> Player::getCountriesOwned() {
	return countriesOwned;
}

int Player::numberOfCountriesOwned() {
	return countriesOwned.size();
}

int Player::getTotalArmies() {
	return totalNumberOfArmies;
}

void Player::addArmiesToPlaceOnBoard(int armies) {
	totalNumberOfArmies += armies;
}
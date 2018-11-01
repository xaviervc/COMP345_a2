#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

int main() {

	vector<string> count = { "Canada","USA", "Mexico", "France", "Colombia" };

	vector <string> hand = { "Canada-Infantry","USA-Artillery", "Mexico-Infantry", "France-Calvary", "Colombia-Infantry" };

	vector<string> count2 = { "North Korea","South Korea", "Nice Korea", "Best Korea", "Korea" };

	vector <string> hand2 = { "1-Infantry","2-Artillery", "3-Infantry", "4-Calvary", "5-Infantry" };

	string diceOBj = "This will be a Dice object (Part 3)";
	string diceOBj2 = "This is a different Dice object";

	Player p1 = Player(count, hand, diceOBj);
	Player p2 = Player(count2, hand2, diceOBj2);

	cout << "First Player: "<< endl;

	p1.attack();
	p1.reinforce();
	p1.diceImp();
	p1.fortify();

	cout << "Second Player: " << endl;

	p2.attack();
	p2.reinforce();
	p2.diceImp();
	p2.fortify();

	cout << "Enter q or Q at any time to exit.";

	char input;

	 do{
	
		cin >> input;

	 } while (input != 'q'&& input != 'Q');

}

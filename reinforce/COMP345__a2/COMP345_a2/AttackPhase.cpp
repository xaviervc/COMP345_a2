//#include "AttackPhase.h"
//
//AttackPhase::AttackPhase() {}
//
//AttackPhase::~AttackPhase() {}
//
//AttackPhase::AttackPhase(Player &player) : thePlayer(&player){}
//
//using namespace std;
//
//void AttackPhase::prompt() {
//
//	while (1) {
//		cout << "Would you like to attack?" << endl;
//		cout << "Input \"y\" to attack or \"n\" to skip attack phase." << endl;
//		cout << endl;
//
//		char choice;
//		cin >> choice;
//
//		if (choice == 'n') {
//			cout << "Attack phase over." << endl;
//			return;
//		}
//		else if (choice == 'y') {
//			//put main attack and choice logic here
//			while (1) {
//				displayAndChooseCountry();
//			}
//		}
//		else {
//			cout << "Invalid choice" << endl;
//			cout << "Input \"y\" to attack or \"n\" to skip attack phase." << endl;
//			cout << endl;
//		}
//	}
//}
//
//
//int AttackPhase::displayAndChooseCountry() {
//
//	cout << "Which country would you like to attack from?" << endl;
//	cout << endl;
//
//	for (int i = 0; i < thePlayer->getCountriesOwned().size(); i++) {
//		if (thePlayer->getCountriesOwned()[i]->getArmies() > 1) {
//
//			int count = 1;
//			cout << count << " " << thePlayer->getCountriesOwned()[i]->getName() << endl;
//
//			//fill eligibleCountries container
//			eligibleCountries.push_back(thePlayer->getCountriesOwned()[i]);
//			
//			count++;
//		}
//	}
//
//
//}
//
//
//
//void AttackPhase::attackCountry(int fromCountry) {
//	//display adjacent list
//}
//
//void eligibleAdjacentCountries(){}
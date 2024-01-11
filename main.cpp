#include <iostream>
#include <string>
#include "pokemon.h"
#include "fight.h"
#include "items.h"
#include "info.h"

using namespace std;

int main() {
	// player money and inventory, will be available to other sub functions
	int money = 200;
	int* money_ptr = &money;
	int inventory[3] = { 0,0,0 };

	string option = "";
	while (option != "quit") {
		cout << "You have " << money << " money" << endl;
		cout << "Select an option (fight, shop, info, quit): ";
		cin >> option;
		if (option == "fight") {
			//fight function returns how much money the player gains if any
			money += fight(inventory);
		}
		if (option == "shop") {
			itemShop(money_ptr, inventory);
		}
		if (option == "info") {
			checkPokemon();
		}
	}
	return 0;
}
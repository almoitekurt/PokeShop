#include <iostream>
#include <string>
#include "pokemon.h"

using namespace std;

const int numItems = 3;
const string shopItems[numItems] = { "Small Potion", "Super Potion", "Max Potion" };
int potion = 0;
int hp;

void printShop()
{
	cout << "Pokeshop Inventory: " << endl;
	for (int i = 0; i < numItems; i++) {
		cout << i + 1 << ". " << shopItems[i] << "(" << 25*(i+1) << " money)" << endl;
	}

	cout << endl;
}

void printInventory(const int playerInventory[numItems]) {
	cout << " Whats in your inventory: " << endl;
	for (int i = 0; i < numItems; i++) {
		if (playerInventory[i] > 0) {
			cout << i+1 << ". " << playerInventory[i] << "x " << shopItems[i] << endl; // prints and updates new player inventory after every buy
		}
	}
	cout << endl;
}

bool buyItems(int playerInventory[numItems], int* money)
{
	cout << "You have " << *money << " money" << endl;
	int input;
	cout << " What would you like to purchase? (Enter 0 to Exit) Enter (" << 1 << "-" << 3 << ") to purchase: "; // purchases items coresponding to string shopItems.
	cin >> input;

	if (input == 0) { // exits shop
		return true;
	}
	if (input - 1 < 0 || input - 1 >= numItems) { // prints error if #'s 0-3 not chosen. 
		cout << " ERROR ";
		return false;
	}
	if (*money < (25 * input)) {
		cout << "You don't have enough money!" << endl;
	}
	else {
		cout << "Bought 1 " << shopItems[input-1] << endl;
		playerInventory[input - 1]++;
		*money = *money - (25 * input);
	}
	return false;
}

// created object to store values populated by for loop
void currentHp() {
	int smallPotion = 0;
	int superPotion = 0;
	int maxPotion = 0;


// Populate Object
	for (int i = 0; i < 100; i++) { // Created for loop to run until i is < 100
	if (i <= 25) { // if i is less than or equal to 25 add to potion 1
		int smallPotion{};  smallPotion + 0.25;
	}
	else if (i <= 50) { // if i is less that 50 but greater that 25 add to potion 2
		int superPotion{}; superPotion + 0.50;
	}
	else { // add to potion3 to handle falsy results above
		int maxPotion{};  maxPotion + 1;
		}
	}
	cout << "Consuming! " << potion;
}

int usePotion(Pokemon* poke, int hp, int inventory[]) {
	printInventory(inventory);
	int choice;
	cout << "What to use?" << endl;
	cin >> choice;
	if (choice == 1 && inventory[choice - 1] > 0) {
		if ((hp + 10) > poke->hp) {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return poke->hp;
		}
		else {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return hp + 10;
		}
	}
	else if (choice == 2 && inventory[choice - 1] > 0) {
		if ((hp + 20) > poke->hp) {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return poke->hp;
		}
		else {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return hp + 20;
		}
	}
	else if (choice == 3 && inventory[choice - 1] > 0) {
		if ((hp + 50) > poke->hp) {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return poke->hp;
		}
		else {
			inventory[choice - 1] = inventory[choice - 1] - 1;
			return hp + 50;
		}
	}
	else {
		cout << "You don't have enough!" << endl;
		return hp;
	}
}

void itemShop(int* money, int playerInventory[]) {   // CALL TO MAIN
	bool isDone = false;

	cout << " *** Welcome to the PokeShop! *** " << endl;

	while (isDone == false) {
		printShop();
		printInventory(playerInventory);
		isDone = buyItems(playerInventory, money);
	}
}
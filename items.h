#pragma once


#include <string>
#include <vector>

void itemShop(int* money, int inventory[]);
void printInventory(const int playerInventory[]);
void printShop();
bool buyItems(int playerInventory[]);
void currentHp();
int usePotion(Pokemon* poke, int hp, int inventory[]);
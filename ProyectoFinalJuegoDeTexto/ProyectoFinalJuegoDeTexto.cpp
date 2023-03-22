#include <iostream>
#include <string>
#include <json/json.h>
#include <fstream>
using namespace std;


struct Weapon {
	string name;
	int damage;
};

const int NUM_WEAPONS = 3;
Weapon weapon_database[NUM_WEAPONS] = {
	{"Sword", 10},
	{"Axe", 15},
	{"Mace", 20}
};

int main()
{
	Json::Value root;

	cout << "SimpleRPg!" << endl;
	cout << "commands:|attack|rest|" << endl;
	cout << "----------------------------------" << endl;


	int health = 100;
	int attack = 10;
	Weapon current_weapon = weapon_database[0];


	while (health > 0)
	{

		cout << "Health: " << health << endl;
		cout << "Attack: " << attack << endl;
		cout << "Weapon: " << current_weapon.name << " (+" << current_weapon.damage << " damage)" << endl;


		string input;
		cout << "What do you want to do? ";
		getline(cin, input);

		if (input == "attack" || "a")
		{

			root["health"] = health;
			std::ofstream newFile("data1.json");
			newFile << root;
			newFile.close();

			cout << "You attack the enemy with your " << current_weapon.name << "!" << endl;
			int damage = rand() % current_weapon.damage + 1;
			cout << "You deal " << damage << " damage!" << endl;
		}
		else if (input == "rest" || "r")
		{
			cout << "You rest and regain some health." << endl;

			int restore = rand() % 10 + 1;
			health += restore;
			cout << "You restore " << restore << " health!" << endl;
		}
		else if (input == "loot" || "l")
		{
			cout << "You find a weapon!" << endl;
			int index = rand() % NUM_WEAPONS;
			current_weapon = weapon_database[index];
			cout << "You pick up a " << current_weapon.name << " (+" << current_weapon.damage << " damage)" << endl;
		}
		else
		{
			cout << "Invalid input. Try again." << endl;
		}


		int enemy_attack = rand() % 10 + 1;
		cout << "The enemy attacks you!" << endl;
		cout << "You take " << enemy_attack << " damage!" << endl;
		health -= enemy_attack;
	}


	cout << "Game Over!" << endl;
	cout << "You died." << endl;

	return 0;
}

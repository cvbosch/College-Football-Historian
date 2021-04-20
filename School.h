#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct School
{
	//roster, tree of jersey numbers
	struct Player
	{
		Player* left;
		Player* right;
		short number;
		string name;
		Player(short number, string name);
	};

	School* left;
	School* right;
	string school;
	vector<short> years; //years with data
	unordered_map<short, Player*> roster; //roster in desired year

	School(string school);
	Player* updateRoster(Player* node, short number, string name);
	void findPlayer(Player* node, short number);
	void printRoster(Player* node);
};

#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct SchoolAVL
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

	SchoolAVL* left;
	SchoolAVL* right;
	string school;
	vector<short> years; //years with data
	unordered_map<short, Player*> roster; //roster in desired year

	SchoolAVL(string school);
	Player* updateRoster(Player* node, short number, string name);
	void findPlayer(Player* node, short number);
	void printRoster(Player* node);




	//Roster tree balancing
	bool isBalanced(Player* node, int& balance);
	int getHeight(Player* node);
	int maximum(int left, int right);
	Player* rotate(Player* node, int parentBalance);
	Player* rotateLeft(Player* node);
	Player* rotateRight(Player* node);
	Player* rotateLeftRight(Player* node);
	Player* rotateRightLeft(Player* node);
};

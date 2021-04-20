#include "School.h"
using namespace std;


School::Player::Player(short number, string name)
{
	this->number = number;
	this->name = name;
	left = nullptr;
	right = nullptr;
}


School::School(string school)
{
	this->school = school;
	left = nullptr;
	right = nullptr;
}

School::Player* School::updateRoster(Player* node, short number, string name)
{
	if (node == nullptr)
		return new Player(number, name);

	if (number < node->number)
		node->left = updateRoster(node->left, number, name);
	else
		node->right = updateRoster(node->right, number, name);

	return node;
}

void School::findPlayer(Player* node, short number)
{
	if (node == nullptr)
	{
		cout << "Nobody wore " << number << " that year!" << endl;
	}
	else if (number == node->number)
	{
		cout << node->name << endl;
		//findPlayer(node->left, number);
		//findPlayer(node->right, number);
	}
	else if (number < node->number)
		if (node->left != nullptr)
		{
			findPlayer(node->left, number);
		}
		else
		{
			cout << "Nobody wore " << number << " that year!" << endl;
		}
	else
		if (node->right != nullptr)
		{
			findPlayer(node->right, number);
		}
		else
		{
			cout << "Nobody wore " << number << " that year!" << endl;
		}
}

void School::printRoster(Player* node)
{
	if (node == nullptr)
		return;

	printRoster(node->left);
	cout << node->number << ", " << node->name << endl;
	printRoster(node->right);
}

School* addSchool(School* node, string school)
{
	if (node == nullptr)
		return new School(school);

	if (school < node->school)
		node->left = addSchool(node->left, school);
	else
		node->right = addSchool(node->right, school);

	return node;
}

School* findSchool(School* node, string school)
{
	if (node == nullptr)
		return nullptr;

	if (school == node->school)
		return node;
	else if (school < node->school)
		return findSchool(node->left, school);
	else
		return findSchool(node->right, school);
}
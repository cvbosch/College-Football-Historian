#include "SchoolAVL.h"
using namespace std;


bool isBalanced(SchoolAVL* node, int& balance);
int getHeight(SchoolAVL* node);
int maximum_S(int left, int right);
SchoolAVL* rotate(SchoolAVL* node, int parentBalance);
SchoolAVL* rotateLeft(SchoolAVL* node);
SchoolAVL* rotateRight(SchoolAVL* node);
SchoolAVL* rotateLeftRight(SchoolAVL* node);
SchoolAVL* rotateRightLeft(SchoolAVL* node);


//Player member function
SchoolAVL::Player::Player(short number, string name)
{
	this->number = number;
	this->name = name;
	left = nullptr;
	right = nullptr;
}

//School member functions
SchoolAVL::SchoolAVL(string school)
{
	this->school = school;
	left = nullptr;
	right = nullptr;
}
SchoolAVL::Player* SchoolAVL::updateRoster(Player* node, short number, string name)
{
	if (node == nullptr)
		return new Player(number, name);

	if (number < node->number)
		node->left = updateRoster(node->left, number, name);
	else
		node->right = updateRoster(node->right, number, name);

	int balance;
	if (isBalanced(node, balance))
		return node;
	else
		return rotate(node, balance);
}
void SchoolAVL::findPlayer(Player* node, short number)
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
void SchoolAVL::printRoster(Player* node)
{
	if (node == nullptr)
		return;

	printRoster(node->left);
	cout << node->number << ", " << node->name << endl;
	printRoster(node->right);
}

//Roster tree balancing
bool SchoolAVL::isBalanced(Player* node, int& balance)
{
	if (node == nullptr)
		return true;

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	balance = leftHeight - rightHeight;

	if (balance > 1 || balance < -1)
		return false;

	return true;
}
int SchoolAVL::getHeight(Player* node)
{
	if (node == nullptr)
		return 0;

	return 1 + maximum(getHeight(node->left), getHeight(node->right));
}
int SchoolAVL::maximum(int left, int right)
{
	if (left > right)
		return left;

	return right;
}
SchoolAVL::Player* SchoolAVL::rotate(Player* node, int parentBalance)
{
	int childBalance = 0;
	if (parentBalance > 0)
		isBalanced(node->left, childBalance);
	else
		isBalanced(node->right, childBalance);

	//left left case, rotate right
	if (parentBalance > 1 && childBalance > -1)
		return rotateRight(node);

	//right Right case, rotate left
	else if (parentBalance < -1 && childBalance < 1)
		return rotateLeft(node);

	//left right case, rotate left right
	else if (parentBalance > 1 && childBalance < 0)
		return rotateLeftRight(node);

	//right left case, rotate right left
	else if (parentBalance < -1 && childBalance > 0)
		return rotateRightLeft(node);

	else
		return node;
}
SchoolAVL::Player* SchoolAVL::rotateLeft(Player* node)
{
	Player* grandchild = node->right->left;
	Player* parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}
SchoolAVL::Player* SchoolAVL::rotateRight(Player* node)
{
	Player* grandchild = node->left->right;
	Player* parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
SchoolAVL::Player* SchoolAVL::rotateLeftRight(Player* node)
{
	Player* left = node->left;

	Player* grandchild = left->right->left;
	Player* parent = left->right;
	parent->left = left;
	left->right = grandchild;

	node->left = parent;

	grandchild = node->left->right;
	parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
SchoolAVL::Player* SchoolAVL::rotateRightLeft(Player* node)
{
	Player* right = node->right;

	Player* grandchild = right->left->right;
	Player* parent = right->left;
	parent->right = right;
	right->left = grandchild;

	node->right = parent;

	grandchild = node->right->left;
	parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}



SchoolAVL* addSchoolAVL(SchoolAVL* node, string school)
{
	if (node == nullptr)
		return new SchoolAVL(school);

	if (school < node->school)
		node->left = addSchoolAVL(node->left, school);
	else
		node->right = addSchoolAVL(node->right, school);

	int balance;
	if (isBalanced(node, balance))
		return node;
	else
		return rotate(node, balance);
}

SchoolAVL* findSchoolAVL(SchoolAVL* node, string school)
{
	if (node == nullptr)
		return nullptr;

	if (school == node->school)
		return node;
	else if (school < node->school)
		return findSchoolAVL(node->left, school);
	else
		return findSchoolAVL(node->right, school);
}


//School tree balancing
bool isBalanced(SchoolAVL* node, int& balance)
{
	if (node == nullptr)
		return true;

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	balance = leftHeight - rightHeight;

	if (balance > 1 || balance < -1)
		return false;

	return true;
}
int getHeight(SchoolAVL* node)
{
	if (node == nullptr)
		return 0;

	return 1 + maximum_S(getHeight(node->left), getHeight(node->right));
}
int maximum_S(int left, int right)
{
	if (left > right)
		return left;

	return right;
}
SchoolAVL* rotate(SchoolAVL* node, int parentBalance)
{
	int childBalance = 0;
	if (parentBalance > 0)
		isBalanced(node->left, childBalance);
	else
		isBalanced(node->right, childBalance);

	//left left case, rotate right
	if (parentBalance > 1 && childBalance > -1)
		return rotateRight(node);

	//right Right case, rotate left
	else if (parentBalance < -1 && childBalance < 1)
		return rotateLeft(node);

	//left right case, rotate left right
	else if (parentBalance > 1 && childBalance < 0)
		return rotateLeftRight(node);

	//right left case, rotate right left
	else if (parentBalance < -1 && childBalance > 0)
		return rotateRightLeft(node);

	else
		return node;
}
SchoolAVL* rotateLeft(SchoolAVL* node)
{
	SchoolAVL* grandchild = node->right->left;
	SchoolAVL* parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}
SchoolAVL* rotateRight(SchoolAVL* node)
{
	SchoolAVL* grandchild = node->left->right;
	SchoolAVL* parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
SchoolAVL* rotateLeftRight(SchoolAVL* node)
{
	SchoolAVL* left = node->left;

	SchoolAVL* grandchild = left->right->left;
	SchoolAVL* parent = left->right;
	parent->left = left;
	left->right = grandchild;

	node->left = parent;

	grandchild = node->left->right;
	parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
SchoolAVL* rotateRightLeft(SchoolAVL* node)
{
	SchoolAVL* right = node->right;

	SchoolAVL* grandchild = right->left->right;
	SchoolAVL* parent = right->left;
	parent->right = right;
	right->left = grandchild;

	node->right = parent;

	grandchild = node->right->left;
	parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}

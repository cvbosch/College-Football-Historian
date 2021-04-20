#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <chrono>
#include "SchoolAVL.h"
#include "School.h"
#include "NameAVL.h"
#include "Name.h"
using namespace std;


SchoolAVL* addSchoolAVL(SchoolAVL* node, string school);
SchoolAVL* findSchoolAVL(SchoolAVL* node, string school);
School* addSchool(School* node, string school);
School* findSchool(School* node, string school);
NameAVL* addNameAVL(NameAVL* node, string name);
NameAVL* findNameAVL(NameAVL* node, string name);
Name* addName(Name* node, string name);
Name* findName(Name* node, string name);


void outputAVL(SchoolAVL* root, SchoolAVL* node, NameAVL* rootN, NameAVL* nodeN)
{
	auto start = chrono::high_resolution_clock::now();

	cout << "\nSearch options" << endl;
	cout << "-----------------" << endl;
	cout << "0. Quit program" << endl;
	cout << "1. Find name of player with school, number, and year" << endl;
	cout << "2. Find names of players with school and number" << endl;
	cout << "3. Print roster with school and year" << endl;
	cout << "4. Print all rosters of school in database" << endl;
	cout << "5. Print a players career information" << endl;
	cout << "6. Print a player's number in a year" << endl;
	cout << "7. Print a player's school in a year" << endl;

	int option;
	cout << "\nChoose option: ";
	cin >> option;
	string school;
	short number;
	short year;
	string name;

	if (option == 1)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter number: ";
		cin >> number;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;

		start = chrono::high_resolution_clock::now();
		node = findSchoolAVL(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			bool found = false;
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				if (node->years[i] == year)
				{
					found = true;
					node->findPlayer(node->roster[year], number);
				}
			}
			if (!found)
				cout << "Player not found!" << endl;
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 2)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter number: ";
		cin >> number;

		start = chrono::high_resolution_clock::now();
		node = findSchoolAVL(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				cout << "\n" << node->years[i] << ": " << endl;
				node->findPlayer(node->roster[node->years[i]], number);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 3)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		node = findSchoolAVL(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			if (node->roster[year] == nullptr)
				cout << year << " roster is unavailable" << endl;
			else
			{
				cout << "\n" << year << " roster: " << endl;
				node->printRoster(node->roster[year]);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 4)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);

		start = chrono::high_resolution_clock::now();
		node = findSchoolAVL(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				cout << "\n" << node->years[i] << " roster: " << endl;
				node->printRoster(node->roster[node->years[i]]);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	/*else if (option == 5)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);

		start = chrono::high_resolution_clock::now();
		nodeN = findNameAVL(rootN, name);
		if (nodeN != nullptr)
			nodeN->printInfo();
		else
			cout << "Name not found!" << endl;
	}

	else if (option == 6)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		nodeN = findNameAVL(rootN, name);
		if (nodeN != nullptr)
			nodeN->printNumber(year);
		else
			cout << "Name not found!" << endl;
	}

	else if (option == 7)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		nodeN = findNameAVL(rootN, name);
		if (nodeN != nullptr)
			nodeN->printSchool(year);
		else
			cout << "Name not found!" << endl;
	}*/

	else
		cout << "Input invalid." << endl;

}

void outputBST(School* root, School* node, Name* rootN, Name* nodeN)
{
	auto start = chrono::high_resolution_clock::now();

	cout << "\nSearch options" << endl;
	cout << "-----------------" << endl;
	cout << "0. Quit program" << endl;
	cout << "1. Find name of player with school, number, and year" << endl;
	cout << "2. Find names of players with school and number" << endl;
	cout << "3. Print roster with school and year" << endl;
	cout << "4. Print all rosters of school in database" << endl;
	//cout << "5. Print a players career information" << endl;
	//cout << "6. Print a player's number in a year" << endl;
	//cout << "7. Print a player's school in a year" << endl;

	int option;
	cout << "\nChoose option: ";
	cin >> option;
	string school;
	short number;
	short year;
	string name;

	if (option == 1)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter number: ";
		cin >> number;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;

		start = chrono::high_resolution_clock::now();
		node = findSchool(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			bool found = false;
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				if (node->years[i] == year)
				{
					found = true;
					node->findPlayer(node->roster[year], number);
				}
			}
			if (!found)
				cout << "Player not found!" << endl;
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 2)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter number: ";
		cin >> number;

		start = chrono::high_resolution_clock::now();
		node = findSchool(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				cout << "\n" << node->years[i] << ": " << endl;
				node->findPlayer(node->roster[node->years[i]], number);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 3)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		node = findSchool(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			if (node->roster[year] == nullptr)
				cout << year << " roster is unavailable" << endl;
			else
			{
				cout << "\n" << year << " roster: " << endl;
				node->printRoster(node->roster[year]);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	else if (option == 4)
	{
		cout << "Enter school: ";
		cin.ignore();
		getline(cin, school);

		start = chrono::high_resolution_clock::now();
		node = findSchool(root, school);
		auto end = chrono::high_resolution_clock::now();
		if (node != nullptr)
		{
			for (unsigned int i = 0; i < node->years.size(); i++)
			{
				cout << "\n" << node->years[i] << " roster: " << endl;
				node->printRoster(node->roster[node->years[i]]);
			}
		}
		else
			cout << "School not found!" << endl;
		chrono::duration<double> duration = end - start;
		cout << "Time taken: " << duration.count() << "s" << endl;
	}

	/*else if (option == 5)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);

		start = chrono::high_resolution_clock::now();
		nodeN = findName(rootN, name);
		if (nodeN != nullptr)
			nodeN->printInfo();
		else
			cout << "Name not found!" << endl;
	}

	else if (option == 6)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		nodeN = findName(rootN, name);
		if (nodeN != nullptr)
			nodeN->printNumber(year);
		else
			cout << "Name not found!" << endl;
	}

	else if (option == 7)
	{
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter year: ";
		cin >> year;

		start = chrono::high_resolution_clock::now();
		nodeN = findName(rootN, name);
		if (nodeN != nullptr)
			nodeN->printSchool(year);
		else
			cout << "Name not found!" << endl;
	}*/

	else
		cout << "Input invalid." << endl;
}

SchoolAVL* testAVL(SchoolAVL* root)
{
	string school;
	cout << "Choose school name: ";
	cin.ignore();
	getline(cin, school);

	auto start = chrono::high_resolution_clock::now();
	root = addSchoolAVL(root, school);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Time taken: " << duration.count() << "s" << endl;

	return root;
}

School* testBST(School* root)
{
	string school;
	cout << "Choose school name: ";
	cin.ignore();
	getline(cin, school);

	auto start = chrono::high_resolution_clock::now();
	root = addSchool(root, school);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Time taken: " << duration.count() << "s" << endl;

	return root;
}


int main()
{
	ifstream file("Rosters.csv");

	string info = "";
	short number;
	string name;
	string school;
	short year;

	SchoolAVL* rootAVL = nullptr;
	SchoolAVL* nodeAVL = nullptr;
	SchoolAVL::Player* playerAVL = nullptr;
	School* root = nullptr;
	School* node = nullptr;
	School::Player* player = nullptr;
	string curSchool = "";
	short curYear = -1;

	NameAVL* rootNameAVL = nullptr;
	NameAVL* nodeNameAVL = nullptr;
	unordered_map<string, NameAVL*> namesAVL;
	Name* rootName = nullptr;
	Name* nodeName = nullptr;
	unordered_map<string, Name*> names;

	if (file.is_open())
	{
		getline(file, info, '\n');
		while (getline(file, info, ','))
			//for (int i = 0; i < 15; i++)
		{
			//getline(file, info, ',');
			number = stoi(info);
			getline(file, name, ',');
			getline(file, school, ',');
			getline(file, info, '\n');
			year = stoi(info);

			//SCHOOL CLASS
			if (school == curSchool)
			{
				if (year != curYear)
				{
					curYear = year;
					nodeAVL->years.push_back(year);
					node->years.push_back(year);
				}
				nodeAVL->roster[year] = nodeAVL->updateRoster(nodeAVL->roster[year], number, name);
				node->roster[year] = node->updateRoster(node->roster[year], number, name);
			}
			else
			{
				curSchool = school;
				rootAVL = addSchoolAVL(rootAVL, school);
				root = addSchool(root, school);
				nodeAVL = findSchoolAVL(rootAVL, school);
				node = findSchool(root, school);
				curYear = year;
				nodeAVL->years.push_back(year);
				node->years.push_back(year);
				nodeAVL->roster[year] = nodeAVL->updateRoster(nodeAVL->roster[year], number, name);
				node->roster[year] = node->updateRoster(node->roster[year], number, name);
			}

			cout << school << endl;

			//NAME CLASS

			/*if (names.find(name) == names.end())
			{
				rootName = addName(rootName, name);
				rootNameAVL = addNameAVL(rootNameAVL, name);
				nodeName = findName(rootName, name);
				nodeNameAVL = findNameAVL(rootNameAVL, name);
				names[name] = nodeName;
				namesAVL[name] = nodeNameAVL;
			}
			else
			{
				nodeName = names[name];
				nodeNameAVL = namesAVL[name];
			}
			nodeName = nodeName->updateName(number, school, year);
			nodeNameAVL = nodeNameAVL->updateName(number, school, year);*/

		}
		file.close();
	}

	else
		cout << "File failed to open!" << endl;


	bool quit = false;
	while (!quit)
	{
		cout << "\nChoose a tree" << endl;
		cout << "-----------------" << endl;
		cout << "0. Quit program" << endl;
		cout << "1. AVL tree" << endl;
		cout << "2. Regular BST" << endl;
		cout << "3. Test insertion time with AVL" << endl;
		cout << "4. Test insertion time with BST" << endl;

		int option;
		cout << "\nChoose option: ";
		cin >> option;


		if (option == 0)
			quit = true;
		else if (option == 1)
			outputAVL(rootAVL, nodeAVL, rootNameAVL, nodeNameAVL);
		else if (option == 2)
			outputBST(root, node, rootName, nodeName);
		else if (option == 3)
			rootAVL = testAVL(rootAVL);
		else if (option == 4)
			root = testBST(root);
		else
			cout << "Input invalid." << endl;
	}

	return 0;
}
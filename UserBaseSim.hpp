#ifndef USERBASESIM_HPP
#define USERBASESIM_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"
#include "UserListGen.hpp"
#include "Cryptographer.hpp"

using std::cout;
using std::endl;
using std::getline;

// header comment goes here

class UserBaseSim
{
	private:
	HashTable userDB;
	const string NAME_FILE = "lastNames.txt";
	ifstream fileReader;
	void PopulateDB();
	public:
	UserBaseSim();
	void CheckDB();
};

#endif

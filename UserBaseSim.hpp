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

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: UserBaseSim.hpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - Defines the methods and attributes to create the needed files,
 *   Populate a hashtable with encrypted passwords, and to compare the stored passwords against raw ones to ensure validity.
 ***************************************************************/

class UserBaseSim
{
	private:
	HashTable userDB;
	const string NAME_FILE = "lastNames.txt";
	const string ENCRYPT_FILE = "encrypted.txt";
	const string CHECK_FILE = "raw.txt";
	const string CIPHER_KEY = "jones";
	ifstream fileReader;
	public:
	UserBaseSim();
	void PopulateDB();
	void CheckDB();
};

#endif

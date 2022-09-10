#ifndef USERLISTGEN_HPP
#define USERLISTGEN_HPP

 /***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: UserListGen.hpp
 *	Assignment number: Project 1
 *
 *	Other comments regarding the file - UserListGen.hpp defines the variables and methods
 *      used for generating a file "raw.txt" containing usernames and passwords; 
 *      the former of which is read from the file "lastNames.txt" and the latter
 *      which is randomly generated. An instance of the Cryptographer class is then used
 *      to generate a list of userIds and encrypted passwords to be read into a hash table for storage.
 *
 ***************************************************************/

#include <fstream>
#include "Cryptographer.hpp"

using std::fstream;

class UserListGen
{
	private:
	fstream fileHandler;
	Cryptographer* dataCryptographer;

	public:
	UserListGen(string nameDataFile);
	void GenerateEncryptedList();
};

#endif

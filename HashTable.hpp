#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: HashTable.hpp
 *	Assignment number: Project 1
 *
 *      Other comments regarding the file - HashTable.hpp defines the variables and methods
 *	used to store userData by a key in an externally linked hashtable.
 *
 ***************************************************************/
#include "Node.hpp"

class HashTable
{
	private:
	int numBuckets;
	Node** headerBucketList;
	int NameToNum(string someString);
	
	public:
	HashTable(int someNumBuckets);
	~HashTable();
	int HashFunction(string userKey);
	void InsertItem(string userID, string userPassword);
	Node* FindItem(string userID);
};

#endif

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
#include <list>

using std::list;

class HashTable
{
	private:
	Node** headerBucketList;
	int numBuckets;
	int NameToNum(string someString);
	
	public:
	HashTable(int numBuckets);
	~HashTable();
	int HashFunction(string userKey);
	void InsertItem(string userId, string password);
	Node* FindItem(string userId);
};

#endif

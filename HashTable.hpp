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

const int NUM_BUCKETS = 17;

class HashTable
{
	private:
	Node* headerBucketList[NUM_BUCKETS];
	int NameToNum(string someString);
	
	public:
	HashTable();
	~HashTable();
	int HashFunction(string userKey);
	void InsertItem(string userID, string userPassword);
	Node* FindItem(string userID);
};

#endif

#include "HashTable.hpp"

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: HashTable.cpp
 *	Assignment number: Project 1
 *
 *      Other comments regarding the file - HashTable.cpp implements the variables and methods
 *	defined by the HashTable class.
 *
 ***************************************************************/

HashTable::HashTable(int numBuckets)
{
	this->numBuckets = numBuckets;

	this->headerBucketList = new Node*[numBuckets];

	for(int i = 0; i < this->numBuckets; ++i)
	{
		headerBucketList[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	delete[] headerBucketList;
}

int HashTable::HashFunction(string userKey)
{
	return (this->NameToNum(userKey) % this->numBuckets);
}

void HashTable::InsertItem(string userId, string password)
{
	int whatBucket = HashFunction(userId);
	Node* tableTraveler = nullptr;

	if(headerBucketList[whatBucket] != nullptr)
	{
		tableTraveler = headerBucketList[whatBucket];
		while(tableTraveler->GetNext() != nullptr)
		{
			tableTraveler = tableTraveler->GetNext();
		}

		tableTraveler->SetNext(new Node(userId, password));
	}
	else
	{
		headerBucketList[whatBucket] = new Node(userId, password);
	}
}

Node* HashTable::FindItem(string userId)
{
	Node* itemHolder = nullptr;
	return itemHolder;
}

//Helper
int HashTable::NameToNum(string someString)
{
	int convert;

	for(long unsigned int i = 0; i < someString.length(); ++i)
	{
		convert += someString[i]; 
	}

	return convert;
}

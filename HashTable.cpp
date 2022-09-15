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
		this->headerBucketList[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	Node* nodeGrabber = nullptr;
	for(int i = 0; i < this->numBuckets; ++i)
	{
		while(this->headerBucketList[i] != nullptr)
		{
			nodeGrabber = this->headerBucketList[i];
			if(nodeGrabber->GetNext() == nullptr)
			{
				delete nodeGrabber;
			}
			else
			{
				nodeGrabber = nodeGrabber->GetNext();
			}
		}
	}
	
	delete[] this->headerBucketList;
}

int HashTable::HashFunction(string userKey)
{
	return (NameToNum(userKey) % this->numBuckets);
}

void HashTable::InsertItem(string userId, string password)
{
	int whatBucket = HashFunction(userId);
	Node* tableTraveler = nullptr;

	if(this->headerBucketList[whatBucket] != nullptr)
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
		this->headerBucketList[whatBucket] = new Node(userId, password);
	}
}

Node* HashTable::FindItem(string userId)
{
	Node* itemHolder = nullptr;
	bool nameFound = false;
	int whatBucket = HashFunction(userId);
	
	itemHolder = this->headerBucketList[whatBucket];

	while(!nameFound)
	{
		if(itemHolder == nullptr)
		{
			break;
		}
		else if(itemHolder->GetUserId() == userId)
		{
			nameFound = true;
		}
		else
		{
			itemHolder = itemHolder->GetNext();
			nameFound = false;
		}
	}

	return itemHolder;
}

int HashTable::NameToNum(string someString)
{
	int convert;

	for(long unsigned int i = 0; i < someString.length(); ++i)
	{
		convert += someString[i]; 
	}

	return convert;
}

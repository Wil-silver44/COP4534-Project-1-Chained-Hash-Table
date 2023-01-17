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
	//pointer to array of node pointers.
	this->headerBucketList = new Node*[numBuckets];

	//makes every pointer null to begin
	for(int i = 0; i < this->numBuckets; ++i)
	{
		this->headerBucketList[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	//helper node
	Node* nodeGrabber = nullptr;

	//DELETE LATER: loop through every bucket
	for(int i = 0; i < this->numBuckets; ++i)
	{
		//DELETE LATER: while the current bucket is not null
		while(this->headerBucketList[i] != nullptr)
		{
			//DELETE LATER: sets helper node to the current bucket header
			nodeGrabber = this->headerBucketList[i];
			//DELETE LATER: if the current node has no next node, delete it.
			if(nodeGrabber->GetNext() == nullptr)
			{
				delete nodeGrabber;
			}
			//DELETE LATER: otherwise, move the helper to the next node, and repeat the check until the header is all that remains.
			else
			{
				nodeGrabber = nodeGrabber->GetNext();
			}
		}
	}
	
	delete this->headerBucketList;
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

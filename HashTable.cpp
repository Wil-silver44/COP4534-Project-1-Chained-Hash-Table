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

HashTable::HashTable()
{
	for(int i = 0; i < NUM_BUCKETS; ++i)
	{
		headerBucketList[i] = nullptr;	
	}
}

HashTable::~HashTable()
{

	Node* helperNode = nullptr;

	for(int i = 0; i < NUM_BUCKETS; ++i)
	{
		//if something is in the bucket
		if(headerBucketList[i] != nullptr)
		{
			//if there is another node in the linked list stored in the bucket
			if(headerBucketList[i]->GetNext() != nullptr)
			{
				//until the bucket is empty, loop
				while(headerBucketList[i] != nullptr)
				{
					helperNode = headerBucketList[i];

					if(helperNode->GetNext() != nullptr)
					{
						helperNode = helperNode->GetNext();
					}
					else
					{
						delete helperNode;
					}
				}
			}
			else
			{
				delete headerBucketList[i];
			}
			
		}
	}
}

int HashTable::HashFunction(string userKey)
{
	return (NameToNum(userKey) % NUM_BUCKETS);
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
	bool nameFound = false;
	int whatBucket = HashFunction(userId);
	
	itemHolder = headerBucketList[whatBucket];

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

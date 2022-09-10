#ifndef NODE_HPP
#define NODE_HPP

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: Node.hpp
 *	Assignment number: Project 1
 *
 *	Other comments regarding the file - Node.hpp defines the variables and methods
 *	used to contain user information for insertion and retrieval in a hash table.
 *
 ***************************************************************/


#include<string>

using std::string;

class Node
{
	private:
	string userId;
	string password;
	Node* next;
	public:
	Node(string userId, string password);
	void SetNext(Node* someNext);
	void SetUserId(string userId);
	void SetPassword(string password);

	Node* GetNext();
	string GetUserId();
	string GetPassword();
};

#endif

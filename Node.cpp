#include "Node.hpp"

/***************************************************************
 *	Student Name: Wilver Santos
 *	File Name: Node.cpp
 *	Assignment number: Project 1
 *
 *	Other comments regarding the file - Node.cpp implements the definitions of
 *	the  variables and methods used to contain user information 
 *	for insertion and retrieval in a hash table.
 *
 ***************************************************************/

Node::Node(string userId, string password)
{
	this->next = nullptr;
	SetUserId(userId);
	SetPassword(password);
}

void Node::SetNext(Node* someNext)
{ this->next = someNext; }

void Node::SetUserId(string userId)
{ this->userId = userId; }

void Node::SetPassword(string password)
{ this->password = password; }

Node* Node::GetNext()
{ return this->next; }

string Node::GetUserId()
{ return this->userId; }

string Node::GetPassword()
{ return this->password; }

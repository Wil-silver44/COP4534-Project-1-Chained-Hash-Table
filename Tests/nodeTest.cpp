#include "../Node.hpp"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	cout << "Testing Node class. Creating node object with the following information:" << endl;
	cout << "userId: jones" << endl << "passWord: davis" << endl << endl;

	Node* userNode = new Node("jones","davis");

	cout << "Node created!" << endl << endl;
	
	string userIdTest = userNode->GetUserId();

	string userPasswordTest = userNode->GetPassword();

	if (userIdTest == "jones" && userPasswordTest == "davis")
	{
		cout << "TEST PASSED." << endl << endl;
	}
	else
	{
		cout << "TEST FAILED." << endl << endl; 
	}

	delete userNode;

	cout << "Node destroyed." << endl;

	return 0;
}

#include "../HashTable.hpp"
#include "../Node.hpp"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Creating Table with 4 buckets." << endl;
	HashTable testTable;

	cout << endl << "Table created!" << endl << endl;

	string user = "jenessa";
	string pass = "avalon";
	
	cout << "testing insertion of the following user data." << endl;
	cout << "Username: " << user << endl << "Password: " << pass << endl << endl;

	testTable.InsertItem(user, pass);

	Node* resultHolder = nullptr;

	cout << "reading data back from table." << endl << endl;

	resultHolder = testTable.FindItem("jenessa");
	
	cout << "find item found something" << endl;

	if(resultHolder != nullptr)
	{
		if(resultHolder->GetUserId() == user)
		{
			cout << "Username: " << resultHolder->GetUserId() << endl;
			cout << "Password: " << resultHolder->GetPassword() << endl;
			cout << "TEST PASS." << endl << endl;
		}
	}
	else
	{
		cout << "FAILED TO FIND NODE." << endl << endl;
	}

	cout << "Operation complete : END TEST." << endl;

	return 0;
}

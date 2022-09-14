#include "../UserListGen.hpp"
#include "../Cryptographer.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	string testPassword;
	ifstream testStream;

	cout << "generating userlist" << endl << endl;
	
	UserListGen testList("/home/wds11/COP4534/COP4534-Project-1-Chained-Hash-Table/lastNames.txt");

	testStream.open("/home/wds11/COP4534/COP4534-Project-1-Chained-Hash-Table/raw.txt");
	if(testStream.is_open())
	{
		string fileData;
		while(!testStream.eof())
		{
			getline(testStream,fileData);
			cout << fileData << endl;
		}
		testStream.close();
		cout << "Raw data printed." << endl;
	}
	else
	{
		cout << "ERROR: 'raw.txt' NOT OPENED" << endl << endl;
		testStream.close();
	}
	
	cout << "Generating encrypted list" << endl;
	testList.GenerateEncryptedList();

	cout << "Operation complete." << endl;
	return 0;
}

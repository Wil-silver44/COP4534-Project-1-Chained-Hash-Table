 /***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: mainTest.cpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - mainTest.cpp is the driving code compiling all classes created for the project,
 *   functioning by creating a UserListGenerator Object, generating a list of user's with encrypted passwords,
 *   loading said users and their passwords into a hash table, and finally hasing into the table to compare raw passwords to the stored encrypted versions
 *   to determine whether or not they match.
 *
 ***************************************************************/

#include "Cryptographer.hpp"
#include "Node.hpp"
#include "UserListGen.hpp"
#include "HashTable.hpp"

using std::cout;
using std::endl;

void readIntoTable(string someFile, HashTable someTable);

void tableComparisonOutput(string someRawfile, HashTable SomeTable);

int main()
{
	HashTable testTable;
	UserListGen userTestList("lastNames.txt");
	userTestList.GenerateEncryptedList();
	
	//readIntoTable("encrypted.txt", testTable);

	tableComparisonOutput("raw.txt", testTable);
	
	return 0; 
}

void readIntoTable(string someFile, HashTable someTable)
{
	ifstream fileReader;
	string dataHolder;
	string passHolder;
	string userHolder;
	int delim;

	fileReader.open(someFile);
	if(fileReader.is_open())
	{
		for(int i = 0; i < 5; ++i)
		{
			std::getline(fileReader, dataHolder);
			delim = dataHolder.find_first_of(',');
			userHolder = dataHolder.substr(0, delim - 1);
			passHolder = dataHolder.substr(delim + 1, dataHolder.size() - 1);
			someTable.InsertItem(userHolder, passHolder);
		
		}

		fileReader.close();
		cout << "User Data stored successfully." << endl << endl;
	}

	else
	{
		cout << "ERROR: " << someFile << " COULD NOT BE OPENED." << endl;
	}
}

void tableComparisonOutput(string someRawFile, HashTable someTable)
{
	Cryptographer testCrypto("brodhead");
	Node* tableRef = nullptr;
	ifstream fileReader;
	string dataHolder;
	string passHolder;
	string userHolder;
	int delim;
	
	cout << "Userid Password Attempted Result" << endl << endl;

	fileReader.open(someRawFile);
	if(fileReader.is_open())
	{
		for(int i = 0; i < 5; ++i)
		{
			std::getline(fileReader, dataHolder);
			delim = dataHolder.find_first_of(',');
			userHolder = dataHolder.substr(0, delim - 1);
			passHolder = dataHolder.substr(delim + 1, dataHolder.size() - 1);
			tableRef = someTable.FindItem(userHolder);
		
			if(tableRef->GetPassword() == testCrypto.Encrypt(passHolder))
			{
				cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
					<< testCrypto.Encrypt(passHolder) << " match" << endl << endl;
			}
			else
			{
				cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
					<< testCrypto.Encrypt(passHolder) << " no match" << endl << endl;
			}
		}
		
		fileReader.close();
	}
	else
	{
		cout << "ERROR: " << someRawFile << " COULD NOT BE OPENED." << endl;
		fileReader.close();
	}

}

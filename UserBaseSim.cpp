#include "UserBaseSim.hpp"

//header comment goes here.


UserBaseSim::UserBaseSim()
{
	cout << "Beginning simulation: generating user data..." << endl << endl;
	
	UserListGen testGen(NAME_FILE);
	
	cout << "Data Generated! Encrypting..." << endl << endl;

	testGen.GenerateEncryptedList();

	cout << "Encrypted list generated." << endl;
	cout << "Populating database with sample users..." << endl << endl;

	PopulateDB();
	
	cout << "Test complete." << endl << endl;

	//cout << "Database populated." << endl << endl;

}

void UserBaseSim::PopulateDB()
{
	string lineHolder;
	string userHolder;
	string passHolder;
	int delim;

	fileReader.open("encrypted.txt");
	
	if(fileReader.is_open())
	{
		for(int i = 0; i < 5; ++i)
		{
			getline(fileReader, lineHolder);
			cout << "Line is: " << lineHolder << endl << endl;

			delim = lineHolder.find(',');
			userHolder = lineHolder.substr(0, delim);
			passHolder = lineHolder.substr((delim+1), lineHolder.size());

			userDB.InsertItem(userHolder, passHolder);

			cout << "added to hash table!" << endl;

		}
				
	}

}

void UserBaseSim::CheckDB()
{
	//TODO
}

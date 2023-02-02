#include "UserBaseSim.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: UserBaseSim.cpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - implements defined methods and variables 
 *   for the UserBaseSim class.
 ***************************************************************/

UserBaseSim::UserBaseSim()
{
	cout << "Beginning simulation: generating user data..." << endl << endl;
	
	UserListGen testGen(NAME_FILE);
	
	cout << "Data Generated! Encrypting..." << endl << endl;

	testGen.GenerateEncryptedList();

	cout << "Encrypted list generated." << endl;
	
	cout << "Test complete." << endl << endl;

}

void UserBaseSim::PopulateDB()
{
	string lineHolder;
	string userHolder;
	string passHolder;
	int delim;

	fileReader.open(ENCRYPT_FILE);
	
	if(fileReader.is_open())
	{
		while(getline(fileReader, lineHolder))
		{

			delim = lineHolder.find(',');
			userHolder = lineHolder.substr(0, delim);
			passHolder = lineHolder.substr((delim+1), lineHolder.size());

			userDB.InsertItem(userHolder, passHolder);
		}
		fileReader.close();
	}
	else
	{
		cout << "FAILED TO OPEN FILE " << ENCRYPT_FILE << endl; 
		fileReader.close();
	}
}

void UserBaseSim::CheckDB()
{
	Cryptographer testCrypt(CIPHER_KEY);
	Node* tableRef = nullptr;
	string lineHolder;
        string userHolder;
        string passHolder;
	string encryptedPassHolder;
	int delim;
	
	//legal check
	fileReader.open(CHECK_FILE);
	{
		if(fileReader.is_open())
		{
			cout << "Legal:" << endl;

			for(int i = 0; i < 5; ++i)
			{
				getline(fileReader, lineHolder);
				delim = lineHolder.find(',');
				userHolder = lineHolder.substr(0, delim);
				passHolder = lineHolder.substr((delim+1), lineHolder.size());

				tableRef = userDB.FindItem(userHolder);
				if(tableRef->GetPassword() == testCrypt.Encrypt(passHolder))
				{
					cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
						<< testCrypt.Encrypt(passHolder) << " match" << endl << endl;
				}
				else
				{
					cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
						<< testCrypt.Encrypt(passHolder) << " no match" << endl << endl;
				}
			}

			fileReader.close();
		}
		else
		{
			cout << "FAILED TO OPEN FILE " << CHECK_FILE << endl;
			fileReader.close();
		}
	}

	//double encrypt check
	fileReader.open(CHECK_FILE);
	{
		if(fileReader.is_open())
		{
			cout << "Illegal:" << endl;
			for(int i = 0; i < 5; ++i)
			{
				getline(fileReader, lineHolder);
				delim = lineHolder.find(',');
				userHolder = lineHolder.substr(0, delim);
				passHolder = lineHolder.substr((delim+1), lineHolder.size());
				
				tableRef = userDB.FindItem(userHolder);
				encryptedPassHolder = testCrypt.Encrypt(passHolder);

				if(tableRef->GetPassword() == testCrypt.Encrypt(encryptedPassHolder))
				{
					cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
						<< testCrypt.Encrypt(encryptedPassHolder) << " match" << endl << endl;
				}
				else
				{
					cout << tableRef->GetUserId() << " " << tableRef->GetPassword() << " "
						<< testCrypt.Encrypt(encryptedPassHolder) << " no match" << endl << endl;
				}
			}
			fileReader.close();
		}
		else
		{
			cout << "FAILED TO OPEN FILE " << CHECK_FILE << endl;
			fileReader.close();
		}
	}
}

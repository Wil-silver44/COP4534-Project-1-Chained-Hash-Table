 /***************************************************************
 *      Student Name: Wilver Santos
 *      File Name: UserListGen.cpp
 *      Assignment number: Project 1
 *
 *      Other comments regarding the file - UserListGen.cpp implements the variables and methods 
 *      defined in UserListGen.hpp.
 *
 ***************************************************************/

#include "UserListGen.hpp"

UserListGen::UserListGen(string nameDataFile)
{
	this->dataCryptographer = new Cryptographer("davis");
	
	this->fileReader.open(nameDataFile);
	int delim;
	if(this->fileReader.is_open())
	{
		string nameHolder;
		this->fileWriter.open("/home/wds11/COP4534/COP4534-Project-1-Chained-Hash-Table/raw.txt");
		if(this->fileWriter.is_open())
		{
			for(int i = 0; i < 5; ++i)
			{
				std::getline(this->fileReader, nameHolder);
				delim = nameHolder.find_first_of(' ');
				nameHolder = nameHolder.substr(0, delim);

				nameHolder += "," + RandPasswordGen();
				this->fileWriter << nameHolder << "\n"; 
			}

		fileWriter.close();
		}
		else
		{ 
			std::cout << "ERROR: FAILED TO OPEN FILE: 'raw.txt'" << std::endl;
			this->fileWriter.close();
		}

		this->fileReader.close();
	}
	else
	{
		std::cout << "ERROR: FAILED TO OPEN FILE: 'lastNames.txt'" << std::endl;
		this->fileReader.close();
	}
	
}

void UserListGen::GenerateEncryptedList()
{
	 this->fileReader.open("/home/wds11/COP4534/COP4534-Project-1-Chained-Hash-Table/raw.txt");
	 if(this->fileReader.is_open())
	 {
		this->fileWriter.open("/home/wds11/COP4534/COP4534-Project-1-Chained-Hash-Table/encrypted.txt");
		if(this->fileWriter.is_open())
		{
			string userHolder;
			string passHolder;
			int delim;
			std::cout << "encryption test" << std::endl;
			std::getline(this->fileReader, userHolder);
			delim = userHolder.find_first_of(',');
			std::cout << "line info: " << userHolder << std::endl;
			std::cout << "comma is at index: " << delim << std::endl;
			std::cout << "last letter is at index: " << (userHolder.size() - 1) << std::endl;
			std::cout << "password is: " << userHolder.substr(delim + 1 , userHolder.size() - 1) << std::endl;
			std::cout << "attempting to encrypt: " << this->dataCryptographer->Encrypt(userHolder.substr(delim + 1 , userHolder.size() - 1)) << std::endl;

			
			
			/*for(int i = 0; i < 5; ++i)
			{
				std::getline(this->fileReader, userHolder);
				delim = userHolder.find_first_of(',');
				passHolder = userHolder.substr(delim + 1 , userHolder.size() - 1);
				this->fileWriter << userHolder.substr(0,delim) << ',' << this->dataCryptographer->Encrypt(passHolder) << std::endl;

			} */

			this->fileWriter.close();
		}
		else
		{
			std::cout << "ERROR: FAILED TO OPEN FILE: 'encrypted.txt'" << std::endl;
			this->fileWriter.close();
		}
		this->fileReader.close();
	 }
	 else
	 {
		std::cout << "ERROR: FAILED TO OPEN FILE: 'raw.txt'" << std::endl;
		this->fileReader.close();
	 }
}

string UserListGen::RandPasswordGen()
{
	std::random_device rand; //generates seed for random num generator
	std::mt19937 gen(rand()); //Standard mersenne twister engine seeded with the above random device.
	std::uniform_int_distribution<> distribute(97, 122); //generates random ints uniformly distributed along a closed range.

	int someNum;
	char passChar;
	string rawPassword;

	for(int i = 0; i < 9; ++i)
	{
		someNum = distribute(gen);
		passChar = someNum;
		rawPassword += passChar;
	}

	return rawPassword;
}

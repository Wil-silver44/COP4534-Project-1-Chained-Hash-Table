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
	dataCryptographer = new Cryptographer(CIPHER_KEY);
	
	fileReader.open(nameDataFile);
	int delim;
	if(fileReader.is_open())
	{
		string nameHolder;
		fileWriter.open("raw.txt");
		if(fileWriter.is_open())
		{
			while(fileReader.good())
			{
				std::getline(fileReader, nameHolder);
				if(fileReader.eof())
				{ break; }
				
				else
				{
					delim = nameHolder.find_first_of(' ');
					nameHolder = nameHolder.substr(0, delim);

					nameHolder += "," + RandPasswordGen();
					this->fileWriter << nameHolder << "\n";
				}	
			}

		fileWriter.close();
		}
		else
		{ 
			std::cout << "ERROR: FAILED TO OPEN FILE: 'raw.txt'" << std::endl;
			fileWriter.close();
		}

		fileReader.close();
	}
	else
	{
		std::cout << "ERROR: FAILED TO OPEN FILE: 'lastNames.txt'" << std::endl;
		fileReader.close();
	}
	
}

//takes raw file and generates encrypted file from it.
void UserListGen::GenerateEncryptedList()
{
	 fileReader.open("raw.txt");
	 if(fileReader.is_open())
	 {
		this->fileWriter.open("encrypted.txt");
		if(fileWriter.is_open())
		{
			string userHolder;
			string passHolder;
			int delim;

			while(fileReader.good())
			{
				std::getline(fileReader, userHolder);
				if(fileReader.eof())
				{ break; }
				
				else
				{
					delim = userHolder.find_first_of(',');
					passHolder = userHolder.substr(delim + 1, userHolder.size() - 1);
					fileWriter << userHolder.substr(0,delim) << ',' 
					<< dataCryptographer->Encrypt(passHolder) << std::endl;
				}

			}

			fileWriter.close();
		}
		else
		{
			std::cout << "ERROR: FAILED TO OPEN FILE: 'encrypted.txt'" << std::endl;
			fileWriter.close();
		}
		fileReader.close();
	 }
	 else
	 {
		std::cout << "ERROR: FAILED TO OPEN FILE: 'raw.txt'" << std::endl;
		fileReader.close();
	 }

	 delete dataCryptographer;
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

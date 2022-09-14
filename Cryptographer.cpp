 /***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: Cryptographer.cpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - implements defined methods and variables 
 *   for the cryptographer class.
 ***************************************************************/

#include "Cryptographer.hpp"

Cryptographer::Cryptographer(string key)
{
	this-> key = key;
	this-> keySize = key.size();
	this->alphabet = "abcdefghijklmnopqrstuvwxyz";
}

string Cryptographer::Encrypt(string rawData)
{
	int rawDatSize = rawData.size();
	string encryptedDat;
	char charHolder;

	if(this->keySize >= rawDatSize)
	{
       		for(int i = 0; i < rawDatSize; ++i)
		{
			charHolder = rawData.at(i) + (this->key.at(i) - 'a');
			if(charHolder > 122)
			{
				charHolder =- 26;
			}
			
			encryptedDat += charHolder;
		}


	}
	
	else if(this->keySize < rawDatSize)
	{
		for(int i = 0; i < rawDatSize; ++i)
		{
			charHolder = rawData.at(i) + (this->key.at(i) - 'a');
			if(charHolder > 122)
			{

			}
			encryptedDat += charHolder;
		}
	}
	
	return encryptedDat;
}

string Cryptographer::Decrypt(string encryptedData)
{
	int encryptedDatSize = encryptedData.size();
	string decryptedDat;
	
	if(this->keySize >= encryptedDatSize)
	{
		for(int i = 0; i < encryptedDatSize; ++i)
		{
			 decryptedDat += encryptedData.at(i) - (this->key.at(i) - 'a');
		}
	}

	else if(this->keySize < encryptedDatSize)
	{
		for(int i = 0; i < encryptedDatSize; ++i)
		{
			decryptedDat += encryptedData.at(i) - (this->key.at(i % this->keySize) - 'a');
		}
	}

	return decryptedDat;
}

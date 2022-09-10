 /***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: Cryptographer.cpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - implements defined methods and variables 
 *   for the cryptographer class.
 ***************************************************************/

#include "Cryptographer.hpp"
#include<iostream>
using std::cout;
using std::endl;

Cryptographer::Cryptographer(string key)
{
	this-> key = key;
	this-> keySize = key.size();
	this->alphabet = "abcdefghijklmnopqrstuvwxyz";
}

string Cryptographer::Encrypt(string rawData)
{
	int rawDatSize = rawData.size();
	int charCounter = 0;
	string encryptedDat;
	string cypherAlphabet; 
	int alphaIter; 
	char keyVal;
	
		
	for(int keyIter = 0; charCounter < rawDatSize; ++keyIter)
	{	
		keyVal = this->key.at(keyIter);
		cypherAlphabet.clear();
		
		for(alphaIter = alphabet.find(keyVal); cypherAlphabet.size() != 26; ++alphaIter)
		{
			cypherAlphabet += this->alphabet.at(alphaIter);
		
			if(alphaIter == 25)
			{ alphaIter = -1; }
		}
		cout << cypherAlphabet << " FOR KEY LETTER " << keyVal << endl << endl;

		encryptedDat += cypherAlphabet.at( this->alphabet.find( rawData.at(charCounter) ) );
		++charCounter;		
		if(keyIter == --keySize && cypherAlphabet.size() != 26)
		{ keyIter = 0; }
	}
	
	return encryptedDat;
}

string Cryptographer::Decrypt(string encryptedData)
{
	int encryptDataSize = encryptedData.size();
	int charCounter = 0;
	string decryptedDat;
	string cypherAlphabet;
	int alphaIter;
	char keyVal;
	
	for(int keyIter = 0; charCounter < encryptDataSize; ++keyIter)
	{
		keyVal = this->key.at(keyIter);
		cypherAlphabet.clear();
		for(alphaIter = alphabet.find(keyVal); cypherAlphabet.size() != 26; ++alphaIter)
		{
			cypherAlphabet += this->alphabet.at(alphaIter);

			if(alphaIter == 25)
			{ alphaIter = -1; }
		}
		cout << cypherAlphabet << " FOR KEY LETTER " << keyVal << endl << endl;

		decryptedDat += this->alphabet.at(cypherAlphabet.find( encryptedData.at(charCounter) ) );
		++charCounter;
		if(keyIter == --keySize && cypherAlphabet.size() != 26)
		{ keyIter = 0; }
	}

	return decryptedDat;
}

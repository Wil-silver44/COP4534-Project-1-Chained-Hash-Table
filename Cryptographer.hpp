#ifndef CRYPTOGRAPHER_HPP
#define CRYPTOGRAPHER_HPP

 /***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: Cryptographer.hpp
 *   Assignment number: Project 1
 *
 *   Other comments regarding the file - Cryptographer.hpp defines the variables and methods
 *   used for encryption and decryption by the Vigenere Cipher.
 *         
 ***************************************************************/

#include<string>

using std::string;

class Cryptographer
{
	private:
	string key;
	int keySize;
	const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
	
	public:
	Cryptographer(string key);
	string Encrypt(string rawData);
	string Decrypt(string EncryptedData);
};

#endif

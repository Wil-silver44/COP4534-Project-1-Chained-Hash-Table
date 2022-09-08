#include "Cryptographer.hpp"
#include<iostream>

using std::cout;
using std::endl;

int main()
{
	cout << "creating Cryptographer object with key jones." << endl << endl;

	Cryptographer testCrypter("jones");

	cout << "operation complete." << endl;

	string rawWord = "data";
	string encryptedWord;

	encryptedWord = testCrypter.Encrypt(rawWord);

	if(encryptedWord == "moge")
	{ cout << "TEST PASSED." << endl << endl;  }
	else
	{ cout << "TEST FAILED\nPRINTING OUTPUT: " << encryptedWord << endl << endl; }

	cout << "decrypting previously encrypted data." << endl;

	string decryptedWord;

	decryptedWord = testCrypter.Decrypt(encryptedWord);

	if(decryptedWord == "data")
	{ cout << "TEST PASSED." << endl << endl; }
	else
	{ cout << "TEST FAILED\nPRINTING OUTPUT: " << decryptedWord << endl << endl; }

	return 0;
}

#include "Cryptographer.hpp"

Cryptographer::Cryptographer(string key)
{
	this->key = key;
}

string Cryptographer::Encrypt(string rawData)
{
	return rawData; //fix later, just for makefile testing.
}

string Cryptographer::Decrypt(string encryptedData)
{
	return encryptedData; //fix later, just for makefile testing.
}

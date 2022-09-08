#ifndef CRYPTOGRAPHER_HPP
#define CRYPTOGRAPHER_HPP

#include<string>

using std::string;

class Cryptographer
{
	private:
	string key;
	const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public:
	Cryptographer(string key);
	string Encrypt(string rawData);
	string Decrypt(string EncryptedData);
};

#endif

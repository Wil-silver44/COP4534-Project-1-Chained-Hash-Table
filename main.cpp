#include "UserBaseSim.hpp"

//header comment goes here


int main()
{
	cout << "Beginning Operations." << endl;

	UserBaseSim TestSim;

	cout << "Class instance created." << endl;

	cout << "Populating database with sample users..." << endl << endl;

	TestSim.PopulateDB();

	TestSim.CheckDB();

	cout << "Operations complete" << endl;
	
	return 0;
}

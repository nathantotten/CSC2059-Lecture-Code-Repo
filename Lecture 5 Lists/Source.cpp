#include "List.h"	//Include the list class so that we can isntantiate a list
#include <iostream>	// IO class
#include <string>	// System class for string class and functionality
#include <fstream> //System class for file IO

using namespace std;

int main()
{
	List<string> clist;

	string item;
	ifstream fin("corpus.txt");

	while (fin >> item) {
		clist.insert_end(item);
	}

	cin >> item;

	return 0;
}
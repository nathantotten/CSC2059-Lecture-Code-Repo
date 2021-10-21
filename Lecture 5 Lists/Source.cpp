#include "List.h"	//Include the list class so that we can isntantiate a list
#include <iostream>	// IO class
#include <string>	// System class for string class and functionality
#include <fstream> //System class for file IO

using namespace std;

template<typename T>
int coutFreq(List<T> linkedList, T key)
{
	int count = 0;
}

int main()
{
	List<string> clist;

	string item;
	ifstream fin("corpus.txt");

	while (fin >> item) {
		clist.insert_end(item);
	}
	fin.close();
	
	cout << clist.size() << endl;


	return 0;
}
#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class WordList
{
private:
	ifstream refList;
	string refLine;
	int listCount = 0;

	int selected;
	int readCount; 
	 


public:

	WordList(); 

	string key;

	void GetCount();

	void SetKey();

	bool CheckList(string str); 
};


#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class WordList // feedback: while I see the thought behind the naming this class like this, the only data in fact that it manages is
			   // a "key" string, the picked random word from the file. Class name should represent what data class manages, for example
			   // TargetWordPicker. By looking at the current class name I expected to see an actual list of the words, which is not what
			   // this class is doing.
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


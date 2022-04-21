#include "WordList.h"

WordList::WordList()
{
	GetCount();
	SetKey(); 
}

void WordList::GetCount()
{
	if(!refList.is_open()) refList.open("words.txt");

	if (refList.is_open())
	{
		while (getline(refList, refLine))
		{
			listCount++;
		}
	}

	else cout << "Reference List Not Found" << endl;


	refList.close(); 
}

void WordList::SetKey()
{
	// feedback: this function depends on result of GetCount to work properly. This is not obvious and there is no check for listCount being set
	// Meaning that just calling this function(without calling GetCount first) will produce an error. Moreover, storage file is opened and read
	// twice in these 2 functions which is questionable from performance point of view.
	// I'd rather combine these 2 functions in one, read the contents of a file to memory, and pick a random word from memory instead
	srand(time(0));

	selected = rand() % listCount;

	if (!refList.is_open()) refList.open("words.txt");

	if (refList.is_open())
	{
		while (getline(refList, refLine))
		{
			readCount++;

			if (readCount == selected)
			{
				key = refLine;
			}

		}
		
	}

	else cout << "Reference List Not Found" << endl;

	readCount = 0; 
	refList.close();
}

bool WordList::CheckList(string str)
{
	if (!refList.is_open()) refList.open("words.txt");
	// feedback: here you open and read the file once again, which is relatively expensive operation.
	// I think this is another possible place for optimization suggested above.

	if (refList.is_open())
	{
		while (getline(refList, refLine))
		{
			
			if (refLine.find(str) != string::npos)
			{
				refList.close();
				return true;
				
			}

		}
	}
	refList.close();
	return false; 
}


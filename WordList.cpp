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


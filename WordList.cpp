#include "WordList.h"

WordList::WordList()
{
	GetCount();
	SetKey(); 
}

void WordList::GetCount()
{
	refList.open("words.txt");

	if (refList.is_open())
	{
		while (getline(refList, refLine))
		{
			listCount++;
		}
	}

	else cout << "Reference List Not Found" << endl;

	cout << listCount << " lines in Total" << endl;

	refList.close(); 
}

void WordList::SetKey()
{
	srand(time(0));

	selected = rand() % listCount;

	refList.open("words.txt");

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

	cout << "Selected line is " << selected << " : " << key << endl;

}


#include "Guess.h"

bool Guess::isValid(string str)
{
	
}


void Guess::GetInput()
{
	cout << "You have " << chances << " chance left. Make your guess. ";
	cin >> input;

	if (input.length() > 5 || input.length() < 5) cout << "Invalid Word. Please ensure your guess is a valid 5 letter word. \n";

	for (int i = 0; i < 5; i++)
	{
		input[i] = toupper(input[i]);
	}

	if (wordList.CheckList(input) && isValid(input))
	{
		chances--; 
		CheckInput(input);
	}
	
}



void Guess::CheckInput(string str)
{
	if (input == wordList.key)
	{
		cout << BACKGROUND(BackgroundColor::Green, input) << endl;
		cout << endl;
		cout << "Hurrah! You guessed the word in " << 6 - chances << " tries !" << endl;

	}

	else
	{
		for (int i = 0; i < 5; i++)
		{
			if (input[i] == wordList.key[i])
			{

				cout << BACKGROUND(BackgroundColor::Green, input[i]);
			}

			else cout << input[i];
		}
		cout << endl;
	}
}

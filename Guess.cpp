#include "Guess.h"

void Guess::GetInput()
{
	cout << endl; 
	cout << "You have " << chances << " chances left. Make your guess : ";
	std::cin >> input;

	for (int i = 0; i < 5; i++)
	{
		input[i] = toupper(input[i]);
	}

	isValid(input); 
}

void Guess::isValid(string str)
{
	if (input.length() > 5 || input.length() < 5 ) {
		cout << "Invalid Word. Please ensure your guess is a valid 5 letter word. \n" ;
		GetInput(); 
	}

	else if (!wordList.CheckList(str))
	{
		cout << "Invalid Word. The word " << FOREGROUND(ForegroundColor::Red, str) << " does not exist in the dictionary. \n";
		GetInput();
	}

	else 
	{
		chances--;
		CheckInput(str);
	}
}

void Guess::CheckInput(string str)
{
	if (input == wordList.key)
	{
		cout << BACKGROUND(BackgroundColor::Green, FOREGROUND(ForegroundColor::Black, input)) << endl;
		cout << endl;
		cout << "Hurrah! You guessed the word in " << 6 - chances << " tries ! ";
		Restart(); 
	}

	else
	{
		string temp = wordList.key;
		int count = 0; 

		for (int i = 0; i < 5; i++)
		{
			if (input[i] == wordList.key[i])
			{
				cout << BACKGROUND(BackgroundColor::Green, FOREGROUND(ForegroundColor::Black, input[i]));
				temp[i] = '0';
				count++; 
			}

			else if (wordList.key.find(input[i]) == string::npos)
			{
				cout << BACKGROUND(BackgroundColor::Grey, FOREGROUND(ForegroundColor::Black, input[i]));
			}

			else if (temp.find(input[i]) != string::npos)
			{
				cout << BACKGROUND(BackgroundColor::Yellow, FOREGROUND(ForegroundColor::Black, input[i]));
				for (int x = 0; x < 5; x++)
				{
					
					if  (input[i] == temp[x] && count == 0)
					{
						temp[i] = '0';
						count++; 
					}
				}
			}

		}
		cout << " " << endl;

		if (chances > 0) GetInput();
		else cout << "The correct answer was '" << wordList.key << "' . ";
		Restart(); 
		
	}
		
}

void Guess::Restart()
{
	cout << "Would you like to play again? Y / N : ";
	std::cin >> repeat;

	if (repeat == "Y" || repeat == "y")
	{
		cout << endl << "Selecting new Secret Word ... \n" << endl;
		chances = 6;
		wordList.SetKey();
		GetInput();
	}

	else cout << "See You Next Time!"; 
}



#include "Guess.h"

void Guess::GetInput()
{
	cout << endl; 
	cout << "You have " << chances << " chances left. Make your guess : ";
	std::getline(cin, input);
	for (int i = 0; i < input.length(); i++)
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
		string test = input; 
		int bgcolors[6];
		int fgcolors[6]; 


		for (int i = 0; i < 5 ; i++)
		{
			if (input[i] == wordList.key[i])
			{
				temp[i] = '*';
				test[i] = '0'; 
				bgcolors[i] = (int)BackgroundColor::Green;
				fgcolors[i] = (int)ForegroundColor::Black;
			}



		}

		for (int i = 0; i < 6; i++)
		{

			if (temp.find(test[i]) != string::npos)
			{
				for (int x = 0; x < 6; x++)
				{
					if (test[i] == temp[x])
					{
						temp[x] = '*';
						test[x] = '0';
					}

				}

				bgcolors[i] = (int)BackgroundColor::Yellow;
				fgcolors[i] = (int)ForegroundColor::Black;
			}

			

		}

		for (int i = 0; i < 6; i++)
		{
			cout << BACKGROUND(bgcolors[i], FOREGROUND(fgcolors[i], input[i])); 
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



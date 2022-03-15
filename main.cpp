#include <iostream>
#include <cstdlib>
#include <string>

#include "WordList.h"


using namespace std;

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
    Red = 31,
    Green = 32,
    Yellow = 33,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93
};

enum class BackgroundColor : int {
    Red = 41,
    Green = 42,
    Yellow = 43,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103
};

int main()
{
    srand(time(0));

    cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
    cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;

	WordList wordList;
    
    wordList.GetCount();

    wordList.SetKey(); 

    char input[5];
    char upperInput[5]; 
    int chances = 6;
    bool correct = false;

    string repeat; 

    cout << "You have " << chances << " chances left. Enter your guess. \n";
    cin >> input;

    for(int i = 0; i < strlen(input); i++)
    {
        upperInput[i] = toupper(input[i]); 
    }


    if (upperInput == wordList.key)
    {
        correct = true;

        for (int i = 0; i < 5; i++)
        {
            cout << BACKGROUND(BackgroundColor::Green, upperInput);
        }

        cout << endl;
        cout << "Hurra! You guessed the word in " << 7 - chances << " tries !" << endl;
        
    }

    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (upperInput[i] == wordList.key[i])
            {

                cout << BACKGROUND(BackgroundColor::Green, upperInput[i]);
            }

            else cout << upperInput[i];
        }
        cout << endl;
    }

    

    return 0; 
}
    
    

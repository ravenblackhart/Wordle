#pragma once
#include "WordList.h"

using namespace std; 

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
	Black =30,
	Red = 31,
    Green = 32,
    Yellow = 33
};

enum class BackgroundColor : int {
    Red = 41,
    Green = 42,
    Yellow = 43,
    Grey = 100
};

class Guess
{
private:

	string input;
	int chances = 6;

	string repeat; 

	
public:
    WordList wordList;

    void isValid(string str);  // feedback: string arguments could be references to avoid copying.
	void GetInput();
	void CheckInput(string str); 
	void Restart();
};


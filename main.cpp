#include <iostream>
#include <cstdlib>
#include <string>

#include "WordList.h"
#include "Guess.h"

using namespace std;


int main()
{

    Guess guess;
    cout << FOREGROUND(ForegroundColor::Yellow, "GUESS THE WORD FROM KRISTER'S WORDLIST") << endl << endl; 
    cout << "Welcome! This game is a twist on the super-popular internet sensation " <<
        BACKGROUND(BackgroundColor::Red, FOREGROUND(ForegroundColor::Black, "W")) <<
        BACKGROUND(BackgroundColor::Green, FOREGROUND(ForegroundColor::Black, "O")) <<
        FOREGROUND(ForegroundColor::Green, "R") <<
        BACKGROUND(BackgroundColor::Yellow, FOREGROUND(ForegroundColor::Black, "D")) <<
        FOREGROUND(ForegroundColor::Red, "L") <<
        FOREGROUND(ForegroundColor::Yellow, "E") <<
        " where you will have to guess a secret 5 letter word each day in 6 tries. \n" << endl <<
        "In this version, however, the reference dictionary is a word list provided by Krister; Not all the words you expect to be in the list will be there. Not all the words in this list are actual words either. \n" << endl <<
        "Other than the words, the usual rules of WORDLE apply : \n" <<
        "For every guess that is not the right answer, each letter will be marked with an indicator. \n" <<
        "- Letters not in the word are marked with a " << BACKGROUND(BackgroundColor::Grey, FOREGROUND(ForegroundColor::Black, "GREY BACKGROUND")) << ". \n" <<
        "- Letters in the word but are in the wrong positions are marked with a " << BACKGROUND(BackgroundColor::Yellow, FOREGROUND(ForegroundColor::Black, "YELLOW BACKGROUND")) << ". \n" <<
        "- Letters in the word AND are in the right positions are marked with a " << BACKGROUND(BackgroundColor::Green, FOREGROUND(ForegroundColor::Black, "GREEN BACKGROUND")) << ". \n" << endl;

        cout <<"Setting the Secret Word...\n" << endl; 
    	
    guess.GetInput(); 
     

    

    return 0; 
}
    
    

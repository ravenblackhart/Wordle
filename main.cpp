#include <iostream>
#include <cstdlib>
#include <string>

#include "WordList.h"
#include "Guess.h"

using namespace std;


int main()
{
    cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
    cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;

    Guess guess; 
   

    string repeat; 

    guess.GetInput(); 
    
    
   




    

    

    return 0; 
}
    
    

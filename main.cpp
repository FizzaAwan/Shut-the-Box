//Shut the b0x
#include <cmath>       
#include <cstdlib>
#include <ctime>       // for srand
#include "shutbox.h"   //header file
#include <iostream>   
#include <string>     // for strings
using namespace std; 

int main(){
srand(time(0));        //intializing the time for rand() to use; 

Box b;                 // creating varaible b from class Box,  
char first, second, third;    // first tile, second, and third tile varaibles are all characters
int exit;                     // varaible for inner do while loop, declared outside the loops. 

do{                                    // do while loop for each turn
cout << "\nBox:  " << b.str() <<endl; //outputs the called string function, a member of the box class, displays the numbers of in the box. 
Dice d;                            //creates varaibles for class Dice. 
if (b.score() <= 12)              // b.score is the score function from the box class, if the 
  d.n_dice = 1;                   //       totol of the move is less than one, the dice class                                    changes the number of dices to be part of the dice collection. 
d.roll();                              // rolls the dice. 
cout << "Dice: " << d.str() <<endl;    //using Dice class's string function to output the dice. 

do{                    //inner do while loop allows the program to promt the user to 
exit=0;                //         input more tiles if the orginal input was invalid 
cout << "Tiles: " ;    //         using the exit variable for post testing. 
cin >> first;          //promts for input to the first tile.
cin.ignore(1000,' ');  //ignores the spaces so the first, second, third dont become spaces. 
cin >>second; 
cin.ignore(1000,' ');
cin >> third; 


if (first+second+third != 144){     // 144 is logically equivalent to the ascii values of the                                               characters 0+0+0, essentially if the input arent all zeros,                                          the program executes the statements below 
  if (((first+second+third)-144) != (d.total())) { //if the [char]tiles dont add up to the [int]dice. 
    cout << "Invalid entry!" <<endl;               // outputs invalid entry
    exit= 1;}                                      // makes exit become 1. 
  else if (b.close(first, second, third) != 1){   //otherwise validates tile input using the Box class close function
             cout << "Invalid entry!"<< endl;     // if the function returns false, output invalid entry
             exit=1;}                             // exit becomes one. 
} 
}while(exit ==1);                                 // if exit is 1, an invalid entry occured, and inner loop repeats. 
}while ( first+second+third != 144);              // is the inputs are all zero, no more turns, and the game ends. 

if( first+second+third == 144)                    //if tiles are all zero, no more turns, the game ends
  cout << "Score:  " << b.score()<< endl;         // the score is output usig the Box class's score funtion. 

return 0; 
}

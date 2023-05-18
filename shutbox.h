#pragma once           // top of header file 

#include <string>      // for string functions
using namespace std; 

class Dice{             //rolling the dice
private :   
  int dice[6];         //object represents the dice itself 
  
public :
  int n_dice;          // number of dice in collection 
  Dice ();             // constructor
  Dice(int n);         // constructor changes number of dice 
  void roll();         // rolls the dice
  void roll(int index); // roll specific die. 
  
  int total() const;             //adds the value of dice rolled up, doesnt change the dice, hence const
  int die( int index) const;     // returns value of specific die rolled. doesnt change the number. 
  int count (int value) const;   
  std::string str () const;     // turns rolled values into strings. 

}; 

class Box {       // box class represents the box in the game. 
  private:
    char box[9] = {'1','2','3','4','5','6','7','8','9'} ;   //creates a character array that defines the box.
  public: 
    Box();              // constructor

    bool close (int first, int second, int third);    // validates unputted tiles, closes the number if its true 
    int score() const;                                //give score of game
    std::string str() const ;                         // makes the box array into a string to output. 
};
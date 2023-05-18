#include "shutbox.h"
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <string> 
#include <ctype.h>

using namespace std; 

Dice::Dice () {
  n_dice= 2;               //constructor sets the dice to 2. 
  dice[0]= rand()%6 +1;    // each dice uses randomly picks a number from 1 to 6. 
  dice[1]= rand()%6 +1; 
}

Dice::Dice (int n){             // constructor changes number of dice. 
  n_dice=n;                         // input becomes a variable for the for loop. 
  for( int i=0; i<n_dice; i++)      //each of the dice get random numbers. 
    dice[i]= rand()%6+1; 
}

int Dice::total() const{            // adds the dice up, doesnt change the dice, therefore const
  int sum=0;                        // creates sum to represent total. 
  for (int i=0; i<n_dice; i++){     // the value of each die is added till the loop ends when it does all the dice. 
    sum=sum+dice[i]; 
  }
  return sum; 
}

int Dice::count (int value) const{   
  int cnt =0;                       //creates a for loop to evaluate all the dice and see which one has 
   for(int i=0; i< n_dice; i++ ){   //      the specific value that was equal to the int value varaible. 
     if (dice[i]==value)
      cnt++; 
  }
  return cnt; 
} 

int Dice::die (int index) const{      //returns the value of one die. 
  return dice[index]; 
}

void Dice::roll (){                  // rolls the die using a for loop for
  for (int i=0; i<n_dice; i++){       //randomizing each of die. 
      dice[i]= rand()%6+1; 
  }
}

string Dice:: str() const{                //creates a string of the box                              
  string s;                               //creates string variable 
  for (int i=0; i < n_dice ; i++){       //uses a for loop to add values of each dive. 
   if (i>0)
    s = s + "-";                         // space inbetween values
  s += to_string(dice[i]); }            //uses to string function for each int die value. 
return s;                                //returns string to caller.
}

Box::Box(){                         //box class contrsuctor 
}

bool Box::close (int first, int second, int third){    //inout validation and closing the numbers in the box. 

  if(first<48 || first>57)
    return false; 
  if(second<48 || second>57)    // input each tile input to be between 1 and 9, using ascii values since tiles are                                         characters
    return false; 
  if(third<48 || third>57)
    return false;               //if the tiles aren't between one and 9, the close functino returns false 

   if (box[first-49]=='*')
    return false; 
   if(box[second-49]=='*')     // if the user inputs a tiles that already is down in the box and has astrick, 
    return false;               //       the function returns a false. 
   if(box[third-49]=='*')
    return false; 
  
  if(third==second && third!='0')      // if statements to validate the tile inputs dont repeat, except for zeros. 
    return false;                      // returns false if the inputs are repeated ( a 3 3 0 would be false). 
  if(third==first && third!='0')
    return false;
  if(second==first && second!='0')
    return false;
  if(second==third && second!='0')
    return false;
  if(first==second && first!='0')
    return false;
  if(first==third && first!='0')
    return false;
  

for(int i=0; i<9; i++){                //for loop that actually closes the corresponding number in the box. 
  if (first!='0' && box[i]==first){    
    box[i]='*';}    ////goes through box array and the character matching the validated input tile gets an astrick. 
  }
for(int i=0; i<9; i++){  
  if (second!='0' && box[i]==second){   // repeats another loop for second tile 
    box[i]='*';}
  }
for(int i=0; i<9; i++){     
  if (third!='0' && box[i]==third){    // loop for third tile
    box[i]='*';}
  }

return true;         // if the input tilea are valid and the box's corresponding numbers are closed, returns true. 
}

int Box::score()const {       //scores the game, doesnt change the box, hence const 
  int score=0;                  //varaible to keep score. 
  for (int i=0; i< 9; i++){    // for loop that adds the value of the numbers still up in the box, not astrick 
    if (box[i] != '*'){  
      score+=(box[i]-48);}  // since the box is a character array, 48 is 0 in ascii, must be scaled for the int score. 
    }
return score;             //retusn the score of the box to caller. 
}

std:: string Box::str() const {   // string output of the box character array. 
  std::string s;                  //creates varaible for string array. 
  for (int i=0; i<9 ; i++){       // for loop to go through array
    if (i>0)                        
      s+= " ";                     //creates spaces, only after the first loop. 
    if(box[i] == '*')               // if the arryay has astrick character, adds an astrick to the string 
      s+= "*"; 
    if(box[i] != '*')              // if the array has number charcter, not an astrick, add its to string, 
      s+= to_string(box[i]-48);       //used to string functino to turn into string, and inside turns the box array's                                     charcter at that index an int, sclaed using 48 ['0'=48 in ascii]
  }
return s;                         //returns string to caller. 
}
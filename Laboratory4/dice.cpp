/**
    dice.cpp
    CMPT 275 Laboratory 4
    Purpose: This lab will break down the dicegame program into different functions
    and enable the dynamic selection of the rules.

    Marcelo Napoleao Sampaio
    31/10/2019
*/

#include "dice.h"
#include<iostream>
#include<iomanip>

using namespace std;

// This function rolls and returns a die, using a rand function and a value given
// to it in the start of the program as the parameter "diceSides" that dynamically
// selects the number of sides on the die.
int rollDie(unsigned int diceSides){
  return (rand() % diceSides) + 1;
}


// This function seeds the rand function using a paramater given to it when the
// program is called (randomSeed). If no value is passed to this parameter, the
// program generates a random seeding number instead.
void initializeRNG(int randomSeed){
  srand(randomSeed);
}


// This function displays the rules that the game will be following, using the values
// given to its different parameters when the program was called.
void printRules(unsigned int diceSides,int startingMoney,int winValue,unsigned int maxRolls,int randomSeed){
  const int WIDTH = 17;
  cout << "+- RULES --------------------------+" << endl;
  cout << "|   sides per die" << setw(WIDTH) << diceSides << right <<"  |" << endl;
  cout << "|   starting $   " << setw(WIDTH) << startingMoney << right <<"  |" << endl;
  cout << "|   maximum $    " << setw(WIDTH) << winValue << right <<"  |" << endl;
  cout << "|   maximum rolls" << setw(WIDTH) << maxRolls << right <<"  |" << endl;
  cout << "|   random seed  " << setw(WIDTH) << randomSeed << right <<"  |" << endl;
  cout << "+----------------------------------+" << endl;
}


// This function displays the header of each step of the game, containing the turn
// as well as the current situation of the player's money (parameter startingMoney).
void printHeader(int startingMoney, int rollCount){
  const int FILLWIDTH = 36;
  cout << "Roll # " << rollCount << endl;
  cout << "" << setfill('-') << setw(FILLWIDTH) << "" << endl ;
  cout << "  Player's money: $" << startingMoney << endl;
}


// This function rolls the first die and the following ones according to it, while
// recording the values of each roll to an array, displaying them and adding them
// up, then returning the value of the sum of all the dice rolled. It needs the
// parameter "diceSides" because it calls the function "rollDie", which needs
// that paramater to know how many sides the dice has.
int roll_n_print_dice(unsigned int diceSides){
   int sum, FirstRoll, i ;
   sum = 0;
   int OtherRolls[FirstRoll];
   FirstRoll = rollDie(diceSides);
  cout << "  Die Roll: " << FirstRoll << endl;
  cout << "  Dice rolls: " ;
  for(i = 0 ; i < FirstRoll ; ++i){
    OtherRolls[i] = rollDie(diceSides);
    sum += OtherRolls[i];
    cout << OtherRolls[i] << " ";
    }
    cout << endl;
    return sum ;
}


// This function will print the result of the sum and test whether the Player
// gained or lost money. The function will record the original value of the sum
// to a new variable, which will then be changed to negative in case it is even.
// The function then returns the modified (or not) variable but prints the original
// sum value without the negative sign.
int get_n_print_Result(int sum, int startingMoney){
  int totalSum = sum;
  string GainOrLoss;
  if(totalSum % 2 == 0){
    totalSum *= -1;
    GainOrLoss = "Lost";
  } else{
    GainOrLoss = "Gained";
  }
  cout << "  sum: " << sum<< endl;
  cout << "  Result: " << GainOrLoss << " $" << sum << endl;
  cout << endl;
  return totalSum ;
}


// This function will, after the game is done, print out a message with the Result
// based on whether the player reached the maximum money, the maximum rolls or
// lost all their money.
void printFinalMessage(int startingMoney, unsigned int maxRolls, int rollCount, int winValue){
  if(startingMoney >= winValue){
    cout << "+++++ You Won! Congratulations +++++" << endl;
  }else if (rollCount >= maxRolls){
    cout << "------ Sorry -- No Rolls Left ------" << endl;
  }else {
    cout << "------- I'm Sorry, You Lost! -------" << endl;
  }
}

// This function will be responsible for testing whether the game has finished
// and the program should exit the while loop. It will test the conditions needed
// for the game to keep running and return a false value while this is the case,
// and will return a true value once the conditions are not true anymore, meaning
// that the game is in fact over. This function will be places in the conditional
// statement of the do ... while loop, which will test if the function is returning
// a true or false value. Once a true value is returned the loop will terminate.
bool gameOver(int startingMoney, int winValue, int rollCount, unsigned int maxRolls, const int LOSEVALUE){

   if((startingMoney > LOSEVALUE) && (startingMoney < winValue) && (rollCount <= maxRolls)){
   return false;
 } else {
   return true;
  }
 }

// This function will orchestrate the game using the other functions in the right
// order and place, and taking all the necessary parameters that it and the other fucnctions
// need.
void playGame(unsigned int diceSides,int startingMoney,int winValue,unsigned int maxRolls,int randomSeed) {
// Calling the function to seed the rand function.
initializeRNG(randomSeed);
// Calling the function to print the game rules.
printRules(diceSides, startingMoney, winValue, maxRolls, randomSeed);
// Both of the previous functions were called outside the do ... while loop because
// they shouldn't be repeated again throughout the game.

// Declaring a variable to count the turns and a constant for the lose value which
// which will be used when testing if the game is over and if the player lost.
 int rollCount = 1;
 const int LOSEVALUE = 0;

 // Using a do ... while loop to keep the game going as long as the function
 // gameOver does not return a true value.
 do {
   printHeader(startingMoney, rollCount); // Printing header at the beginning of each iteration.
   ++rollCount;// Counting the turns that go by.
   // To change the startingMoney, we add what the get_n_print_Result function returns
   // which will be a negative value in case the player is supposed to lose money.
   // To call the get_n_print_Result function, the "sum" parameter is being passed
   // by calling the roll_n_print_dice function, which returns the sum value.
   // By doing this, the functions display what they need to display in the right
   // order, at the same time that we use the values they are returning in the right
   // places.
   startingMoney += get_n_print_Result(roll_n_print_dice(diceSides), startingMoney);
}while(gameOver(startingMoney, winValue, rollCount, maxRolls, LOSEVALUE) != true);// testing if the gameOver function returns a true value, which will end the game.
   printFinalMessage(startingMoney, maxRolls, rollCount, winValue); // displaying the final message with the resut
 }

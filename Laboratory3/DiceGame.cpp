/*Marcelo Napoleao Sampaio
CMPT275
Lab3 DiceGame
This program will execute a dice game where the player starts with $100, rolls a Die
then rolls dice according to the result of the first roll, adds up those results,
and if they add up to an even number, that value is subtracted from the player's
starting money, and if it is odd, it is added to it, until the player either doubles
his/her money, or loses all of it.
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;
//Creating a function that returns the roll of a 6 sided die
int DieRoll(){
  const int DICESIDES = 6;
  return (rand() % DICESIDES) + 1;
}
//creating the DiceGame Function
void DiceGame(){
// Allocating memory space for my variables, declaring my constants and seeding the rand function
  int RollCount = 0;
  int sum, FirstRoll, i ;
  int PlayerMoney = 100;
  const int LOSEVALUE = 0;
  const int WINVALUE = PlayerMoney * 2;
  const int FILLWIDTH = 36;
  unsigned int seed = time(0);

  srand(seed);

//Creating a while loop to keep the game going untill one of the conditions have been met
  while((PlayerMoney > LOSEVALUE) && (PlayerMoney < WINVALUE)) {
    ++RollCount;    //Counting the turns
    i = 0;
    sum = 0;
    FirstRoll = DieRoll();
//Creating an array to store the rolls and allow me to use them
    int OtherRolls[FirstRoll];
    string GainOrLoss;
//Displaying the progress of the game
    cout << "Roll # " << RollCount << endl;
    cout << "" << setfill('-') << setw(FILLWIDTH) << "" << endl ;
    cout << "  Player's money: $" << PlayerMoney << endl;
    cout << "  Die Roll: " << FirstRoll << endl;
    cout << "  Dice rolls: " ;
//Creating a loop to roll the dice an amount of times equal to the first dieroll, store the rolls into an array the size of the first roll,
//and display the rolls
    for( ; i < FirstRoll ; ++i){
      OtherRolls[i] = DieRoll();
      sum += OtherRolls[i];
      cout << OtherRolls[i] << " ";
      }
//Creating a conditional statement to test if the sum is even, in which case it will subtract from the Player's PlayerMoney
//and display "lost", or if it's odd, it will add it to the player's money and display "gained".
//The displaying of the word lost or gained is being done by changing a string variable that is being outputed.
            if(sum % 2 == 0){
              PlayerMoney -= sum;
              GainOrLoss = "Lost";
            } else{
              PlayerMoney += sum;
              GainOrLoss = "Gained";
            }
//Displaying the remainder of the data
    cout << endl;
    cout << "  sum: " << sum << endl;
    cout << "  Result: " << GainOrLoss << " $" << sum << endl;
    cout << endl;
  }
//Creating a conditional statement to test if the player won or lost, and displaying the result
    if(PlayerMoney >= WINVALUE){
      cout << "+++++ You Won! Congratulations +++++" << endl;
    }else{
      cout << "------- I'm Sorry, You Lost! -------" << endl;
    }

}

int main() {
//calling the dicegame function in my main function.
    DiceGame();
  return 0;
}

/**
    bigInt.cpp
    CMPT 275 Laboratory 5
    Purpose: Recording two positive integers of at most 30 digits, printing them
    and their sum, as well as testing if the inputs are appropriate and displaying
    appropriate warning messages in case they aren't.

    @Marcelo Napoleao Sampaio
    @15/11/2019
*/
#include "bigInt.h"
using namespace CMPT275;
using namespace std;


//This function returns a string representation for a given big integer(bigInt)
std::string BigInt::toString(const digit bigInt[]) {
  //Recording the max size value and allocating memory space for other variables
  //that will be used in the function
  int maxlength = BigInt::MAX_SIZE;
  string outputString = "";
  int i = 0;
  int j = 0;
  int pos = maxlength - 1;
  //Finding where the numbers in the array start and recording the position to
  //variable j so that we can skip the zeros and only add the numbers into the string
  //that will be returned.
  for(;i <= maxlength; i++){
    if(bigInt[i] != 0){
      break;
    }
    if(i == pos){
      return "0";
    }
  }
  //Converting the numbers in the array into charachters and adding them to the
  //outputString variable which is recording our big integer as a string to be returned.
  for(j = i; j < maxlength ; j++){
    char C = bigInt[j] + '0'; //This line converts the numbers into charachters
    outputString += C;        //by changing them to the respective ascii value.
                              //then adds them to the string.

    //Adding commas between every 3 digts.
    if((pos - j) % 3 == 0 && j != pos ){
      outputString += ",";
    }
  }

  //Returning the string to be displayed by the program.
  return outputString;
}


//This function converts an arbitrary string into a bigInt and returns the bigInt
//as a reference parameter as well as the length of the input as an integer value.
//If the integer input isn't valid it returns a value of -1.
int BigInt::fromString(digit bigInt[], const std::string &inputString) {
  //Allocatnig memory space for variables that will be used to run the function, as
  //well as recording the length of the input and the maximum size which will be used
  //to manipulate the array.
  int length = inputString.length();
  int MaxL = BigInt::MAX_SIZE;
  int skip = MaxL - length;
  int i = 0;
  int j = 0;
  //Testing if the input is of an appropriate size.
  if(inputString.length() <= BigInt::MAX_SIZE){
    //Setting all the values in the bigInt to 0
    for( i = 0; i < MaxL ; i++){
      bigInt[i] = 0;
    }
    //Recording the input numbers into the bigInt array only in the needed spots,
    //skipping the unused spaces and leaving them as zeros. This is done by subtracting
    //the input length from the max size, and starting our counting variable i at that
    //value and letting the loop continue until it reaches the max value again, while
    //using another counting variable j to get the values from the inputString.
    for( i = skip; i < MaxL; j++,i++ ){
      //Testing every character in the inputString to make sure they are a number.
      if(inputString[j] > 47 && inputString[j] < 58){
        bigInt[i] = inputString[j] - '0'; //Converting each character in the input
        //string into numbers and storing them into bigInt.
      }else{
        return -1;
      }
    }
  }else{
    return -1;
  }
  //Returning the length of the inputs.
  return length;
}

//This function will add two bigInts together and return the result as a reference
//parameter, and the carry value as an integer so the program can test for overflow.
int BigInt::add(digit sum[], const digit first[], const digit second[]) {
//Allocatnig memory space for variables that will be used to run the function, as
//well as recording the length of the input and the maximum size which will be used
//to manipulate the array.
  int maxlength = BigInt::MAX_SIZE;
  int i = 0;
  int j = 0;
  int pos = maxlength - 1;
  int waste = 0;
//Setting all the numbers in the sum array to 0.
  for( ; j < maxlength ; j++){
  sum[j] = 0;
    }
//Loop counting backwards to add the two values at a given position and store them
//in the sum array at that same position, as well as adding the carry value when
//necessary.
  for(i = pos; i >= 0; i--){
    sum[i] += first[i] + second[i] + waste;
//Testing if the sum is greater than 10, in which case it will only record the
//value smaller than 10, and change the carry variable to 1 to account for the
//excess, which will be added in the next iteration of the loop.
      if(sum[i] >= 10 ){
      sum[i] = sum[i]-10;
      waste = 1;
    }else  {
      waste = 0;
    }
    }
//Returning the carry variable which is used to test for overflow.
  return waste;

}

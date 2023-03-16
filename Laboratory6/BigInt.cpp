/**
    BigInt.cpp
    CMPT 275 Laboratory 6
    Purpose:  This is the program to contain a Class that has at most 30 digits.
    It is responsible for storing the digits even if they are inputed as a string,
    an array of chars or a long number, and is able to perform comparisons and
    determine various things about the number from doing so, as well as adding
    bigInts together.

    @Marcelo Napoleao Sampaio
    @29/11/2019
*/

#include "BigInt.h"
using namespace CMPT275;
using namespace std;

//This function will initialize the input, receving a string, it will convert it
//into the array number by number, while testing each number for its validity, and
//for the appropriate size.
 void BigInt::init(const std::string& inputString){
   int length = inputString.length();
   int i = 0;
   int j = 0;
   int max = PRECISION;
   int skip = max - length;
   //Initializing my boolean variables to their default position, a different function
   //is responsible for testing them and updating them.
   invalid = false;
   overflow = false;

   if(inputString.length() > PRECISION){
     invalid = true;
   }

   for(int i = 0; i < PRECISION; i++){
     digits[i] = 0;
   }
//Converting the numbers in the string to integers and passing them into the array
//as well as testing if they are all numbers between 0 and 9, if anything is not a number
//it will set the validity boolean variable to true.
   for(j = skip, i = 0; j < PRECISION; i++,j++){
     if(inputString[i] >= '0' && inputString[i] <= '9'){
       digits[j] = inputString[i] - '0';
   }else{
     invalid = true;
   }
}
 }

//Default constructor initializes the array in the class to 0, using the init()
//function, passing it a string containing the number 0.
BigInt::BigInt() {
  string c = "0";
  init(c);
  return;
}
//Constructor to assign the numbers in an array of characters into the array of
//the class by changing the array to a string, and passing a string to the init()
//function.
BigInt::BigInt(const char digitString[]) {
  string s = digitString;
  init(s);
  return;
}
//Constructor to assign a string to the array in the class simply by calling the
//init function and giving it the string passed as a parameter.
BigInt::BigInt(const std::string &digitString) {
  init(digitString);
  return;
}
//Constructor to store a long number into the array, by converting it into a string
//while giving it to the init() function as a parameter.
BigInt::BigInt(long number) {
  init(to_string(number));
return;
}
//Function count the amount of numbers in the class' array.
int BigInt::length() const {
  int i = 0;
  int size = 1;
  for(; i < PRECISION; i++){
    if(digits[i] != 0){
      size = PRECISION - i;
      break;
    }
  }
  return size;
}
//Fucntion that returns whether there was an overflow of numbers after adding.
bool BigInt::isOverflow() const {
  return overflow;
}
//Function that returns whether the input is valid.
bool BigInt::isInvalid() const {
  return invalid;
}
//Function that converts the bigint into a string for it to be displayed, placing
//the commas and ignoring the 0's.
std::string BigInt::toString() const {
    int maxlength = PRECISION;
    std::string outputString = "";
    int i = 0;
    int j = 0;
    int pos = maxlength - 1;
    //Finding where the numbers in the array start and recording the position to
    //variable j so that we can skip the zeros and only add the numbers into the string
    //that will be returned.
    for(;i <= maxlength; i++){
      if(digits[i] != 0){
        break;
      }
      if(i == pos){
        return "0";
      }
    }
    //Converting the numbers in the array into charachters and adding them to the
    //outputString variable which is recording our big integer as a string to be returned.
    for(j = i; j < maxlength ; j++){
      char C = digits[j] + '0'; //This line converts the numbers into charachters
      outputString += C;        //by changing them to the respective ascii value.
                                //then adds them to the string.

      //Adding commas between every 3 digts.
      if((pos - j) % 3 == 0 && j != pos ){
        outputString += ",";
      }
    }
  return outputString;
}
//Fucntion to add two bigints together, returning their sum as a bigint.
BigInt BigInt::add (const BigInt& otherBigInt) const {
  BigInt sum;//Declaring the bigint sum.
  //Allocatnig memory space for variables that will be used to run the function, as
//well as recording the length of the input and the maximum size which will be used
//to manipulate the array.
  int maxlength = PRECISION;
  int i = 0;
  int j = 0;
  int pos = maxlength - 1;
  int waste = 0;
//Setting all the numbers in the sum array to 0.
  for( ; j < maxlength ; j++){
  sum.digits[j] = 0;
    }
//Loop counting backwards to add the two values at a given position and store them
//in the sum array at that same position, as well as adding the carry value when
//necessary.
  for(i = pos; i >= 0; i--){
    sum.digits[i] += otherBigInt.digits[i] + digits[i] + waste;
//Testing if the sum is greater than 10, in which case it will only record the
//value smaller than 10, and change the carry variable to 1 to account for the
//excess, which will be added in the next iteration of the loop.
      if(sum.digits[i] >= 10 ){
      sum.digits[i] = sum.digits[i]-10;
      waste = 1;
    }else  {
      waste = 0;
    }
  }
  if(waste == 1){
    sum.overflow = true; //Testing if there was an overflow, in which case will
                        //set the overflow variable to true.
  }
  return sum;
}
//Function to add two big ints when a long is inputed.
BigInt BigInt::add (long otherNumber) const {
  BigInt sum(otherNumber); //Declaring a bigint and calling its long constructor
  return add(sum); //using the regular add function now that the long was converted.
}
//Function to filter through two big ints and return whether one is greater, smaller
//or if they are equal.
int BigInt::compare (const BigInt& otherBigInt) const {
  int i = 0;
  for(; i < PRECISION; i++){
    if(otherBigInt.digits[i] > digits[i]){
      return -1;
    }else if (digits[i] > otherBigInt.digits[i]){
      return 1;
    }
  }
  return 0;
}
//Function to run the compare function when a long number is inputed.Follows the
//same procedure as the add function for long.
int BigInt::compare (long otherNumber) const {
  BigInt anotherBigInt(otherNumber);
  return compare(anotherBigInt);
}
//These functions will now merely interpret the result of the compare function.
//Works the same way for the long case, as it has its own compare function that
//fixes it up first.
//These functions are responsible for determining what information will be displayed,
//by displaying only the ones that return true.
bool BigInt::greaterThan (const BigInt& otherBigInt) const {
  return (compare(otherBigInt) > 0);
}

bool BigInt::greaterThan (long otherNumber) const {
  return (compare(otherNumber) > 0);
}

bool BigInt::greaterThanOrEqual (const BigInt& otherBigInt) const {

  return (compare(otherBigInt) >= 0);
}

bool BigInt::greaterThanOrEqual (long otherNumber) const {
  return (compare(otherNumber) >= 0);
}

bool BigInt::lessThan (const BigInt& otherBigInt) const {

  return (compare(otherBigInt) < 0);
}

bool BigInt::lessThan (long otherNumber) const {
  return (compare(otherNumber) < 0);
}

bool BigInt::lessThanOrEqual (const BigInt& otherBigInt) const {
  return (compare(otherBigInt) <= 0);
}

bool BigInt::lessThanOrEqual (long otherNumber) const {
  return (compare(otherNumber) <= 0);
}

bool BigInt::equal (const BigInt& otherBigInt) const {
  return (compare(otherBigInt) == 0);
}

bool BigInt::equal (long otherNumber) const {
  return (compare(otherNumber) == 0);
}

bool BigInt::notEqual (const BigInt& otherBigInt) const {
  return (compare(otherBigInt) != 0);
}

bool BigInt::notEqual (long otherNumber) const {
  return (compare(otherNumber) != 0);
}

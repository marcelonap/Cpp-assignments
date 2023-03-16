/**
    BigInt.h
    CMPT 275 Laboratory 6
    Purpose:  This is the program to contain a Class that has at most 30 digits.
    It is responsible for storing the digits even if they are inputed as a string,
    an array of chars or a long number, and is able to perform comparisons and
    determine various things about the number from doing so, as well as adding
    bigInts together.

    @Marcelo Napoleao Sampaio
    @29/11/2019

*/

#include<iostream>
namespace CMPT275 {
  class BigInt {

    public:
      static const int PRECISION = 30;

      // Constructors:
      BigInt();
      BigInt(const char[]);
      BigInt(const std::string&);
      BigInt(long);

      // Accessors
      int length() const;
      bool isOverflow() const;
      bool isInvalid() const;

      std::string toString() const;

      BigInt add (const BigInt&) const;
      BigInt add (long) const;

      int compare (const BigInt&) const;
      int compare (long) const;

      bool greaterThan (const BigInt&) const;
      bool greaterThan (long) const;

      bool greaterThanOrEqual (const BigInt&) const;
      bool greaterThanOrEqual (long) const;

      bool lessThan (const BigInt&) const;
      bool lessThan (long) const;

      bool lessThanOrEqual (const BigInt&) const;
      bool lessThanOrEqual (long) const;

      bool equal (const BigInt&) const;
      bool equal (long) const;

      bool notEqual (const BigInt&) const;
      bool notEqual (long) const;

    private:
      
      typedef int digit;

      digit digits[PRECISION];

      void init(const std::string&);

      bool invalid;
      bool overflow;

  };
}

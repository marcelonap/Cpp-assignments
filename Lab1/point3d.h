/* point3d.h
    CMPT 276 Laboratory 1
Purpose:  The purpose of this lab is to create a class
to stores and manipulates a point in three dimensional space
that has three coordinates: x, y and z. In this .h file i define declare the 
class and the headers for the member functions and the overloaded operators. 

    @Marcelo Napoleao Sampaio
    @31/01/2020
*/
#include<iostream>
using namespace std;
#ifndef _point3d_H
#define _point3d_H
  class point3d
  {
  public:
//Constructor
//Preconditions: none if the default constructor is called, but needs three valid doubles if the parametarized constructor is called.
//Postconditions: initializes the data points to zero if the default constructor is called, or initializes them to the given parameters if the parametarized constructor is called.
    point3d(double init_x = 0.0, double init_y = 0.0, double init_z = 0.0);
//Getters.
//Preconditions: none.
//Postconditions: returns a respective data point of the object, which are doubles.
    double get_x() { return x; };
    double get_y() { return y; };
    double get_z() { return z; };
//Setters.
//Preconditions: Needs a double value as a parameter, takes only one paramater.
//Postconditions: Changes the respective data point in the object to the parameter inputed.
    void set_x(double new_x);
    void set_y(double new_y);
    void set_z(double new_z);
//Shift function (overloaded function)
    //Preconditions: 3 valid doubles.
    //Postconditions: changes the value of all 3 data points by adding the input parameters to them.
    void shift(double shift_x, double shift_y, double shift_z);
    //Preconditions: needs a valid point3d object as a paramater.
    //Postconditions: changes the value of all 3 data points by adding the corresponding data points from
    //the object given as a parameter.
    void shift(const point3d& shifter);
//Precondition: needs a valid double as a parameter:
//Postconditions: changes all the data points by multiplying them by the parameter given.
    void scale(double scale_all);
//Overloaded operators.

//Preconditions: Needs 2 valid point3d's.
//Postconditions: adds the data points to their corresponding variable of the other object
//and returns the sum.
friend point3d operator+(  const point3d& first,  const point3d& second);

//Preconditions: Needs 2 valid point3d's.
//Postconditions: compares all the corresponding data points and returns wether they're all the same(true)
//or not (false);
 friend bool operator==( const point3d& first,   const point3d& second);

//Preconditions: os is a stream ready for writing, x is a valid point3d.
//Postconditions: writes the data points of a point3d into the stream
 friend ostream& operator<<( ostream& os,   const point3d& x);
  
private:
//Data points in the object.
    double x;
    double y;
    double z;
  };


#endif

/* main.cpp
    CMPT 276 Laboratory 1
    Purpose: The purpose of this main.cpp file is to test our point3d class
    and make sure it does everything it is supposed to do.

    @Marcelo Napoleao Sampaio
    @31/01/2020
*/
#include<iostream>
#include"point3d.h"
using namespace std;

int main(){
  //this whole program tests the << overloaded operator everytime it has to cout anything.
//testing default constructor
point3d a;
cout << "coordinates should all be 0" << endl;
cout << a << endl;
//testing parametarized constructor
point3d b(2.0, 3.0, 4.0);
cout << " coordinates should be 2.0 3.0 and 4.0"<< endl;
cout << b << endl;
//testing overloaded == operator
point3d c;
cout << "a and b should not be equal" << endl;
if(a==b){
  cout << "a and b are equal"<< endl;
}else{
  cout << "a and b are not equal" << endl;
}
cout << "a and c should be equal" << endl;
if(a==c){
  cout << "a and c are equal"<< endl;
}else{
  cout << "a and c are not equal" << endl;
}

point3d d(1.0,2.0,3.0);
//testing overloaded + operator
point3d x = b + d;
cout << "x should be 3,5,7" << endl;
cout << "x: " << x << endl;
//testing shift function with point3d parameter
a.shift(b);
cout << "a should now be 2,3,4" << endl;
cout << "a: " << a << endl;
//testing shift function with 3 doubles.
b.shift(1.0,3.0,2.0);
cout << "b should now be 3,6,6" << endl;
cout << "b: " << b << endl;
//testing scale function
d.scale(3.0);
cout << "d should now be 3,6,9" << endl;
cout << "d: " << d << endl;
//testing setters
c.set_x(3.0);
c.set_y(4.0);
c.set_z(5.0);
cout << "c should now be 3,4,5" << endl;
cout << "c: " << c << endl;
//testing getters
cout << "b's x should be 3" << endl;
cout <<"b.get_x():" << b.get_x() << endl;

cout << "c's y should be 4" << endl;
cout <<"y.get_y():" << c.get_y() << endl;

cout << "d's z should be 9" << endl;
cout <<"d.get_z():" << d.get_z() << endl;
//testing the + and << operator used together
cout << "b + d should be equal 6, 12, 15" << endl;
cout << "b + d = " << (b+d) << endl;

point3d d(9,9,9);
cout << d;


  return 0;
}

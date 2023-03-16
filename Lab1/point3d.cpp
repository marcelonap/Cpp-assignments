/* point3d.cpp
    CMPT 276 Laboratory 1
    Purpose:  The purpose of this lab is to create a class
to stores and manipulates a point in three dimensional space
that has three coordinates: x, y and z.

    @Marcelo Napoleao Sampaio
    @31/01/2020
*/
#include"point3d.h"
#include<iostream>
using namespace std;

point3d::point3d(double init_x, double init_y, double init_z){
      x = init_x;
      y = init_y;
      z = init_z;
}

void point3d::set_x(double new_x){
  x = new_x;

}

void point3d::set_y(double new_y){
  y = new_y;

}

void point3d::set_z(double new_z){
  z = new_z;

}
 void point3d::shift(double shift_x, double shift_y, double shift_z){
   x += shift_x;
   y += shift_y;
   z += shift_z;


 }

 void point3d::shift(const point3d& shifter){
   x += shifter.x;
   y += shifter.y;
   z += shifter.z;
}

 void point3d::scale(double scale_all){
   x *= scale_all;
   y *= scale_all;
   z *= scale_all;

 }

 point3d operator+(  const point3d& first,   const point3d& second){
   point3d sum(first.x+second.x, first.y+second.y, first.z+second.z);
   return sum;
 }

  bool operator==( const point3d& first, const point3d& second){
    return (first.x == second.x && first.y == second.y && first.z == second.z);
}

  ostream& operator<<(ostream& os,const point3d& x){
    os << x.x << ", " << x.y<< ", " << x.z;
    return os;
  }

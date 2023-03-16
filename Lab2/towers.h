/* towers.h
    CMPT 276 Laboratory 2
    Purpose:  The purpose of this lab is to create a towers class and a pegs class
    which are used to play the towers of hanoi game, storing and manipulating The
    data necessary for the game to happen.

    @Marcelo Napoleao Sampaio
    @14/02/2020
*/

#ifndef __TOWERS_H__
#define __TOWERS_H__

#include"peg.h"
#include <iostream>
using namespace std;

class towers{
public:

  static const int NUMPEGS = 3; // Number of pegs in the tower.

  towers(peg::size_type n=30);
// Constructor.
// This initializes the towers so that there are n disks
// stacked on the first peg, in order of size, and the
// other two pegs are empty.
size_t many_disks(int peg_number) const;
// peg_number is 1, 2 or 3
// The return value is the number of disks on the specified
// peg.
size_t top_diameter(int peg_number) const;
// peg_number is 1, 2 or 3
// If many_disks(peg_number)>0, then the return value is
// the diameter of the top disk of the specified peg;
// otherwise the return value is 0.
void move(int start_peg, int end_peg);
// Precondition: start_peg is 1, 2 or 3, and
// many_disks(start_peg)>0. end_peg is 1, 2 or 3, but not
// equal to start_peg. Also, top_diameter(end_peg) is
// either 0 or more than top_diameter(start_peg).
// Postcondition: The top disk is moved from start_peg to
// end_peg.
void display() const;
// Displays the disks on each peg, one above the other.
// For example:
// 1: 3-1
// 2:
// 3: 2-
//void moveBottomDisk(towers& tower);
private:

  peg pegs[NUMPEGS]; //Array of peg objects.

};

void solve3(towers& tower, int target, int start); // function to move the top 3 disks
//Preconditions: provided with a valid towers object, and two integers from 1-3 but different from each other
//Postcondition: moves the top three disks on the starting peg to the targt peg.

//void solve(towers& tower, int target, int start, int num_disks);


#endif

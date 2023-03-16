

/***************************************************************************

  peg.h:  Provides the peg class, which describes disks stored on a peg
  according to the rules of the Tower of Hanoi puzzle.

  -Robert MacDonald, The King's University (February 2016)

  The storage is implemented as a partially-filled array.
  - The disklist array stores the diameters of each disk on the peg.
    - disklist[0] stores the bottom (largest) disk.
  - numdisks stores the number of disks currently on the peg.

 ***************************************************************************/

#ifndef __PEG_H__
#define __PEG_H__

#include <iostream>
using namespace std;

/**********************************************************/
/***                  CLASS DEFINITION                  ***/
/**********************************************************/

class peg {
/***********************************/
 public:

  typedef size_t size_type; // Type for counting disks and labeling diameters.
  static const size_type CAPACITY = 30; // Maximum number of disks on a peg.


  /***********************************/
  /***  FRIEND FUNCTIONS (not members)  ***/

  friend ostream& operator<<(ostream& os, const peg& a);
  // PRECONDITIONS:  The ostream object must be ready for output.
  // POSTCONDITIONS: A visual representation of the peg is displayed on
  // the output stream.


  /***********************************/
  /***  Constructors  ***/

  peg(size_type startingdisks = 0);
  // PRECONDITIONS:  startingdisks <= CAPACITY.
  // POSTCONDITIONS: Constructor.  If startingdisks is given, the peg
  // is initialized with disk sizes from 1 to startingdisks (with 1 on
  // top).  Otherwise initializes an empty peg (no disks).

  /***********************************/
  /***  Getters  ***/

  size_type get_num_disks() const;
  // PRECONDITIONS:  None.
  // POSTCONDITIONS: Returns the number of disks on the peg.

  size_type get_top_diameter() const;
  // PRECONDITIONS:  None.
  // POSTCONDITIONS: Returns the diameter of the topmost disk,
  //   or 0 if the peg is empty.


  /***********************************/
  /***  Modifiers  ***/

  bool add_disk(size_type newsize);
  // PRECONDITIONS:  None.
  // POSTCONDITIONS: If there was enough room on the peg to add a
  // disk, AND the topmost disk (if any) was larger than newsize, then
  // a disk with diameter newsize is added to the top of the peg and
  // this function returns true.  If it was unable to add a disk, the
  // peg is unchanged and this function returns false.

  void remove_disk();
  // PRECONDITIONS:  There is at least one disk on the peg.  
  // (Calling remove_disk() on an empty peg is undefined behaviour.)
  // POSTCONDITIONS: The topmost disk has been removed from the peg.


/***********************************/
 private:

  size_type disklist[CAPACITY]; // diameters of each disk on the peg.
  size_type numdisks; // Number of disks currently on the peg.
  
}; // class peg


/**********************************************************/
/***  NON-MEMBER FUNCTIONS associated with this class.  ***/
/**********************************************************/

// See FRIEND functions in class definition.


#endif // defined __PEG_H__

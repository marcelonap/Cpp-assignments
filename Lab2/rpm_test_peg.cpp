/***************************************************************************

 rpm_test_peg.cpp: Test suite for the peg class (CMPT302 Lab 2).

 -Robert MacDonald, The King's University (February 2016)
 
 ***************************************************************************/ 

#include<iostream> // for cout
#include<iomanip>  // for setw
#include<string>   // for string
#include<sstream>  // for stringstream
#include"peg.h"
using namespace std;

ostream& testcomment(ostream& os, const char comment[], const char expect[]);
// Display a test description and the expected results, in
// nicely-formatted columns.  Inputs are C-strings so that I can pass
// things like "Expected" without having to do string("Expected").
// NOTE: Sets "left" attribute on output stream!

string starbar(int nstars);
// Returns a string containing nstars *'s.


int main() {

  // Testing constructors.
  peg peg1(3);   // Parametrized constructor.
  peg peg2, peg3; // Default constructor.
  peg full_peg(30); // Starts out full.
 
  cout << left; // Left-align the columns for cleaner output.

  testcomment(cout, "Comment", "Expected") << "Output" << endl << endl;

  // Check the capacity.
  //testcomment(cout, "Peg capacity:", "30") << peg::CAPACITY << endl;

  // Check getters.
  testcomment(cout, "get_num_disks:", "3, 0, 0, 30") << peg1.get_num_disks() << ", " << peg2.get_num_disks() << ", "
						     << peg3.get_num_disks() << ", " << full_peg.get_num_disks() << endl;
  testcomment(cout, "get_top_diameter:", "1, 0, 0, 1") << peg1.get_top_diameter() << ", " << peg2.get_top_diameter() << ", " 
						       << peg3.get_top_diameter() << ", " << full_peg.get_top_diameter() << endl;

  // Check assignment & copy constructor
  peg3     = peg1; // Assignment!
  peg peg4 = peg1; // Copy constructor!
  cout << endl;
  testcomment(cout, "peg1 (for reference):", "3, 1") << peg1.get_num_disks() << ", " << peg1.get_top_diameter() << endl;
  testcomment(cout, "peg3=peg1 (asg):", "3, 1") << peg3.get_num_disks() << ", " << peg3.get_top_diameter() << endl;
  testcomment(cout, "peg4=peg1 (copy ctor):", "3, 1") << peg4.get_num_disks() << ", " << peg4.get_top_diameter() << endl;

  // Check adding disks.
  cout << endl;
  testcomment(cout, "peg1.add_disk(3):", "0 (F), 1") << peg1.add_disk(3) << ", " << peg1.get_top_diameter() << endl;
  testcomment(cout, "peg2.add_disk(3):", "1 (T), 3") << peg2.add_disk(3) << ", " << peg2.get_top_diameter() << endl;
  testcomment(cout, "peg2.add_disk(3):", "0 (F), 3") << peg2.add_disk(3) << ", " << peg2.get_top_diameter() << endl;
  testcomment(cout, "peg2.add_disk(2):", "1 (T), 2") << peg2.add_disk(2) << ", " << peg2.get_top_diameter() << endl;
  testcomment(cout, "full_peg.add_disk(3):", "0 (F), 1") << full_peg.add_disk(3) << ", " << full_peg.get_top_diameter() << endl;

  // Check removing disks.
  cout << endl;
  peg3 = peg(); // Assign an empty peg to peg3, i.e. reset peg3.
  peg3.add_disk(5);
  peg1.remove_disk();
  peg2.remove_disk();
  peg3.remove_disk();
  full_peg.remove_disk();
  testcomment(cout, "peg1.remove_disk():", "2, 2") << peg1.get_num_disks() << ", " << peg1.get_top_diameter() << endl;
  testcomment(cout, "peg2.remove_disk():", "1, 3") << peg2.get_num_disks() << ", " << peg2.get_top_diameter() << endl;
  testcomment(cout, "peg3.remove_disk():", "0, 0") << peg3.get_num_disks() << ", " << peg3.get_top_diameter() << endl;
  testcomment(cout, "full_peg.remove_disk():", "29, 2") << full_peg.get_num_disks() << ", " << full_peg.get_top_diameter() << endl;

  peg2.remove_disk();
  full_peg.remove_disk();
  full_peg.remove_disk();
  full_peg.remove_disk();
  testcomment(cout, "peg2.remove_disk():", "0, 0") << peg2.get_num_disks() << ", " << peg2.get_top_diameter() << endl;
  testcomment(cout, "full_peg.remove_disk():", "26, 5") << full_peg.get_num_disks() << ", " << full_peg.get_top_diameter() << endl;

  cout << endl;

  // Testing visual display of peg contents.
  peg1     = peg(3);
  peg2     = peg();
  full_peg = peg(30);
  cout << endl << starbar(34) << " PEGS " << starbar(34) << endl;
  cout << "  Peg1 (3):" << endl << peg1 << endl;
  cout << "  Peg2 (0):" << endl << peg2 << endl;
  cout << "  Full Peg (30):" << endl << full_peg << endl;
  cout << starbar(76) << endl;

  return 0;

} // main()



ostream& testcomment(ostream& os, const char comment[], const char expect[]) {
  // Display a test description and the expected results, in
  // nicely-formatted columns.

  // Output column widths, for faster reading:
  const int TESTCOL   = 30;
  const int EXPECTCOL = 15;

  os << right << setw(TESTCOL) << comment << "  " << left << setw(EXPECTCOL) << expect;

  return os;
}


string starbar(int nstars) {
  return string(nstars, '*'); // Handy string constructor!
}

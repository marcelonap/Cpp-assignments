/*
  checktest: Utilities for displaying the results of a test suite.
  -Robert MacDonald, The King's University (Winter 2018)
*/

#include <iostream> // for cout
#include <iomanip>  // for setw
#include <sstream> // for stringstream


using namespace std;

bool checktest(string comment, string expect, string result) {

  // Output column widths:
  static const int MATCHCOL = 11;
  static const int COMMENTCOL = 30;
  static const int EXPECTCOL = 30;

  bool match = (expect == result);

  cout << left;

  cout << setw(MATCHCOL);
  if (match) {
    cout << "match";
  } else {
    cout << "==DIFF==";
  }
  cout << setw(COMMENTCOL) << comment << " | ";
  cout << setw(EXPECTCOL) << expect << " | ";
  cout << result << endl;

  return match;
} // bool checktest


bool checktest(const char comment[], const char expect[], string result) {
  return checktest(string(comment), string(expect), result);
}
bool checktest(string comment, string expect, stringstream &result) {
  string s = result.str();
  result.str(string(""));
  return checktest(comment, expect, s);
}
bool checktest(const char comment[], const char expect[], stringstream &result) {
  string s = result.str();
  result.str(string(""));
  return checktest(comment, expect, s);
}



string bool2str(bool b) {
  if (b)
    return string("true");
  else
    return string("false");
}

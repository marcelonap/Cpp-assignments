/***************************************************************************

  test_polynomial.cpp: Tester for the polynomial class.

  -Robert MacDonald, The King's University (Winter 2018)

************************************************************************/

#include <iostream>
#include <sstream> // stringstream

#include "polynomial.h"

#include "checktest.h"

using namespace std;

/***************************************************************************/

int main () {
  
  stringstream result; // For test results.
  
  ////////////////////////////////////////
  // Testing constructors.
  polynomial p0, p0b;  // Default constructor.
  polynomial p42(42); // Parametrized constructor.
  polynomial p42b = p42;  // Copy constructor.
  
  // Show constructor results (and test output).
  cout << " Testing constructors" << endl;
  result << p0;
  checktest("p0 (default ctor)", "0", result);
  result << p42;
  checktest("p42 (param. ctor)", "42", result);
  result << p42b;
  checktest("p42b (copy ctor)", "42", result);


  ////////////////////////////////////////
  // Test inserting new terms, & negative coefficients.
  // Also ensures copy ctor makes deep copies.
  p0b.setCoefficient(99, 1);
  p42.setCoefficient(5, 1);
  p42.setCoefficient(-1, 2);
  p42b.setCoefficient(2, 3);
  cout << " Inserting new terms" << endl;
  result << p0b;
  checktest("p0b", "0 + 99*x^1", result);
  result << p42;
  checktest("p42", "42 + 5*x^1 - 1*x^2", result);
  result << p42b;
  checktest("p42b", "42 + 0*x^1 + 0*x^2 + 2*x^3", result);
  
  
  ////////////////////////////////////////
  // Test modifying terms, & decimal coefficients.
  // Also ensures assignment makes deep copies.
  p0b = p0;
  p0b.setCoefficient(48, 0);
  p42b = p42;
  p42.setCoefficient(0.5, 1);
  p42.setCoefficient(-0.8, 2);
  cout << " Modifying terms" << endl;
  result << p0b;
  checktest("p0b", "48", result);
  result << p42;
  checktest("p42", "42 + 0.5*x^1 - 0.8*x^2", result);
  result << p42b;
  checktest("p42b", "42 + 5*x^1 - 1*x^2", result);

  // Test "removing" terms (setting the coefficients to 0).
  p42.setCoefficient(0, 1);
  p42b.setCoefficient(0, 2);
  cout << " Zeroing terms" << endl;
  result << p42;
  checktest("p42", "42 + 0*x^1 - 0.8*x^2", result);
  
  ////////////////////////////////////////
  // Test getters:
  
  // Test degree.
  cout << " Polynomial degree" << endl;
  result << p0.degree();
  checktest("p0", "0", result);
  result << p42.degree();
  checktest("p42", "2", result);
  //checktest("p42b", "1", result) << p42b.degree() << endl;

  // Test coefficient getter.
  cout << " Coefficient getter" << endl;
  result << p42.coefficient(2);
  checktest("p42 x^2", "-0.8", result);
  result << p42.coefficient(1);
  checktest("p42 x", "0", result);
  result << p42b.coefficient(1);
  checktest("p42b x", "5", result);
  result << p0.coefficient(4);
  checktest("p0 x^4", "0", result);
  
  // Test evaluation.
  cout << " Evaluation" << endl;
  result << p42(2);
  checktest("p42(2)", "38.8", result);
  result << p42b.eval(-4);
  checktest("p42b.eval(-4)", "22", result);
  result << p42(0.5);
  checktest("p42(0.5)", "41.8", result);
  
  
  //////////////////////////////////////////////////
  // Test operators.

  // Test comparison.
  polynomial p1a(5);
  p1a.setCoefficient(-1, 1);
  polynomial p1b(5);
  p1b.setCoefficient(-1, 1);
  polynomial p2(5);
  polynomial p3(42);
  cout << " Comparing polynomials" << endl;
  checktest("p1a == p1b", "true", bool2str(p1a==p1b));
  checktest("p1a == p2 (same constant)", "false", bool2str(p1a==p2));
  checktest("p1b == p3 (all diff.)", "false", bool2str(p1a==p3));
  
  // Test adding polynomials.
  polynomial q, r;
  q = p42 + p42b;
  p42b.setCoefficient(-42, 0);
  p42.setCoefficient(10, 1);
  p42b.setCoefficient(2, 3);
  r = p42 + p42b;
  cout << " Adding polynomials" << endl;
  result << q;
  checktest("q (p42 + p42b)", "84 + 5*x^1 - 0.8*x^2", result);
  result << r;
  checktest("r (more terms)", "0 + 15*x^1 - 0.8*x^2 + 2*x^3", result);
  
} // main


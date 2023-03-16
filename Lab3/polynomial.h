/***************************************************************************
CMPT 276 Laboratory 3
Purpose: This is the header file for the polyniomial class which is contains the function headers
and documentation for the functions, as well as the headers for the overloaded non-member operators.

@Marcelo Napoleao Sampaio
@06/03/2020

  (Please include your name, date, course, etc, and a brief description of this class.)


  FUNCTION DOCUMENTATION

  *** CONSTRUCTORS & DESTRUCTOR ***



  polynomial(double constantTerm = 0)
  PRECONDITIONS: None.
  POSTCONDITIONS: Polynomial object is initialized with degree 0,
    with the given constant term.  Default constant value is 0.
  
  polynomial(const polynomial& source) Copy constructor.
  PRECONDITIONS: Needs a valid polynomial to copy from.
  POSTCONDITIONS: The non-dynamic variables are set equal to the source object and a deep copy of 
  the dynamic array is made.
   
  ~polynomial() Destructor.
  PRECONDITIONS:None.
  POSTCONDITIONS: deallocates the dynamic variable, aka deletes the dyamic array in the object




  *** MODIFIERS ***




  polynomial& operator =(const polynomial& source) Assignment operator.
  PRECONDITIONS: Needs a valid polynomial to copy from.
  POSTCONDITIONS: Makes the object equal to the assigned object with a deep copy of the
  dynamic array.
  void reserveDegree(size_t maxExponent) wrapper for reserveTerms function
  PRECONDITIONS: Needs reserveTerms to be defined and a valid size_t argument.
  POSTCONDITIONS:  Makes sure there's enough space in the container for the term with
the given exponent.  

  void reserveTerms(size_t newterms)
  PRECONDITIONS: Needs a valid size_t argument.
  POSTCONDITIONS:Makes sure the container's array is at least as large as the argument. If it has to
increase the size of the array, the coefficients of all of the new terms are initialized to 0.

  void setCoefficient(double coefficient, size_t exponent)
  PRECONDITIONS: Needs a valid double and a valid size_t arguments.
  POSTCONDITIONS: : Sets the coefficient of the term with the given power of x, adding
terms as needed.
 
 
  *** GETTERS ***



  size_t degree()
  PRECONDITIONS: nterms needs to be a valid size_t.
  POSTCONDITIONS: Returns nterms-1 which is the degree of the polynomial.

  double coefficient(size_t exponent)
  PRECONDITIONS: Needs a valid size_t argument.
  POSTCONDITIONS: Returns the coefficient of the term with the given exponent

   double eval(double x)
   PRECONDITIONS: Needs a valid double argument.
   POSTCONDITIONS: : Evaluates the polynomial at the given value of x (written without using pow :))

  std::string toString() 
  PRECONDITIONS: None.
  POSTCONDITIONS: Returns a string representing the polynomial.

  *** SETTERS ***

The setters are the modifiers



  *** OTHER MEMBER OPERATORS ***



  double operator()(double x)
    Wrapper for eval(x).  See eval for documentation.


  *** NON_MEMBER OPERATORS ***


  polynomial operator +(const polynomial& p1, const polynomial& p2)
  PRECONDITIONS: Needs two valid polynomials.
  POSTCONDITIONS: Returns the sum of the two polynomials, found by adding together
matching terms


  bool operator ==(const polynomial& p1, const polynomial& p2)
  PRECONDITIONS:Needs two valid polynomials.
  POSTCONDITIONS:  Returns true if the two polynomials have the same coefficients, false
otherwise.

  std::ostream& operator <<(std::ostream& os, const polynomial& p)
  PRECONDITIONS: Needs an ostream that is open for writing and a valid polynomial.
  POSTCONDITIONS: Prints the polynomial to the output stream. (Uses toString. :)
 


 ***************************************************************************/

#ifndef POLY_H
#define POLY_H

#include<ostream>

////////////////////////////////////////
// CLASS DEFINITION

class polynomial {
public:
  // CONSTRUCTORS & DESTRUCTOR
  polynomial(double constantTerm = 0); // Constructor.
  polynomial(const polynomial& source); // Copy constructor.
  ~polynomial(); // Destructor.

  // MODIFIERS
  polynomial& operator =(const polynomial& source);  // Assignment operator.
  void reserveDegree(size_t maxExponent) { reserveTerms(maxExponent+1); };
  void reserveTerms(size_t newterms);
  void setCoefficient(double coefficient, size_t exponent);

  // GETTERS
  size_t degree() const { return nterms-1; }
  double coefficient(size_t exponent) const;
  double eval(double x) const;
  std::string toString() const;

  // OTHER MEMBER OPERATORS
  double operator()(double x) const { return eval(x); }

private:
  double *coef;  // The coefficient array.
  size_t coefSize; // Size of the coef array.
  size_t nterms; // Number of elements in coef.  (Internally much more useful than degree.)
  size_t default_size = 10;

};


////////////////////////////////////////
// NON-MEMBER OPERATORS

// Arithmetic:
polynomial operator +(const polynomial& p1, const polynomial& p2);

// Comparison:
bool operator ==(const polynomial& p1, const polynomial& p2);

// Output:
std::ostream& operator <<(std::ostream& os, const polynomial& p);


#endif

/***************************************************************************
CMPT 276 Laboratory 3
Purpose:  this file contains the function definitions for the polynomial class and for
the non-member overloaded operatos.

@Marcelo Napoleao Sampaio
@06/03/2020
  (Please include your name, date, course, etc, and a brief description of this class.)

  See .h file for documentation.

  -Robert MacDonald, The King's University (Winter 2018)

  CLASS INVARIANTS:
  - coefSize contains the current size of the coef array.
  - Index of each element in coeffient array is the exponent for that term.
  - If coefSize > nterms, the "extra" terms have coefficient 0.
  - Any "missing" terms have coefficient 0.

 ***************************************************************************/

#include<cmath>  // for fabs
#include<algorithm>  // for copy and max
#include<sstream> // stringstream for output formatting
#include<ostream> // for << operator
 #include<iostream> // for cout (for testing)

#include"polynomial.h"
using namespace std;

/**********************************************************/
/***               CLASS MEMBER FUNCTIONS.              ***/
/**********************************************************/


/***********************************/
/***  Constructors  ***/

polynomial::polynomial(double constantTerm){

    coefSize = default_size;
    nterms = 1;

    coef = new double [coefSize];

    coef[0] = constantTerm;

    for(size_t i = 1; i < coefSize; i++){
      coef[i] = 0;
    }
}

polynomial::polynomial(const polynomial& source){
    default_size = source.default_size;
    coefSize = source.coefSize;
    nterms = source.nterms;
    coef = new double [coefSize];
    for(size_t i = 0; i < nterms; i++){
      coef[i] = source.coef[i];
    }

}

polynomial::~polynomial(){

  delete [] coef;

}





/***********************************/
/***  Modifiers  ***/

polynomial& polynomial::operator=(const polynomial& source){

  default_size = source.default_size;
  coefSize = source.coefSize;
  nterms = source.nterms;

  delete [] coef;

  coef = new double [coefSize];
  for(size_t i = 0; i < nterms; i++){
    coef[i] = source.coef[i];
  }

  return *this;
}

void  polynomial::reserveTerms(size_t newterms){
  if(coefSize >= newterms) return;
  else{
    coefSize = newterms;
    for( size_t i = nterms; i < coefSize; i++){
      coef[i] = 0;
    }
  }

return;
}

void polynomial::setCoefficient(double coefficient, size_t exponent){
    reserveTerms(exponent);

    coef[exponent] = coefficient;

    if(exponent > nterms-1){
      nterms = exponent + 1;
    }
}



/***********************************/
/***  Getters  ***/


double polynomial::coefficient(size_t exponent) const{
  if(coefSize >= exponent)
    return coef[exponent];
    else
    return 0;
}

double polynomial::eval(double x) const{
  double result = 0;


  for(size_t i = 0; i < nterms; i++){
    double xval = 1;

    for(size_t j = 0; j < i; j++){
       xval *= x;
     }
     result += xval*coef[i];
  }

  return result;
}

string polynomial::toString() const {
  stringstream outstr;
  if (nterms == 0) {return string("0");} // Shouldn't happen, but here you go.
  // Constant term is formatted slightly differently.
  outstr << coef[0];
  // Now print the remaining terms, if any.
  for (size_t i = 1; i < nterms; i++) {
    if (coef[i] < 0) {
      outstr << " - ";
    } else {
      outstr << " + ";
    }
    outstr << fabs(coef[i]) << "*x^" << i;
  }
  return outstr.str();
} // toString




/**********************************************************/
/***               NON-MEMBER OPERATORS                 ***/
/**********************************************************/

polynomial operator+(const polynomial& p1, const polynomial& p2){
  polynomial sum;


  size_t biggerDegree = 0;
  if(p1.degree() > p2.degree()){
    biggerDegree = p1.degree();
  }else{
    biggerDegree = p2.degree();
  }

  sum.reserveTerms(biggerDegree+1);

  for(size_t i = 0; i < biggerDegree + 1; i++){
    sum.setCoefficient(p1.coefficient(i) + p2.coefficient(i), i);
  }

  return sum;
}

bool operator==(const polynomial& p1, const polynomial& p2){
  if(p1.degree() != p2.degree()) return false;

  for(size_t i = 0; i < p1.degree()+1; i++){
    if(p1.coefficient(i) != p2.coefficient(i)){
      return false;
    }
  }

  return true;
}

std::ostream& operator <<(std::ostream& os, const polynomial& p) {
  os << p.toString();
  return os;
} // operator<<

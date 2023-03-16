#include <iostream>
#include <sstream> // stringstream

#include "polynomial.h"


using namespace std;

int main(){
   polynomial p1;

   p1.reserveTerms(4);
   p1.setCoefficient(3,2);
    p1.setCoefficient(3,4);


   cout << p1;

  return 0;
}

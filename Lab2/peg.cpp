/* peg.cpp
    CMPT 276 Laboratory 2
    Purpose:  The purpose of this lab is to create a towers class and a pegs class
    which are used to play the towers of hanoi game, storing and manipulating The
    data necessary for the game to happen.

    @Marcelo Napoleao Sampaio
    @14/02/2020
*/
#include"peg.h"
using namespace std;


peg::peg(peg::size_type startingdisks){
  if(startingdisks <= peg::CAPACITY){
    numdisks = startingdisks;
  }else {
    numdisks = 0;
  }
    if(numdisks > 0){
      for(int i = numdisks,j = 0 ; j < (numdisks); j++,  i--){
        disklist[j] = i;
      }
    }
}

 peg::size_type peg::get_num_disks() const{
  return numdisks;
}

 peg::size_type peg::get_top_diameter() const{
  if(numdisks > 0){
    return disklist[numdisks - 1];
  } else{
    return 0;
  }
}

bool peg::add_disk(peg::size_type newsize){


  if((numdisks < peg::CAPACITY && newsize < disklist[numdisks - 1])||numdisks==0){
      ++numdisks;
      disklist[numdisks-1] = newsize;
      return true;
  }else{
    return false;
  }
}

void peg::remove_disk(){
  if(numdisks > 0){
  --numdisks;
 }
}

ostream& operator<<(ostream& os, const peg& a){
  if(a.numdisks > 0){
  for(int i = 0; i <= a.numdisks-1; i++){
    if(i < a.numdisks-1){
   os << a.disklist[i] << "-";
  }else if(i == a.numdisks-1){
   os << a.disklist[i];
    }
 }
}
  return os;
}

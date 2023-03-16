/* towers.cpp
    CMPT 276 Laboratory 2
    Purpose:  The purpose of this lab is to create a towers class and a pegs class
    which are used to play the towers of hanoi game, storing and manipulating The
    data necessary for the game to happen.

    @Marcelo Napoleao Sampaio
    @14/02/2020
*/

#include"towers.h"

using namespace std;

towers::towers(peg::size_type n){
  for(int  j = n; j > 0; j--){
    pegs[0].add_disk(j);
  }
}

size_t towers::many_disks(int peg_number) const{
  return pegs[peg_number-1].get_num_disks();
}

size_t towers::top_diameter(int peg_number) const{
  if(many_disks(peg_number) > 0){
    return pegs[peg_number-1].get_top_diameter();
  }else{
    return 0;
  }
}

void towers::move(int start_peg, int end_peg){
  int pos1 = start_peg - 1;
  int pos2 = end_peg - 1;
  if(many_disks(start_peg)>0 && end_peg != start_peg &&(top_diameter(end_peg) > top_diameter(start_peg) || top_diameter(end_peg) == 0)){
      pegs[pos2].add_disk(top_diameter(start_peg));
      pegs[pos1].remove_disk();
  }
}

void towers::display() const{
  cout << "1: " << pegs[0] << endl;
  cout << "2: " << pegs[1] << endl;
  cout << "3: " << pegs[2] << endl;
  cout << endl << endl;
}


void solve3(towers& tower, int target, int start){
  int transit = 6 - target - start;
if(tower.many_disks(start) >= 3){
  tower.move(start,target);
  tower.display();
  tower.move(start,transit);
  tower.display();
  tower.move(target,transit);
  tower.display();
  tower.move(start,target);
  tower.display();
  tower.move(transit,start);
  tower.display();
  tower.move(transit,target);
  tower.display();
  tower.move(start,target);
  tower.display();
  }
}
//---------------------------------------------------//

// This is the function i tried to create to use recursion and make my program able
//to solve the puzzle with any number of starting disks.

//You asked me to leave the code i tried to use here for you to remember why my code
//only works for 3 and 5 and said that was okay.

// void solve(towers& tower, int target, int start, int num_disks){
//   int i = 0;
//   int mid = 6 - target - start;
//   solve3(tower, target, start);
//
//   while(tower.many_disks(target) < num_disks){
//     //cout << num_disks << endl;
//     //cout << tower.many_disks(target)<< endl;
//     if(i%2==0){
//       if(tower.top_diameter(start) == num_disks){
//           tower.move(start,mid);
//           tower.display();
//           break;
//       }
//       tower.move(start,mid);
//       tower.display();
//       solve3(tower, mid, target);
//
//     }else{
//       if(tower.top_diameter(start) == num_disks){
//           tower.move(start,target);
//           tower.display();
//           break;
//       }
//       tower.move(start,target);
//       tower.display();
//       solve3(tower, target, mid);
//     }
//     ++i;
//   }


//   while(tower.many_disks(target) != num_disks){
//   if(tower.many_disks(target) == num_disks){
//     cout << "done";
//   }else if(tower.many_disks(target)!= num_disks){
// solve(tower,start,mid,num_disks,target);
// tower.display();
// }
// }
  //
  // solve3(tower, start, mid);
  // tower.move(mid,target);
  // tower.display();
  // solve3(tower,target,start);
// if(tower.top_diameter(start) != num_disks && tower.top_diameter(mid) != num_disks && tower.top_diameter(target) != num_disks ){
//   solve(tower,target,mid,num_disks-1,start);
// }

// }

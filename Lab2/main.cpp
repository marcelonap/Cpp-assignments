/* main.cpp
    CMPT 276 Laboratory 2
    Purpose:  The purpose of this file is to run the game and display the solution
    for 3 and 5 disks in the starting peg.

    @Marcelo Napoleao Sampaio
    @14/02/2020
*/
#include"towers.h"
#include<iostream>

using namespace std;

//This function only works with the inputs 3 or 5 because of the reasons we talked about
//in lab, you asked me to place a reminder for you so here it is.

//Preconditions: three valid integers, first is either 3 or 5 (for the reasons we talked about)
//and last two are numbers from 1-3 but different from each other
//Postcondition: displays the solution for a towers of hanoi game starting with 3 or 5 pegs
int hanoi(int num_disks, int start, int target){
  towers tower(num_disks);
  int MIDDLE = 6 - start - target;


  cout<< "Game starting with " << num_disks << " disks in the first peg" << endl;
  tower.display();

  solve3(tower,target,start);


  while(tower.many_disks(target) != num_disks){


    if(tower.many_disks(MIDDLE) == 0 && tower.top_diameter(target) == 1){
        tower.move(start,MIDDLE);
        tower.display();
        solve3(tower,MIDDLE,target);

    }else if(tower.many_disks(target) == 0 && tower.top_diameter(MIDDLE) == 1){
      tower.move(start,target);
      tower.display();
      solve3(tower,start,MIDDLE);
    }

    if(tower.top_diameter(MIDDLE) - tower.top_diameter(target) == -1){
      tower.move(MIDDLE, target);
      tower.display();
      solve3(tower, target, start);
    }
}
//solve(tower, TARGET, START, num_disks); this is my attempt at solving for any
//number of starting disks.


return 0;
}




int main(){

  hanoi(3, 1, 3);

  hanoi(5, 1, 3);


  return 0;
}

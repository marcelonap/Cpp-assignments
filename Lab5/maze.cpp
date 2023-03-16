/*
maze.cpp file Lab5 CMPT276
Marcelo Napoleao Sampaio

14/04/2020
purpose:
This file contain the function implementations for the maze_type class that
we use to navigate and solve a maze imported from a text file


  maze.cpp: Implements the maze_type class, which reads a maze from a
  	text file and wanders through it to find the treasure.

  See maze.h for documentation.

  -RPM 15.03.2016

*/

#include<fstream> // for file input
#include<cassert> // for assert
#include<cstdlib> // for exit

#include "maze.h"
#include "vector2d.h"

using namespace std;


/**********************************************************/
/***           CLASS STATIC MEMBER VARIABLES.           ***/
/**********************************************************/

const vector2d maze_type::UP    = vector2d(0, -1);
const vector2d maze_type::DOWN  = vector2d(0,  1);
const vector2d maze_type::LEFT  = vector2d(-1, 0);
const vector2d maze_type::RIGHT = vector2d( 1, 0);


/**********************************************************/
/***               CLASS MEMBER FUNCTIONS.              ***/
/**********************************************************/

/***********************************/
/***  Constructor  ***/

maze_type::maze_type(const string &maze_filename) {
  // Constructor.  Loads the maze from the given filename, and positions
  // the Hero at the entrance.
  // Uses the exit function from cstdlib.

  string line, lastrow;
  ifstream mazefile(maze_filename.c_str());
  if (!mazefile) {
    cout << "Bork!  Could not open file " << maze_filename << endl;
    exit(EXIT_FAILURE); // exit terminates the program (does not return to main!).
  }

  /////
  // Read the maze from the file.

  dimy = 0; // This will count the number of rows we read in.
  while (mazefile) {
    getline(mazefile, line); // Read one line from the file.
    if (line.empty())
      break;

    // If this is the first line, reserve all the columns we need.
    // Remember that maze is a "vector of vectors" (each element is a vector of char's).
    if (maze.empty()) {
      dimx = line.length();
      maze.resize(dimx);
    }

    // Add each character in this row to the bottom of the appropriate column.
    for (int i = 0; i < line.length(); ++i) {
      maze[i].push_back(line[i]);
    }

    ++dimy; // Count the row.
    lastrow = line;
  } // while (mazefile)

  mazefile.close();

  /////
  // Find the entrance and the goal, and place the Hero.
  // The entrance should be in the last row in the maze.

  for (int iy = 0; iy < dimy; ++iy) {
    for (int ix = 0; ix < dimx; ++ix) {
      if (maze[ix][iy] == ENTRANCE) {
        entrance_pos = vector2d(ix, iy);
      }
      if (maze[ix][iy] == GOAL) {
        goal_pos = vector2d(ix, iy);
      }
    }
  }

  hero_pos = entrance_pos;

  // Start facing up (into the maze).
  face_dir(UP);
  update_hero_char();

  found = false; // Have not yet found the Infinite Well.

  nmoves = 0; // No moves made yet.

} // maze_type::maze_type()



/***********************************/
/***  Accessors ***/

void maze_type::show_maze() const {
  // Display the maze on the screen.

  for (int iy = 0; iy < dimy; ++iy) {
    for (int ix = 0; ix < dimx; ++ix)
        cout << maze[ix][iy];
    cout << endl;
  }
  cout << endl; // blank line
} // maze_type::show_maze()

 bool maze_type::facing_wall() const{
   if (get_facing_dir() == UP) {
    if( get_char(get_x(), get_y() - 1) == WALL){
      return true;
    }
   } else if (get_facing_dir() == DOWN) {
     if( get_char(get_x(), get_y() + 1) == WALL){
       return true;
     }
   } else if (get_facing_dir() == LEFT) {
     if( get_char(get_x() - 1, get_y()) == WALL){
       return true;
     }
   } else if (get_facing_dir() == RIGHT) {
     if( get_char(get_x() + 1, get_y()) == WALL){
       return true;
     }
   }

   return false;
 }

 bool maze_type::facing_seen() const{

   if (get_facing_dir() == UP) {
    if( get_char(get_x(), get_y() - 1) == VISITED){
      return true;
    }
   } else if (get_facing_dir() == DOWN) {
     if( get_char(get_x(), get_y() + 1) == VISITED){
       return true;
     }
   } else if (get_facing_dir() == LEFT) {
     if( get_char(get_x() - 1, get_y()) == VISITED){
       return true;
     }
   } else if (get_facing_dir() == RIGHT) {
     if( get_char(get_x() + 1, get_y()) == VISITED){
       return true;
     }
   }

return false;
 }

 bool maze_type::at_entrance() const{

   return(hero_pos == entrance_pos);
}



/***********************************/
/***  Modifiers ***/

void maze_type::face_dir(const vector2d& dir) {
  // Face the Hero in the given direction.
  facing = dir;
  update_hero_char();
} // maze_type::face_dir()

void maze_type::turn_left(){
  if (get_facing_dir() == UP) {
      facing = LEFT;
      update_hero_char();
  } else if (get_facing_dir() == DOWN) {
    facing = RIGHT;
    update_hero_char();
  } else if (get_facing_dir() == LEFT) {
    facing = DOWN;
    update_hero_char();
  } else if (get_facing_dir() == RIGHT) {
    facing = UP;
    update_hero_char();
  }

}

  void maze_type::turn_right(){
    if (get_facing_dir() == UP) {
        facing = RIGHT;
        update_hero_char();
    } else if (get_facing_dir() == DOWN) {
      facing = LEFT;
      update_hero_char();
    } else if (get_facing_dir() == LEFT) {
      facing = UP;
      update_hero_char();
    } else if (get_facing_dir() == RIGHT) {
      facing = DOWN;
      update_hero_char();
    }
  }



 bool maze_type::move_forward(){
   vector2d initial_pos = get_pos();

   if (get_facing_dir() == UP) {
     if(facing_seen()||facing_empty()){
       hero_pos = hero_pos.add(0, -1);
       update_hero_char();
       set_maze_char(initial_pos, VISITED);
       if(initial_pos == get_well_pos()){
         set_maze_char(initial_pos, GOAL_FOUND);
       }
       if(initial_pos == entrance_pos){
         set_maze_char(entrance_pos, ENTRANCE);
       }
       return true;
     }
   } else if (get_facing_dir() == DOWN) {
     if(facing_seen()||facing_empty()){
       hero_pos =  hero_pos.add(0, 1);
       update_hero_char();
       set_maze_char(initial_pos, VISITED);
       if(initial_pos == get_well_pos()){
         set_maze_char(initial_pos, GOAL_FOUND);
       }
       if(initial_pos == entrance_pos){
         set_maze_char(entrance_pos, ENTRANCE);
       }

       return true;
     }
   } else if (get_facing_dir() == LEFT) {
     if(facing_seen()||facing_empty()){
       hero_pos = hero_pos.add(-1, 0);
       update_hero_char();
       set_maze_char(initial_pos, VISITED);
       if(initial_pos == get_well_pos()){
         set_maze_char(initial_pos, GOAL_FOUND);
       }
       if(initial_pos == entrance_pos){
         set_maze_char(entrance_pos, ENTRANCE);
       }
       return true;
     }
   } else if (get_facing_dir() == RIGHT) {
     if(facing_seen()||facing_empty()){
       hero_pos = hero_pos.add(1, 0);
       update_hero_char();
       set_maze_char(initial_pos, VISITED);
       if(initial_pos == get_well_pos()){
         set_maze_char(initial_pos, GOAL_FOUND);
       }
       if(initial_pos == entrance_pos){
         set_maze_char(entrance_pos, ENTRANCE);
       }
       return true;
     }
   }
   if(initial_pos == entrance_pos){
     set_maze_char(entrance_pos, ENTRANCE);
   }
   if(initial_pos == get_well_pos() ){
     found = true;
     set_maze_char(goal_pos, GOAL_FOUND);
   }
  return false;
 }

bool maze_type::move_backward(){
  vector2d initial_pos = get_pos();

  if (get_facing_dir() == UP) {
    if(facing_seen()||facing_empty()){
      hero_pos = hero_pos.add(0, 1);


      update_hero_char();
      set_maze_char(initial_pos, VISITED);
      return true;
    }
  } else if (get_facing_dir() == DOWN) {
    if(facing_seen()||facing_empty()){
      hero_pos =  hero_pos.add(0, -1);

      update_hero_char();
      set_maze_char(initial_pos, VISITED);
      return true;
    }
  } else if (get_facing_dir() == LEFT) {
    if(facing_seen()||facing_empty()){
      hero_pos = hero_pos.add(1, 0);

      update_hero_char();
      set_maze_char(initial_pos, VISITED);
      return true;
    }
  } else if (get_facing_dir() == RIGHT) {
    if(facing_seen()||facing_empty()){
      hero_pos = hero_pos.add(-1, 0);

      update_hero_char();
      set_maze_char(initial_pos, VISITED);
      return true;
    }
  }
  if(initial_pos == goal_pos ){
    set_maze_char(goal_pos, GOAL_FOUND);
    found = true;

  }
 return false;
}


//This is not working as perfectly as i wish it was but it is doing its job
void maze_type::explore(){

if(found_well() && at_entrance()){
  return;
}else{
show_maze();

// cout<< found << endl << at_entrance() << endl ;




  if(facing_wall()&&move_backward()){
    move_backward();
    turn_left();
    turn_left();
  }


  if(facing_wall()){
    turn_right();
  }
  if(hero_pos.add(0,-1) == entrance_pos){

    return;
  }
 if(move_forward()){
    move_forward();

  }else{
    explore();

  }
  if(hero_pos.add(0,-1) == entrance_pos){

    return;
  }
  if(facing_empty()){
    move_forward();
    explore();

  }else{
    turn_left();
    explore();
  }

  if(hero_pos.add(0,-1) == entrance_pos){

    return;
  }
}


return;
}



/***********************************/
/***  Private member functions  ***/


//////////
void maze_type::set_maze_char(const vector2d& pos, char c) {
  // PRECONDITIONS: pos is a valid maze coordinate; c is a valid maze character.
  // POSTCONDITION: Assigns the character to the given maze position.
  maze[pos.x()][pos.y()] = c;
}


//////////
void maze_type::update_hero_char() {
  // Updates the character representing the Hero so that it points in the correct direction.
  char c = 'X'; // default, should never be used.
  if (facing == UP) {
    c = HERO_U;
  } else if (facing == DOWN) {
    c = HERO_D;
  } else if (facing == LEFT) {
    c = HERO_L;
  } else if (facing == RIGHT) {
    c = HERO_R;
  }
  set_maze_char(hero_pos, c);
}

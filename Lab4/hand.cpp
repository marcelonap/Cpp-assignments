/*
  hand.cpp file Lab4 CMPT276
  Marcelo Napoleao Sampaio

  27/03/2020
  purpose:
  This file contain the function implementations for the Hand_type class
  which is designed to hold playing cards as a linked ordered list.


  CLASS INVARIANTS:
  - Cards are stored in card_node objects in a linked list.
  - head_ptr points to the first node in the list, or NULL if the list is empty.
  - Each node in the list contains a pointer to the next node, or NULL if it's the last node in the list.
  - Cards are stored in increasing order, with the "lowest" card at the head.
*/

#include <iostream> // for debugging
#include <string>

#include "hand.h"
#include "card.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
// HAND_TYPE MEMBERS

//////////////////////////////////////////////////
// Constructor
hand_type::hand_type(){
  head_ptr = NULL;
  tail_ptr = NULL;
  num_cards = 0;
}



//////////////////////////////////////////////////
// Destructor

hand_type::~hand_type(){
  discard_hand();
}



//////////////////////////////////////////////////
// Getters
size_t hand_type::size() const{
  return num_cards;
}

 bool hand_type::is_empty() const{
   return num_cards == 0;
 }

bool hand_type::has_card(card_type target) const{
 card_node *current =  head_ptr;

  while(current){
    if(current->card == target){
      return true;
    }
    current = current->link_ptr;
  }
  return false;
}

string hand_type::to_string() const{
  card_node *current = head_ptr;
  string output = "";

  while(current){
    output += (current->card).to_string() + " ";
    current = current->link_ptr;
  }
   return output;
}

//////////////////////////////////////////////////
// Modifiers
void hand_type::add_card(const card_type &newcard){
  card_node *newNode_ptr = new card_node;
  newNode_ptr->card = newcard;
  newNode_ptr->link_ptr = NULL;
  card_node *current = head_ptr;
  
//Making the list store the cards in order (this was by far the hardets part but i got it working).
    if(is_empty()){
      head_ptr = newNode_ptr;

    }else{
      if(newcard >= tail_ptr->card){
        tail_ptr->link_ptr = newNode_ptr;
        tail_ptr = newNode_ptr;
        ++num_cards;
        return;
      }else if(newcard <= head_ptr->card){
        newNode_ptr->link_ptr = current;
        head_ptr = newNode_ptr;
        ++num_cards;
        return;
      }else{
        while(current){

          if(newcard >= current->card && newcard <= current->link_ptr->card){

            newNode_ptr->link_ptr = current->link_ptr;
            current->link_ptr = newNode_ptr;
            ++num_cards;
            return;
          }
          current = current->link_ptr;
        }
      }

      tail_ptr->link_ptr = newNode_ptr;
    }

     tail_ptr = newNode_ptr;
     ++num_cards;

}

void hand_type::remove_card(const card_type &target){
   card_node *current =  head_ptr;
   card_node *target_ptr = NULL;
   card_node *prev_ptr = NULL;

  while(current && !target_ptr){
    if(current->card == target){
      target_ptr = current;
    }else{
      prev_ptr = current;
      current = current->link_ptr;
    }
  }

  if(target_ptr == head_ptr){
    head_ptr = target_ptr->link_ptr;
  }else{
    prev_ptr->link_ptr = target_ptr->link_ptr;
}

  delete target_ptr;
  --num_cards;

  return;

 }

void hand_type::discard_hand(){
  card_node *target_ptr;

  while(head_ptr){
    target_ptr = head_ptr;
    head_ptr = head_ptr->link_ptr;
    delete target_ptr;
  }

  num_cards = 0;
}



//////////////////////////////////////////////////
// Private member functions (if any)




//////////////////////////////////////////////////////////////////////////
// CARD_NODE CONSTRUCTORS

hand_type::card_node::card_node() {
  link_ptr = NULL;
}

hand_type::card_node::card_node(const card_type &newcard, card_node *next_ptr) {
  card = newcard;
  link_ptr = next_ptr;
}

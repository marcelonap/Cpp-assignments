/*

  hand.h file Lab4 CMPT276
  Marcelo Napoleao Sampaio

  27/03/2020
  purpose:
  This file contain the class definition for the hand class


  ///////////DOCUMENTATION/////////////////////
    Constructor & destructor:
    No pre or postconditions.


  **********************Getters***********************

  size_t size() const;
  PRECONDITIONS: None.
  POSTCONDITIONS: Returns the number of cards in the hand.

  bool has_card(card_type target) const;
  PRECONDITIONS: Valid card_type input.
  POSTCONDITIONS: Returns true if the object contains the given parameter or
  false if it does not.

  bool is_empty() const;
  PRECONDITIONS: None.
  POSTCONDITIONS:Returns true if there are no cards in the hand or
  false if there are any.

  string to_string() const;
  PRECONDITIONS: None.
  POSTCONDITIONS: Returns the cards in the object as a string, separated by a space.

   ******************Modifiers******************
  void add_card(const card_type &newcard);
  PRECONDITIONS: Valid card_type object input. 
  POSTCONDITIONS: Adds a card to the object in the right place following the 
  given order.

  void remove_card(const card_type &target);
  PRECONDITIONS:  Valid card_type object input.
  POSTCONDITIONS: Removes a specific card from the object.

  void discard_hand();
  PRECONDITIONS: Object needs to have at least a card.
  POSTCONDITIONS: Deletes all the cards in the hand.
  
  

*/

#ifndef __HAND_H__
#define __HAND_H__

#include <string>
#include "card.h"

using namespace std;

class hand_type {
public:
  
  //////////////////////////////////////////////////
  // Constructor & destructor
  hand_type();
  ~hand_type();
   
  //////////////////////////////////////////////////
  // Getters
  size_t size() const;
  bool has_card(card_type target) const;
  bool is_empty() const;
  string to_string() const;
  
  
  //////////////////////////////////////////////////
  // Modifiers
  void add_card(const card_type &newcard);
  void remove_card(const card_type &target);
  void discard_hand();
  
  
private:
  
  //////////////////////////////////////////////////
  // Node struct for storing a card in the linked list.
  // (Normally this would be a class since it has functions (constructors),
  // but since those are just used to initialize the members we might as well
  // keep it a struct.)
  struct card_node {
    card_type card;
    card_node *link_ptr;
    card_node();
    card_node(const card_type &newcard, card_node *next_ptr = NULL);
  };
  
  card_node *head_ptr; // First card in the hand. 
  card_node *tail_ptr; // Last card in the hand
  size_t num_cards; // Number of cards in the hand.
  
};



#endif  // defined __HAND_H__

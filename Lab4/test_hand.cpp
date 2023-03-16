/*
testy_hand.cpp file Lab4 CMPT276
Marcelo Napoleao Sampaio

27/03/2020
purpose:
This file is the test file for the hand and card classes.
*/

#include <iostream>
#include <sstream> // for stringstream, for capturing output.

#include "hand.h"
#include "card.h"
#include "checktest.h"

using namespace std;

int main() {

  // Create some cards to work with.
  card_type heartsA("A", "H"); // Highest possible card.
  card_type heartsQ("Q", "H");
  card_type diamondsA("A", "D");
  card_type diamonds10("10", "D");
  card_type diamonds4("4", "D");
  card_type spadesA("A", "S");
  card_type spadesQ("Q", "S");
  card_type spades2("2", "S");
  card_type clubsA("A", "C");
  card_type clubs9("9", "C");
  card_type clubs2("2", "C"); // Lowest possible card.

//creating 2 hand objects to test our classes.
  hand_type hand1;
  hand_type hand2;
  //adding a few cards to the first hand
  hand2.add_card(spades2);
  hand2.add_card(diamonds10);
  hand2.add_card(clubsA);
cout << "hand2 size = " << hand2.size() << endl;
cout << "hand2 has an ace of Hearts? " << hand2.has_card(heartsA) << endl;


  hand1.add_card(heartsA);
  hand1.add_card(diamonds4);
  hand1.add_card(spadesQ);
  hand1.add_card(clubs9);
  hand1.add_card(spades2);
  hand1.add_card(heartsQ);
  hand1.add_card(diamonds10);
  hand1.add_card(spadesQ);
  hand1.add_card(clubs9);
  hand1.add_card(spades2);
  hand1.add_card(heartsA);
  hand1.add_card(diamonds4);
  hand1.add_card(spadesQ);
  hand1.add_card(clubsA);
  hand1.add_card(spades2);
  hand1.add_card(heartsA);
  hand1.add_card(diamonds10);
  hand1.add_card(spadesQ);
  hand1.add_card(clubs2);
  hand1.add_card(spades2);
  hand1.add_card(heartsA);
  hand1.add_card(diamonds4);
  hand1.add_card(spadesQ);
  hand1.add_card(clubs9);
  hand1.add_card(spades2);
  hand1.add_card(heartsQ);
  hand1.add_card(diamonds4);
  hand1.add_card(spadesQ);
  hand1.add_card(clubsA);
  hand1.add_card(spades2);

cout << "Is hand1 empty? " << hand1.is_empty() << endl;
cout << "hand1 size = " << hand1.size() << endl;
cout << "Hand1 has an Ace of hearts? " << hand1.has_card(heartsA) << endl;

  cout << "hand1: " << hand1.to_string() << endl;
  cout << "hand2: " << hand2.to_string() << endl;


  // For capturing non-string output.
  stringstream result;


  return 0;
}

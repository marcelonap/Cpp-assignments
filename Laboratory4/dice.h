/**
    dice.h
    CMPT 275 Laboratory 4
    Purpose: This is a header file for the dice.cpp program which uses the functions 
    that were declared here. The function prototypes are declared here so that we can use them
    in the order that we want to to make the program work	

    Marcelo Napoleao Sampaio
    31/10/2019
*/

#include <iostream>
#include <stdlib.h>


int rollDie(unsigned int);

void initializeRNG(int);

void printRules(unsigned int,int,int,unsigned int,int);

void printHeader(int, int);

int roll_n_print_dice(unsigned int);

int get_n_print_Result(int, int);

void printFinalMessage(int, unsigned int, int, int);

bool gameOver(int, int,int, unsigned int);

void playGame(unsigned int,int,int,unsigned int,int);

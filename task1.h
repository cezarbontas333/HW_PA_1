#ifndef TASK1_H
#define TASK1_H

#include "declarations.h"

/**
 * Test pointer that it is correctly allocated in the program.
**/
void TestAllocation(void *pointer);

/**
 * For allocating and reading a string with whitespaces.
**/
char* ReadStringWSBuffer(FILE *input_stream);

/**
 * For allocating and reading a string.
**/
char* ReadStringBuffer(FILE *input_stream);

/**
 * Adds a new team entry in the team list. It is the main list used to store all the data
 * needed.
**/
team_node* AddAtBeginningTeam(team_node* head, FILE *input_stream);

/**
 * This is the main function for the first task of the LanParty problem. Contains all the other 
 * functions written above.
**/
void Task1(unsigned int *team_number, team_node **team_list, char *filename);

#endif
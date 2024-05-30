#ifndef TASK3_H
#define TASK3_H

#include "declarations.h"

/**
 * As requested, a stack structure for teams. There will be 2 stacks that will 
 * remember addresses of teams to be reused/deleted.
**/
typedef struct stack
{
    team_node *address;
    struct stack *next;
}team_stack;

/**
 * It is no different than adding an element at the beginning of a list.
**/
void Push(team_stack **top, team_node *to_be_added);

/**
 * Pops the top of a stack. Returns the address of the team node for further 
 * processing.
**/
team_node* Pop(team_stack **top);

/**
 * An element for the actual queue. It 
**/
typedef struct queue_node
{
    struct queue_node *next;
    team_node *address;
}queue_node;

/**
 * As requested, a queue structure for teams. In this way we can organize
 * much more easier the way the matches take place.
**/
typedef struct queue
{
    queue_node *front, *rear;
}team_queue;

/**
 * Adds to the rear of the quque. The closest 2 teams in a queue form a pair
 * that plays in a match, which decides who loses and who wins.
**/
void EnQueue(team_queue **the_queue, team_node *to_be_added);

/**
 * Removes the first element in the queue. This happens in the same time as 
 * the team is placed in the "losing" stack or the "winning" one.
**/
team_node* DeQueue(team_queue **the_queue);

/**
 * Compares 2 teams to see who should go to the losers' stack or the winners'
 * one. It just looks if the order that the teams came in is in ascending
 * order. If there is a stalemate, "one" should be decided as winner.
**/
int CompareTeams(team_node *one, team_node *other_one);

/**
 * This function places the teams in the corresponding stacks. For the winning
 * stack, the fucntion adds a point to each of their members. It returns the 
 * address of the losing team so it can be removed fromt the team list later.
**/
void MakeStacks(team_stack **winners, team_stack **losers, team_node *first, team_node *second, short ordered);

/**
 * The main function to solve the third task.
**/
void Task3(team_node **team_list, unsigned int *team_number, FILE* write_result);

#endif
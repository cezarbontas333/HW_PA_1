#ifndef TASK2_H
#define TASK2_H

#include "declarations.h"

/**
 * Calculates the average score of a team and returns it. It is mainly used to see which
 * of the teams has the lowest points in the team.
**/
float CalculateAveragePointsTeam(player *array, int player_number);

/**
 * Frees all the elements a team has (such as the name and each element of the player
 * array).
**/
void FreeTeamMemory(team_node *to_be_freed);

/**
 * Deletes the node of a team in a team list. Looks for exceptions like when the node to be
 * deleted is a head, which makes the next node after the head to be promoted to the new head.
**/
team_node* DeleteTeamNode(team_node *to_be_deleted, team_node *head);

/**
 * Searches the node in the list of teams for the lowest average, calculated using the
 * CalculateAveragePointsTeam() function. When it finds it, the node is deleted.
**/
team_node* SearchLowestScoreTeamNode(team_node *head);

/**
 * Looks for the lowest ranked teams and eliminates them from the list of teams. Does this
 * until there is an exact power of 2 in order to form a tournament type of contest.
**/
void Task2(unsigned int *team_number, team_node **team_list);

#endif
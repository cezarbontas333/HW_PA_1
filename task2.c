#include <stdio.h>
#include <stdlib.h>
#include "task2.h"
#include <float.h>
#include <math.h>
#include <limits.h>

float CalculateAveragePointsTeam(player *array, int player_number)
{
    float average = 0;
    for(int i = 0; i < player_number; i++)
        average += array[i].points;
    average /= player_number;
    return average;
}

void FreeTeamMemory(team_node *to_be_freed)
{
    free(to_be_freed->name);
    for(int i = 0; i < to_be_freed->player_number; i++)
    {
        free(to_be_freed->array[i].name);
        free(to_be_freed->array[i].surname);
    }
    free(to_be_freed->array);
    free(to_be_freed);
}

team_node* DeleteTeamNode(team_node *to_be_deleted, team_node *head)
{
    if(to_be_deleted == NULL || head == NULL)
        return head;
    //Re-links the nodes in the list in order to be deleted.  
    if(to_be_deleted == head)
        head = head->next;
    else
    {
        team_node *current;
        for(current = head; current->next != to_be_deleted; current = current->next);
        current->next = current->next->next;
    }
    FreeTeamMemory(to_be_deleted);
    return head;
}

team_node* SearchLowestScoreTeamNode(team_node *head)
{
    team_node *current, *to_be_eliminated;
    float minimum = FLT_MAX;
    for(current = head; current != NULL; current = current->next)
    {
        //Calculates all the averages and finds the minimum.
        float average = CalculateAveragePointsTeam(current->array, current->player_number);
        if(minimum > average && fabs(minimum - average) > FLT_EPSILON)
        {
            to_be_eliminated = current;
            minimum = average;
        }
    }
    return to_be_eliminated;
}

void Task2(unsigned int *team_number, team_node **team_list)
{
    //Calculates the highest power of 2 smaller than the actual team number.
    unsigned int maxn = 1;
    for(int i = 0; i < sizeof(maxn) * 8; i++)
    {
        unsigned int new_maxn = maxn << 1;
        if(new_maxn > *team_number)
            break;

        maxn = new_maxn;
    }

    //Eliminates teams until there is a power of 2.
    while(*team_number > maxn)
    {
        team_node *to_be_deleted = SearchLowestScoreTeamNode(*team_list);
        *team_list = DeleteTeamNode(to_be_deleted, *team_list);
        (*team_number)--;
    }
    return;
}
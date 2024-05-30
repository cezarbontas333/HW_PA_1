#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"
#include "task2.h"
#include "task1.h"

void Push(team_stack **top, team_node *to_be_added)
{
    if(*top == NULL)
    {
        *top = malloc(sizeof(team_stack));
        (*top)->next = NULL;
        (*top)->address = to_be_added;
    }
    else
    {
        team_stack *new_top = malloc(sizeof(team_stack));
        new_top->next = *top;
        new_top->address = to_be_added;
        *top = new_top;
    }
    return;
}

team_node* Pop(team_stack **top)
{
    team_node *result = (*top)->address;
    team_stack *to_be_deleted = *top;
    *top = (*top)->next;
    free(to_be_deleted);
    return result;
}

void EnQueue(team_queue **the_queue, team_node *to_be_added)
{
    if(*the_queue == NULL)
    {
        *the_queue = malloc(sizeof(team_queue));
        (*the_queue)->front = (*the_queue)->rear = NULL;
    }
    queue_node *new_element = malloc(sizeof(queue_node));
    new_element->address = to_be_added;
    new_element->next = NULL;
    if((*the_queue)->rear == NULL)
        (*the_queue)->rear = new_element;
    else
    {
        (*the_queue)->rear->next = new_element;
        (*the_queue)->rear = new_element;
    }
    if((*the_queue)->front == NULL)
        (*the_queue)->front = new_element;
}

team_node* DeQueue(team_queue **the_queue)
{
    team_node *result = (*the_queue)->front->address;
    if((*the_queue)->front == (*the_queue)->rear)
    {
        free((*the_queue)->front);
        free(*the_queue);
        *the_queue = NULL;
    }
    else
    {
        queue_node *to_be_deleted = (*the_queue)->front;
        (*the_queue)->front = (*the_queue)->front->next;
        free(to_be_deleted);
    }
    return result;
}

int CompareTeams(team_node *one, team_node *other_one)
{
    return CalculateAveragePointsTeam(one->array, one->player_number) > CalculateAveragePointsTeam(other_one->array, other_one->player_number);
}

void MakeStacks(team_stack **winners, team_stack **losers, team_node *first, team_node *second, short ordered)
{
    if(ordered)
    {
        Push(winners, first);
        Push(losers, second);
    }
    else
    {
        Push(winners, second);
        Push(losers, first);
    }
}

void Task3(team_node **team_list, unsigned int *team_number, FILE* write_result)
{
    team_queue *matches = NULL;
    team_stack *winners = NULL, *losers = NULL;
    for(team_node *current = (*team_list); current != NULL; current = current->next)
        EnQueue(&matches, current);


    int round_no = 1;
    while(*team_number > 1)
    {
        fprintf(write_result, "\n--- ROUND NO:%d\n", round_no);
        while(matches)
        {
            team_node *first = DeQueue(&matches), *second = DeQueue(&matches);
            MakeStacks(&winners, &losers, first, second, CompareTeams(first, second));
            fprintf(write_result, "%-33s-%33s\n", first->name, second->name);
        }

        while(losers)
        {
            team_node *losing_team = Pop(&losers);
            *team_list = DeleteTeamNode(losing_team, *team_list);
            (*team_number)--;
        }

        fprintf(write_result, "\nWINNERS OF ROUND NO:%d\n", round_no);
        while(winners)
        {
            team_node *team = Pop(&winners);
            for(int i = 0; i < team->player_number; i++)
                team->array[i].points++;

            fprintf(write_result, "%-34s-  %.2f\n", team->name, CalculateAveragePointsTeam(team->array, team->player_number));
            EnQueue(&matches, team);
        }

        round_no++;
    }
    while(matches != NULL)
        DeQueue(&matches);
}
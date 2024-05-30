#include <stdio.h>
#include <stdlib.h>
#include "task1.h" 
#include "task2.h"
#include "task3.h"

void PrintResult(team_node *list, unsigned int team_number, FILE *write_result)
{
    team_node *current;
    for(current = list; current != NULL; current = current->next)
    {
        float avg = CalculateAveragePointsTeam(current->array, current->player_number);
        // fprintf(write_result, "%s, %d, %f\n", current->name, current->player_number, avg);
        fprintf(write_result, "%s\n", current->name);
    }
}

/**
 * To be noted that the argv[] gets the names of the files in this order:
 * - argv[1] -> has the file containing whether a task is executed or not;
 * - argv[2] -> has the file containing all the data necessary for completing the tasks, where it 
 * can read data for players, teams, number of teams;
 * - argv[3] -> is the name of the file where the output is written.
 * Writing the files in a different order will cause unexpected behaviour, so please keep that in 
 * mind when testing/using the program.
**/
int main(int argc, char *argv[])
{
    team_node *global_list = NULL;
    unsigned int global_team_number = 0;
    short task_do, magic_number = 0;
    FILE *read_tasks;
    if((read_tasks = fopen(argv[1], "rt")) == NULL)
    {
        printf("\"%s\" cannot be opened. Program aborted.", argv[1]);
        exit(1);
    }
    for(int i = 1; i <= 5; i++)
    {
        fscanf(read_tasks, "%hd", &task_do);
        if(task_do)
            magic_number += task_do;
    }
    fclose(read_tasks);

    FILE *write_result;
    if((write_result = fopen(argv[3], "wt")) == NULL)
    {
        printf("\"%s\" cannot be opened. Program aborted.", argv[3]);
        exit(1);
    }

    // For task selection
    if(magic_number >= 1)
    {
        Task1(&global_team_number, &global_list, argv[2]);

        if(magic_number == 1)
            PrintResult(global_list, global_team_number, write_result);
    }

    if(magic_number >= 2)
    {
        Task2(&global_team_number, &global_list);
        PrintResult(global_list, global_team_number, write_result);
    }

    if(magic_number >= 3)
    {
        Task3(&global_list, &global_team_number, write_result);
    }

    if(magic_number >= 4)
    {
        // Task4();
    }

    if(magic_number >= 5)
    {
        // Task5();
    }

    // eliberare memorie
    while (global_list != NULL)
        global_list = DeleteTeamNode(global_list, global_list);

    fclose(write_result);
    return 0;
}
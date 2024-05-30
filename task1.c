#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "task1.h"

void TestAllocation(void *pointer)
{
    if(pointer == NULL)
    {
        printf("Pointer at address %p was not properly allocated. Program aborted.", pointer);
        exit(1);
    }
    return;
}

char* ReadStringWSBuffer(FILE *input_stream)
{
    char buffer[200];
    fgets(buffer, 200, input_stream);

    int i;
    for(i = strlen(buffer) - 1; i >= 0 && isspace(buffer[i]); i--);
    buffer[i + 1] = '\0';

    char *to_be_read = calloc(strlen(buffer)+1, sizeof(char));
    TestAllocation(to_be_read);
    strcpy(to_be_read, buffer);
    return to_be_read;
}

char* ReadStringBuffer(FILE *input_stream)
{
    char buffer[200];
    fscanf(input_stream, "%s", buffer);
    char *to_be_read = calloc(strlen(buffer)+1, sizeof(char));
    TestAllocation(to_be_read);
    strcpy(to_be_read, buffer);
    return to_be_read;
}

team_node* AddAtBeginningTeam(team_node *head, FILE *input_stream)
{
    if(head == NULL) //The list is not created yet.
    {
        head = malloc(sizeof(team_node));
        TestAllocation(head);
        head->next = NULL;
    }
    else //Adds the new element to the head of the list.
    {
        team_node *new_head = malloc(sizeof(team_node));
        TestAllocation(new_head);
        new_head->next = head;
        head = new_head;
    }
    //Reads from the specified file the team info.
    fscanf(input_stream, "%d", &head->player_number);
    // Accounts for the whitespace between
    getc(input_stream); // I hate whitespaces so much!
    head->name = ReadStringWSBuffer(input_stream);
    return head;
}

void Task1(unsigned int *team_number, team_node **team_list, char *filename)
{
    FILE *read_file;
    if((read_file = fopen(filename, "rt")) == NULL)
    {
        printf("\"%s\" cannot be opened! Program aborted.", filename);
        exit(1);
    }
    fscanf(read_file, "%d", team_number);
    for(int i = 0; i < *team_number; i++)
    {
        *team_list = AddAtBeginningTeam(*team_list, read_file);
        (*team_list)->array = calloc((*team_list)->player_number, sizeof(player));
        for(int j = 0; j < (*team_list)->player_number; j++)
        {
            (*team_list)->array[j].surname = ReadStringBuffer(read_file);
            (*team_list)->array[j].name = ReadStringBuffer(read_file);
            fscanf(read_file, "%d", &(*team_list)->array[j].points);
        } 
    }
    fclose(read_file);
    return;
}
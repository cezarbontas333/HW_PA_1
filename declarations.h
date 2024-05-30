#ifndef DECLARATIONS_H
#define DECLARATIONS_H

/**
 * The "player" structure will be mainly used with the "team" structure as an
 * array to store all the players' information. It is implemented in this way as
 * the list of players does not modify in size after it is initially created or
 * until memory is freed up.
**/
typedef struct player
{
    char *name, *surname;
    unsigned int points;
}player;

/**
 * The "team" structure is made as a node of a simple linked list; the idea behind 
 * this implementation is because the list of teams that are in the tournament does
 * change often, and such deleting nodes from a linked list is a faster approach 
 * than resizing arrays.
**/
typedef struct team
{
    char *name;
    unsigned int player_number;
    struct team *next;
    player *array;
}team_node;

#endif
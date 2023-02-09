#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#define MAXSIZE 256

typedef struct
{
    char name[MAXSIZE];
    int score;
    int moves;
    int len_of_name;
}
player;

typedef struct
{
    char name[MAXSIZE];
    int score;
    int len_of_name;
}
user;



#endif // STRUCTURES_H_INCLUDED

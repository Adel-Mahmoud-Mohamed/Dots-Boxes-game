#include <stdio.h>

#include <stdlib.h>

#include<stdbool.h>

#include<windows.h>

#include<math.h>

#include<string.h>

#include<time.h>

#include "game_function.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"







int main()
{
    system("");
    while (true)
    {
        int option;
        printf(ANSI_COLOR_YELLOW);
        printf("\n \t \t\t\t\tDOTS AND BOXES\n\n \t \t\t\t\tMAIN MENU\n\n");
        printf("\t new game(enter:1):\n\n\t loading the game(enter:2):\n\n\t top ten players(enter:3):\n\n\t exit(enter:4);\n\n\t enter your choice:");
        scanf("%d", & option);
        printf(ANSI_COLOR_RESET);
        system("cls");
        user array_of_users[MAXSIZE] =
        {
            0
        }; //array of structure of users which we use to display the top ten

        FILE * reading_users;
        reading_users = fopen("u.txt", "r");
        //this will return NULL in case of null file and pointer to the file in case of the file exists
        if (reading_users == NULL)
        {
            printf("users file is not here so we'll have it initialized\n"); //so we'll initialize it
            reading_users = fopen("u.txt", "w");
            fclose(reading_users);
            reading_users = fopen("u.txt", "r");
        } //if this condition fulfilled then we'll create users file named s.text

        //we initialized it and had it opened to read from it

        int i = 0;
        while (!feof(reading_users))
        {
            fread( & array_of_users[i].len_of_name, sizeof(int), 1, reading_users);
            fread(array_of_users[i].name, sizeof(char), array_of_users[i].len_of_name, reading_users);
            array_of_users[i].name[array_of_users[i].len_of_name] = '\0';
            fread( & array_of_users[i].score, sizeof(int), 1, reading_users);
            i++;
        }
        fclose(reading_users);

        int difficulty, no_of_players, n;
        player player1, player2;
        int game_outcome, loadedtime = 0, data_each_move = 5;
        //we declared them here to make them seen by the blocks beneath

        if (option == 1)   //new game has emerged
        {
            //fseek(f,0,SEEK_END);
            //fprintf(f,"New game has been selected\n");
            player1.score = 0, player2.score = 0, player1.moves = 0, player2.moves = 0; //at the beginning of a new game we must have'em all zeros
            printf(ANSI_COLOR_GREEN "Enter the difficulty\n\n");
            printf("for beginner press 2 or for expert press 5\n\n");
            printf("enter your choice: ");
            scanf("%d", & difficulty);
            if (difficulty != 2 && difficulty != 5)
            {
                while (1)
                {
                    printf("please enter a valid number: ");
                    scanf("%d", & difficulty);
                    if (difficulty == 2 || difficulty == 5) break;
                }
            }
            //fseek(f,0,SEEK_END);
            //fprintf(f,"Grid %d X %d has been selected\n",difficulty+1,difficulty+1);
            system("cls");

            printf("enter number of players (press 1 for one player or 2 for two players): \n");

            scanf("%d", & no_of_players);

            if (no_of_players != 1 && no_of_players != 2)
            {
                while (1)
                {

                    printf("please enter a valid number: ");

                    scanf("%d", & no_of_players);

                    if (no_of_players == 1 || no_of_players == 2) break;
                }
            }

            printf(ANSI_COLOR_RESET);
            system("cls");

            if (no_of_players == 2)
            {
                //fseek(f,0,SEEK_END);
                //fprintf(f,"There are 2 players in Game\n");
                printf(ANSI_COLOR_RED "enter the first player's name: ");
                fflush(stdin);
                gets(player1.name);
                //fseek(f,0,SEEK_END);
                //fprintf(f,"Player 1 name:%s\n",player1.name);
                printf(ANSI_COLOR_RESET);
                printf("\n\n\n");
                printf(ANSI_COLOR_BLUE "enter the first player's name: ");
                fflush(stdin);
                gets(player2.name);
                //fseek(f,0,SEEK_END);
                //fprintf(f,"Player 1 name:%s\n",player1.name);
                printf(ANSI_COLOR_RESET);
                //fclose(f);
                system("cls");
            }
            else if (no_of_players == 1)
            {
                printf(ANSI_COLOR_RED "enter the player's name: ", player1.name);
                fflush(stdin);
                gets(player1.name);
                printf(ANSI_COLOR_RESET);
                system("cls");
                strcpy(player2.name, "computer");

            }

            strlwr(player1.name);
            strlwr(player2.name);

            char Grid[3 * difficulty + 2][5 * difficulty + 2];

            Grid_initializer(difficulty, Grid);

            int rows = ((3 * difficulty) + 2);

            int col = ((5 * difficulty) + 2);

            const int totalMoves = (16 * difficulty) - 20;

            const int data_each_moves = 5;

            int currentMoves = 0;

            int movesArr[totalMoves][data_each_moves];

            for (int i = 0; i < totalMoves; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    movesArr[i][j] = 0;
                }
            }
            player1.len_of_name = strlen(player1.name);
            player2.len_of_name = strlen(player2.name);
            n = 2;

            game_outcome = our_game(no_of_players, difficulty, rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, & player1.score, & player2.score, MAXSIZE, player1.len_of_name, player2.len_of_name, player1.name, player2.name, player1.moves, player2.moves, loadedtime, n);
        }
        if (option == 2)   //for loading the saved game if it exists
        {
            int save_number;
            printf("please enter the save number(1 or 2 or 3): ");
            scanf("%d", & save_number);
            if (save_number == 1 || save_number == 2 || save_number == 3)   //the user entered valid number for the file but we don't know if it does exist or not
            {
                system("cls");
                char file_name[5];
                sprintf(file_name, "%d.txt", save_number);
                FILE * loading_game;
                loading_game = fopen(file_name, "r"); //open that file that we  don't know if it does exist or not for reading
                if (loading_game == NULL)   //if this is true then the file dosn't exist so we tell the user to return back to the main menu
                {
                    printf("file dose not exist");
                }
                else
                {
                    //so file exists but we don't know if it's empty or not
                    int file_size = ftell(loading_game);
                    if (file_size == 0)   //the file exists but empty
                    {
                        printf("file is empty, please press 1 to return back to the main menu or 0 to exit: ");
                        int fork;
                        scanf("%d", & fork);
                        if (fork != 1 && fork != 0)
                        {
                            while (true)
                            {
                                printf("please enter a valid choice: ");
                                scanf("%d", & fork);
                                if (fork == 1 || fork == 0) break;
                            }
                        }
                        if (fork == 1) continue;
                        else if (fork == 0) return 0;
                    }
                    else     //this means that the given file contains data so we'll start to get it out of there the same way we saved them
                    {

                        fclose(loading_game);
                        fopen(file_name, "r");
                    }
                    fread( & loadedtime, sizeof(int), 1, loading_game);
                    fread( & difficulty, sizeof(int), 1, loading_game);
                    fread( & no_of_players, sizeof(int), 1, loading_game);
                    int rows = (3 * difficulty) + 2, col = (5 * difficulty) + 2, totalMoves = (16 * difficulty) - 20, currentMoves;
                    fread( & currentMoves, sizeof(int), 1, loading_game);
                    fread( & player1.moves, sizeof(int), 1, loading_game);
                    fread( & player2.moves, sizeof(int), 1, loading_game);
                    fread( & player1.score, sizeof(int), 1, loading_game);
                    fread( & player2.score, sizeof(int), 1, loading_game);
                    fread( & n, sizeof(int), 1, loading_game);
                    int movesArr[totalMoves][5];
                    fread(movesArr, sizeof(int), totalMoves * 5, loading_game);
                    char Grid[((3 * difficulty) + 2)][((5 * difficulty) + 2)];
                    fread(Grid, sizeof(char), ((3 * difficulty) + 2) * ((5 * difficulty) + 2), loading_game);
                    fread( & player1.len_of_name, sizeof(int), 1, loading_game);
                    fread(player1.name, sizeof(char), player1.len_of_name, loading_game);
                    player1.name[player1.len_of_name] = '\0'; //to help printing
                    if (no_of_players == 2)   //we saved the second name only in case of two players
                    {
                        fread( & player2.len_of_name, sizeof(int), 1, loading_game);
                        fread(player2.name, sizeof(char), player2.len_of_name, loading_game);
                        player2.name[player2.len_of_name] = '\0';
                    }
                    else if (no_of_players == 1)
                    {
                        strcpy(player2.name, "computer");
                    }
                    player2.len_of_name = strlen(player2.name); //anyway this would be the length
                    strlwr(player1.name);
                    strlwr(player2.name);
                    game_outcome = our_game(no_of_players, difficulty, rows, col, Grid, totalMoves, data_each_move, movesArr, currentMoves, & player1.score, & player2.score, MAXSIZE, player1.len_of_name, player2.len_of_name, player1.name, player2.name, player1.moves, player2.moves, loadedtime, n);
                }
            }
        }
        if (option == 1 || option == 2)   //then we dived into the game once either in a new game or in a loading one and we ended up with one winner or a tie then we have things to do with the array of users right !!
        {
            if (game_outcome == 1)   //the first player is the winner
            {
                int i = 0, flag = 0;
                while (array_of_users[i].len_of_name != 0)
                {
                    if (strcmp(player1.name, array_of_users[i].name) == 0)   //this means that the player played before
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        i++;
                        if (i == MAXSIZE)   //the 1st condition is false till the end of the array so we'll remove all data
                        {
                            for (int j = 0; j < MAXSIZE; j++)
                            {
                                array_of_users[j].len_of_name = 0;
                            }
                            i = 0;
                        }
                    }
                }
                if (flag)   //this means the the player has an existing structure so we'll compare his score
                {
                    if (array_of_users[i].score < player1.score)
                    {
                        array_of_users[i].score = player1.score;
                    }
                }
                else     //that means that the player hasn't played before so we'll create him a struct in the array
                {
                    array_of_users[i].len_of_name = player1.len_of_name;
                    array_of_users[i].score = player1.score;
                    strcpy(array_of_users[i].name, player1.name);
                }
            }
            if (no_of_players == 2 && game_outcome == 2)
            {
                int i = 0, flag = 0;
                while (array_of_users[i].len_of_name != 0)
                {
                    if (strcmp(array_of_users[i].name, player2.name) == 0)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {

                        i++;

                    }
                }
                if (flag)
                {
                    if (array_of_users[i].score < player2.score)
                    {
                        array_of_users[i].score = player2.score;
                    }

                }
                else
                {
                    array_of_users[i].len_of_name = player2.len_of_name;
                    array_of_users[i].score = player2.score;
                    strcpy(array_of_users[i].name, player2.name);
                }
            }
            //after that we got some data to write into the file of users
            FILE * user_writing;
            user_writing = fopen("u.txt", "w");
            int i = 0;
            while (i < MAXSIZE && array_of_users[i].len_of_name != 0)
            {
                fwrite( & array_of_users[i].len_of_name, sizeof(int), 1, user_writing);
                fwrite(array_of_users[i].name, sizeof(char), array_of_users[i].len_of_name, user_writing);
                fwrite( & array_of_users[i].score, sizeof(int), 1, user_writing);
                i++;
            }
            fclose(user_writing);

            printf("\n\nenter 1 to return to main menu\nenter 2 to exit\n");
            while (1)
            {
                char returnkey;
                scanf("%c", & returnkey);
                if (returnkey == '1')
                {

                    system("cls");
                    break;
                }
                else if (returnkey == '2')
                    return 0;
            }
        }
        else if (option == 3)
        {
            sorting_array_of_structs(array_of_users);
            for (int i = 0; i < 10; i++)
            {
                printf("%d:", i + 1);
                for (int j = 0; array_of_users[i].name[j] != '\0'; j++)
                {
                    printf("%c", array_of_users[i].name[j]);
                }
                printf("  %d\n", array_of_users[i].score);
            }
            printf("\npress 1 to return to main menu\n");
            int returnkey;
            scanf("%d", & returnkey);
            system("cls");

        }
        else if (option == 4)
        {
            return 0;
        }
        else
        {
            printf("wrong choice");
        }

    }
    return 0;
}

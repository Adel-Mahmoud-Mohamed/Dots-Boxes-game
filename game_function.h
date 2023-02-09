#ifndef GAME_FUNCTION_H_INCLUDED
#define GAME_FUNCTION_H_INCLUDED

#include"check_complete.h"

#include"printing_grid.h"

#include "validity.h"

#include "move.h"

#include "undo.h"

#include "grid_initializer.h"

#include "add_to_moves.h"


#include "structures.h"






void sorting_array_of_structs(user userarray[MAXSIZE])
{
    int i, j;
    user temp; //for swapping the structures in the array
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        for (j = 0; j < MAXSIZE - 1 - i; j++)
        {
            if (userarray[j].score < userarray[j + 1].score)
            {
                temp = userarray[j];
                userarray[j] = userarray[j + 1];
                userarray[j + 1] = temp;
            }
        }
    }
}

int cheching_emptyness(int rows, int col, char Grid[rows][col])
{
    int flag = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Grid[i][j] == h || Grid[i][j] == v)
            {
                flag = 1;
                break;
            }

        }
    }

    if (flag == 0) return 0;
    else return 1;
}



int turn(int n)
{
    if (n == 1) return 2;
    else return 1;
}





int our_game(int no_of_players, int difficulty, int rows, int col, char Grid[rows][col], int totalMoves, int data_each_moves, int movesArr[totalMoves][data_each_moves], int currentMoves, int * score1, int * score2, int MAX, int len1, int len2, char player1name[len1], char player2name[len2], int moves1, int moves2, int loadedtime, int n)
{
    FILE * bug = fopen("Debugz.txt","w");

    int flag = 1, no_of_undo = 0, which_player = 0, the_one;
    time_t savedtime;
    int t0 = time( & savedtime);
    t0 -= loadedtime;
    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
    fseek(bug,0,SEEK_END);
    if(no_of_players==1)
    {
        fprintf(bug,"There are player against computer\n");
        fprintf(bug,"Player 1 name :%s\n",player1name);
        fprintf(bug,"Player 2 is the computer\n");
    }
    else
    {
        fprintf(bug,"There are player against player\n");
        fprintf(bug,"Player 1 name :%s\n",player1name);
        fprintf(bug,"Player 2 name :%s\n",player2name);
    }

    while (flag)
    {
        which_player = turn(n);
        fseek(bug,0 ,SEEK_END);
        fprintf(bug,"player's %d turn\n",turn(n));
        if (turn(n) == 1)
        {
            int r1, r2, c1, c2;
            printf(ANSI_COLOR_RED "enter the coordinates of the first point:\n");
            scanf("%d%d", & r1, & c1);
            printf(ANSI_COLOR_RED "enter the coordinates of the second point:\n");
            scanf("%d%d", & r2, & c2);
            fseek(bug,0,SEEK_END);
            fprintf(bug,"Player 1 has moved (%d,%d) to (%d,%d)\n",r1,c1,r2,c2);
            printf(ANSI_COLOR_RESET);
            if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
            {
                if (currentMoves == 0)
                    printf("no moves to undo\n");
                else if (cheching_emptyness(rows, col, Grid))
                {
                    fseek(bug,0,SEEK_END);
                    fprintf(bug,"Player 1 has selected Undo button\n");
                    undo(rows, col, Grid, difficulty, totalMoves, data_each_moves, movesArr, no_of_players, & currentMoves, & no_of_undo, score1, score2, & moves1, & moves2, & n);

                    system("cls");

                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                }
                else printf("no moves to undo\n");
            }
            else if (r1 == 2 && c1 == 2 && r2 == 2 && c2 == 2)
            {
                fseek(bug,0,SEEK_END);
                fprintf(bug,"The game has been saved\n");
                //for saving the game
                system("cls");
                int file_number;
                printf("enter the number the file(1 or 2 or 3): ");
                scanf("%d", & file_number);
                if (file_number != 1 && file_number != 2 && file_number != 3)
                {
                    while (true)
                    {
                        printf("\nenter a valid number please: ");
                        scanf("%d", & file_number);
                        if (file_number == 1 || file_number == 2 || file_number == 3) break;
                    }
                }
                time_t currenttime;
                int current = time( & currenttime);
                loadedtime = current - t0;
                char file_name[5];
                sprintf(file_name, "%d.txt", file_number);
                FILE * saving_game;
                saving_game = fopen(file_name, "w");
                fwrite( & loadedtime, sizeof(int), 1, saving_game);
                fwrite( & difficulty, sizeof(int), 1, saving_game);
                fwrite( & no_of_players, sizeof(int), 1, saving_game);
                fwrite( & currentMoves, sizeof(int), 1, saving_game);
                fwrite( & moves1, sizeof(int), 1, saving_game);
                fwrite( & moves2, sizeof(int), 1, saving_game);
                fwrite(score1, sizeof(int), 1, saving_game);
                fwrite(score2, sizeof(int), 1, saving_game);
                fwrite( & n, sizeof(int), 1, saving_game);
                fwrite(movesArr, sizeof(int), totalMoves * 5, saving_game);
                fwrite(Grid, sizeof(char), rows * col, saving_game);
                fwrite( & len1, sizeof(int), 1, saving_game);
                fwrite(player1name, sizeof(char), len1, saving_game);
                if (no_of_players == 2) fwrite( & len2, sizeof(int), 1, saving_game);
                fwrite(player2name, sizeof(char), len2, saving_game);
                fclose(saving_game);
                printf("saved in %d\n", file_number);
                printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                continue;
            }
            else if (r1 == 3 && c1 == 3 && r2 == 3 && c2 == 3)
            {
                fseek(bug,0 ,SEEK_END);
                fprintf(bug,"main menu has been selected\n");
                the_one = 0;
                return the_one;
                //to return to the main menue
            }
            else
            {
                int r = 0; //a flag to know if the move is 1,1,1,1 or other wise ;
                if (r1 == 1 && c1 == 1 && r2 == 1 && c2 == 1)
                {
                    fseek(bug,0,SEEK_END);
                    fprintf(bug,"Plater 1 has selected Redo\n");
                    if (no_of_undo != 0)
                    {
                        r = 1;
                        r1 = movesArr[currentMoves][1];
                        c1 = movesArr[currentMoves][2];
                        r2 = movesArr[currentMoves][3];
                        c2 = movesArr[currentMoves][4];
                        switch (movesArr[currentMoves][0])
                        {
                        case 1:
                            n = 2;
                            break;
                        case 2:
                            n = 1;
                            break;
                        }
                        printf("\n%d\n", no_of_undo);
                    }
                    else
                    {
                        system("cls");
                        printf("no moves to redo\n\n");
                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                        continue;
                    }
                }

                if (validity(r1, c1, r2, c2, rows, col, Grid, difficulty))
                {
                    move(r1, c1, r2, c2, rows, col, Grid, difficulty, which_player);
                    int k = check_complete(r1, c1, r2, c2, difficulty, rows, col, Grid);
                    if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                    {
                        n = 2;
                    }
                    else n = 1;

                    switch (k)
                    {
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        *
                        score1 += 1;
                        break;
                    case 3:
                    case 6:
                        *
                        score1 += 2;
                        break;
                    }
                    currentMoves++;
                    moves1++;
                    if (r == 0)
                    {
                        no_of_undo = 0;
                    }
                    else no_of_undo--;
                    addToMoves(totalMoves, data_each_moves, which_player, r1, c1, r2, c2, movesArr, currentMoves);
                    system("cls");

                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);

                }
                else
                {

                    while (validity(r1, r2, c1, c2, rows, col, Grid, difficulty) == 0)
                    {
                        fseek(bug,0,SEEK_END);
                        fprintf(bug,"Invalid move\n");
                        system("cls");
                        printf("not a valid move\n");
                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                        int r1, r2, c1, c2;
                        printf(ANSI_COLOR_RED "enter the coordinates of the first point:\n"
                               ANSI_COLOR_RESET);
                        scanf("%d%d", & r1, & c1);
                        printf(ANSI_COLOR_RED "enter the coordinates of the second point:\n"
                               ANSI_COLOR_RESET);
                        scanf("%d%d", & r2, & c2);
                        fseek(bug,0,SEEK_END);
                        fprintf(bug,"Player 1 has moved (%d,%d) to (%d,%d)\n",r1,c1,r2,c2);
                        if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
                        {
                            if (currentMoves == 0)
                                printf("no moves to undo\n");
                            else if (cheching_emptyness(rows, col, Grid))
                            {
                                fseek(bug,0,SEEK_END);
                                fprintf(bug,"Player 1 has selected Undo button\n");
                                undo(rows, col, Grid, difficulty, totalMoves, data_each_moves, movesArr, no_of_players, & currentMoves, & no_of_undo, score1, score2, & moves1, & moves2, & n);
                                system("cls");

                                printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                break;
                            }
                            else printf("no moves to undo\n");
                        }
                        else if (r1 == 2 && c1 == 2 && r2 == 2 && c2 == 2)
                        {
                            fseek(bug,0,SEEK_END);
                            fprintf(bug,"Game has been saved\n");
                            //for saving the game
                            system("cls");
                            int file_number;
                            printf("enter the number the file(1 or 2 or 3): ");
                            scanf("%d", & file_number);
                            if (file_number != 1 && file_number != 2 && file_number != 3)
                            {
                                while (true)
                                {
                                    printf("\nenter a valid number please: ");
                                    scanf("%d", & file_number);
                                    if (file_number == 1 || file_number == 2 || file_number == 3) break;
                                }
                            }
                            time_t currenttime;
                            int current = time( & currenttime);
                            loadedtime = current - t0;
                            char file_name[5];
                            sprintf(file_name, "%d.txt", file_number);
                            FILE * saving_game;
                            saving_game = fopen(file_name, "w");
                            fwrite( & loadedtime, sizeof(int), 1, saving_game);
                            fwrite( & difficulty, sizeof(int), 1, saving_game);
                            fwrite( & no_of_players, sizeof(int), 1, saving_game);
                            fwrite( & currentMoves, sizeof(int), 1, saving_game);
                            fwrite( & moves1, sizeof(int), 1, saving_game);
                            fwrite( & moves2, sizeof(int), 1, saving_game);
                            fwrite(score1, sizeof(int), 1, saving_game);
                            fwrite(score2, sizeof(int), 1, saving_game);
                            fwrite( & n, sizeof(int), 1, saving_game);
                            fwrite(movesArr, sizeof(int), totalMoves * data_each_moves, saving_game);
                            fwrite(Grid, sizeof(char), (3 * difficulty + 2) * (5 * difficulty + 2), saving_game);
                            fwrite( & len1, sizeof(int), 1, saving_game);
                            fwrite(player1name, sizeof(char), len1, saving_game);
                            if (no_of_players == 2) fwrite( & len2, sizeof(int), 1, saving_game);
                            fwrite(player2name, sizeof(char), len2, saving_game);
                            fclose(saving_game);
                            printf("saved in %d\n", file_number);
                            printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                            break;
                        }
                        else if (r1 == 3 && c1 == 3 && r2 == 3 && c2 == 3)
                        {
                            fseek(bug,0,SEEK_END);
                            fprintf(bug,"Main menu\n");
                            the_one = 0;
                            return the_one;

                            //to return to the main menue
                        }
                        else
                        {
                            int r = 0;
                            if (r1 == 1 && c1 == 1 && r2 == 1 && c2 == 1)
                            {
                                fseek(bug,0,SEEK_END);
                                fprintf(bug,"Player 1 has selected Redo button\n");
                                if (no_of_undo != 0)
                                {
                                    r = 1;
                                    r1 = movesArr[currentMoves][1];
                                    c1 = movesArr[currentMoves][2];
                                    r2 = movesArr[currentMoves][3];
                                    c2 = movesArr[currentMoves][4];
                                    switch (movesArr[currentMoves][0])
                                    {
                                    case 1:
                                        n = 2;
                                        break;
                                    case 2:
                                        n = 1;
                                        break;
                                    }

                                }
                                else
                                {
                                    system("cls");
                                    printf("no moves to redo\n\n");

                                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);

                                    break;
                                }
                            }
                            if (validity(r1, c1, r2, c2, rows, col, Grid, difficulty))
                            {
                                move(r1, c1, r2, c2, rows, col, Grid, difficulty, which_player);
                                int k = check_complete(r1, c1, r2, c2, difficulty, rows, col, Grid);
                                if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                                {

                                    n = 2;
                                }
                                else n = 1;
                                switch (k)
                                {
                                case 1:
                                case 2:
                                case 4:
                                case 5:
                                    {
                                    *
                                    score1 += 1;
                                    fseek(bug,0,SEEK_END);
                                    fprintf(bug,"Player1 score = %d\n",&score1);
                                    break;}
                                case 3:
                                case 6:
                                    {*
                                    score1 += 2;
                                    fseek(bug,0,SEEK_END);
                                    fprintf(bug,"Player1 score = %d\n",score1);
                                    break;
                                    }
                                }
                                currentMoves++;
                                moves1++;
                                if (r == 0)
                                {
                                    no_of_undo = 0;
                                }
                                else no_of_undo--;
                                addToMoves(totalMoves, data_each_moves, which_player, r1, c1, r2, c2, movesArr, currentMoves);
                                //printing_moves(totalMoves, data_each_moves, movesArr, currentMoves);
                                system("cls");
                                printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (turn(n) == 2)
        {
            if (no_of_players == 2)
            {
                int r1, r2, c1, c2;
                printf(ANSI_COLOR_BLUE "enter the coordinates of the first point:\n");
                scanf("%d%d", & r1, & c1);
                printf(ANSI_COLOR_BLUE "enter the coordinates of the second point:\n");
                scanf("%d%d", & r2, & c2);
                fseek(bug,0,SEEK_END);
                fprintf(bug,"Player 2 has moved (%d,%d) to (%d,%d)\n",r1,c1,r2,c2);
                printf(ANSI_COLOR_RESET);
                if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
                {
                    if (currentMoves == 0)
                        printf("no moves to undo\n");
                    else if (cheching_emptyness(rows, col, Grid))
                    {
                        fseek(bug,0,SEEK_END);
                        fprintf(bug,"Player 2 has selected Undo button\n");
                        undo(rows, col, Grid, difficulty, totalMoves, data_each_moves, movesArr, no_of_players, & currentMoves, & no_of_undo, score1, score2, & moves1, & moves2, & n);
                        system("cls");
                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                    }
                    else printf("no moves to undo\n");
                }
                else if (r1 == 2 && c1 == 2 && r2 == 2 && c2 == 2)
                {
                    fseek(bug,0,SEEK_END);
                    fprintf(bug,"Game saved\n");
                    //for saving the game
                    system("cls");
                    int file_number;
                    printf("enter the number the file(1 or 2 or 3): ");
                    scanf("%d", & file_number);
                    if (file_number != 1 && file_number != 2 && file_number != 3)
                    {
                        while (true)
                        {
                            printf("\nenter a valid number please: ");
                            scanf("%d", & file_number);
                            if (file_number == 1 || file_number == 2 || file_number == 3) break;
                        }
                    }
                    time_t currenttime;
                    int current = time( & currenttime);
                    loadedtime = current - t0;
                    char file_name[5];
                    sprintf(file_name, "%d.txt", file_number);
                    FILE * saving_game;
                    saving_game = fopen(file_name, "w");
                    fwrite( & loadedtime, sizeof(int), 1, saving_game);
                    fwrite( & difficulty, sizeof(int), 1, saving_game);
                    fwrite( & no_of_players, sizeof(int), 1, saving_game);
                    fwrite( & currentMoves, sizeof(int), 1, saving_game);
                    fwrite( & moves1, sizeof(int), 1, saving_game);
                    fwrite( & moves2, sizeof(int), 1, saving_game);
                    fwrite(score1, sizeof(int), 1, saving_game);
                    fwrite(score2, sizeof(int), 1, saving_game);
                    fwrite( & n, sizeof(int), 1, saving_game);
                    fwrite(movesArr, sizeof(int), totalMoves * data_each_moves, saving_game);
                    fwrite(Grid, sizeof(char), rows * col, saving_game);
                    fwrite( & len1, sizeof(int), 1, saving_game);
                    fwrite(player1name, sizeof(char), len1, saving_game);
                    if (no_of_players == 2) fwrite( & len2, sizeof(int), 1, saving_game);
                    fwrite(player2name, sizeof(char), len2, saving_game);
                    fclose(saving_game);
                    printf("saved in %d\n", file_number);
                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                    continue;

                }
                else if (r1 == 3 && c1 == 3 && r2 == 3 && c2 == 3)
                {
                    fseek(bug,0,SEEK_END);
                    fprintf(bug,"Player 2 select main menu\n");
                    the_one = 0;
                    return the_one;

                    //to return to the main menue
                }
                else
                {
                    int r = 0;
                    if (r1 == 1 && c1 == 1 && r2 == 1 && c2 == 1)
                    {
                        fseek(bug,0,SEEK_END);
                        fprintf(bug,"Player 2 has selected Redo button\n");
                        if (no_of_undo != 0)
                        {
                            r = 1;
                            r1 = movesArr[currentMoves][1];
                            c1 = movesArr[currentMoves][2];
                            r2 = movesArr[currentMoves][3];
                            c2 = movesArr[currentMoves][4];
                            switch (movesArr[currentMoves][0])
                            {
                            case 1:
                                n = 2;
                                break;
                            case 2:
                                n = 1;
                                break;
                            }

                        }
                        else
                        {
                            system("cls");
                            printf("no moves to redo\n\n");
                            printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                            continue;
                        }
                    }
                    if (validity(r1, c1, r2, c2, rows, col, Grid, difficulty))
                    {
                        move(r1, c1, r2, c2, rows, col, Grid, difficulty, which_player);
                        int k = check_complete(r1, c1, r2, c2, difficulty, rows, col, Grid);
                        if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                        {
                            n = 1;
                        }
                        else n = 2;

                        switch (k)
                        {
                        case 1:
                        case 2:
                        case 4:
                        case 5:
                            *
                            score2 += 1;
                            break;
                        case 3:
                        case 6:
                            *
                            score2 += 2;
                            break;
                        }
                        currentMoves++;
                        moves2++;
                        if (r == 0) no_of_undo = 0;
                        else no_of_undo--;
                        addToMoves(totalMoves, data_each_moves, which_player, r1, c1, r2, c2, movesArr, currentMoves);
                        system("cls");

                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                    }
                    else
                    {
                        while (validity(r1, r2, c1, c2, rows, col, Grid, difficulty) == 0)
                        {
                            system("cls");
                            fseek(bug,0,SEEK_END);
                            fprintf(bug,"Invalid move for Player 2\n");
                            printf("not a valid move\n");
                            printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                            int r1, r2, c1, c2;
                            printf(ANSI_COLOR_BLUE "enter the coordinates of the first point:\n"
                                   ANSI_COLOR_RESET);
                            scanf("%d%d", & r1, & c1);
                            printf(ANSI_COLOR_BLUE "enter the coordinates of the second point:\n"
                                   ANSI_COLOR_RESET);
                            scanf("%d%d", & r2, & c2);
                            fseek(bug,0,SEEK_END);
                            fprintf(bug,"Player 2 has moved (%d,%d) to (%d,%d)\n",r1,c1,r2,c2);
                            if (r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
                            {
                                if (currentMoves == 0)
                                    printf("no moves to undo\n");
                                else if (cheching_emptyness(rows, col, Grid))
                                {
                                    fprintf(bug,"Player 2 has selected Undo button\n");
                                    undo(rows, col, Grid, difficulty, totalMoves, data_each_moves, movesArr, no_of_players, & currentMoves, & no_of_undo, score1, score2, & moves1, & moves2, & n);
                                    system("cls");
                                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                    break;
                                }
                                else printf("no moves to undo\n");

                            }
                            else if (r1 == 2 && c1 == 2 && r2 == 2 && c2 == 2)
                            {
                                fseek(bug,0,SEEK_END);
                                fprintf(bug,"Game has been saved\n");
                                //for saving the game
                                system("cls");
                                int file_number;
                                printf("enter the number the file(1 or 2 or 3): ");
                                scanf("%d", & file_number);
                                if (file_number != 1 && file_number != 2 && file_number != 3)
                                {
                                    while (true)
                                    {
                                        printf("\nenter a valid number please: ");
                                        scanf("%d", & file_number);
                                        if (file_number == 1 || file_number == 2 || file_number == 3) break;
                                    }
                                }
                                time_t currenttime;
                                int current = time( & currenttime);
                                loadedtime = current - t0;
                                char file_name[5];
                                sprintf(file_name, "%d.txt", file_number);
                                FILE * saving_game;
                                saving_game = fopen(file_name, "w");
                                fwrite( & loadedtime, sizeof(int), 1, saving_game);
                                fwrite( & difficulty, sizeof(int), 1, saving_game);
                                fwrite( & no_of_players, sizeof(int), 1, saving_game);
                                fwrite( & currentMoves, sizeof(int), 1, saving_game);
                                fwrite( & moves1, sizeof(int), 1, saving_game);
                                fwrite( & moves2, sizeof(int), 1, saving_game);
                                fwrite(score1, sizeof(int), 1, saving_game);
                                fwrite(score2, sizeof(int), 1, saving_game);
                                fwrite( & n, sizeof(int), 1, saving_game);
                                fwrite(movesArr, sizeof(int), totalMoves * data_each_moves, saving_game);
                                fwrite(Grid, sizeof(char), rows * col, saving_game);
                                fwrite( & len1, sizeof(int), 1, saving_game);
                                fwrite(player1name, sizeof(char), len1, saving_game);
                                if (no_of_players == 2) fwrite( & len2, sizeof(int), 1, saving_game);
                                fwrite(player2name, sizeof(char), len2, saving_game);
                                fclose(saving_game);
                                printf("saved in %d\n", file_number);
                                printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                break;
                            }
                            else if (r1 == 3 && c1 == 3 && r2 == 3 && c2 == 3)
                            {
                                fseek(bug,0,SEEK_END);
                                fprintf(bug,"Main menu\n");
                                the_one = 0;
                                return the_one;

                                //to return to the main menue
                            }
                            else
                            {
                                int r = 0;
                                if (r1 == 1 && c1 == 1 && r2 == 1 && c2 == 1)
                                {
                                    fprintf(bug,"Player 2 has selected Redo button\n");
                                    if (no_of_undo != 0)
                                    {
                                        r = 1;
                                        r1 = movesArr[currentMoves][1];
                                        c1 = movesArr[currentMoves][2];
                                        r2 = movesArr[currentMoves][3];
                                        c2 = movesArr[currentMoves][4];
                                        switch (movesArr[currentMoves][0])
                                        {
                                        case 1:
                                            n = 2;
                                            break;
                                        case 2:
                                            n = 1;
                                            break;
                                        }

                                    }
                                    else
                                    {
                                        system("cls");
                                        printf("no moves to redo\n\n");
                                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                        break;
                                    }
                                }
                                if (validity(r1, c1, r2, c2, rows, col, Grid, difficulty))
                                {
                                    move(r1, c1, r2, c2, rows, col, Grid, difficulty, which_player);
                                    int k = check_complete(r1, c1, r2, c2, difficulty, rows, col, Grid);
                                    if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                                    {
                                        n = 1;
                                    }
                                    else n = 2;

                                    switch (k)
                                    {
                                    case 1:
                                    case 2:
                                    case 4:
                                    case 5:
                                        *
                                        score2 += 1;
                                        break;
                                    case 3:
                                    case 6:
                                        *
                                        score2 += 2;
                                        break;
                                    }
                                    currentMoves++;
                                    moves2++;
                                    if (r == 0) no_of_undo = 0;
                                    else no_of_undo--;
                                    addToMoves(totalMoves, data_each_moves, which_player, r1, c1, r2, c2, movesArr, currentMoves);
                                    system("cls");
                                    printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                    break;

                                }
                            }
                        }
                    }
                }
            }
            if (no_of_players == 1)
            {
                //initialize the player 2 name by computer
                int move_occurance = 0;
                for (int r1 = 1; r1 <= difficulty + 1; r1++)
                {
                    for (int c1 = 1; c1 <= difficulty + 1; c1++)
                    {
                        for (int r2 = 1; r2 <= difficulty + 1; r2++)
                        {
                            for (int c2 = 1; c2 <= difficulty + 1; c2++)
                            {
                                if (move_occurance == 1) break;
                                else
                                {
                                    if (validity(r1, c1, r2, c2, rows, col, Grid, difficulty))
                                    {
                                        fseek(bug,0,SEEK_END);
                                        fprintf(bug,"Computer has moved (%d,%d) to (%d,%d)\n",r1,c1,r2,c2);
                                        move(r1, c1, r2, c2, rows, col, Grid, difficulty, which_player);
                                        int k = check_complete(r1, c1, r2, c2, difficulty, rows, col, Grid);
                                        if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                                        {
                                            n = 1;
                                        }
                                        else n = 2;
                                        switch (k)
                                        {
                                        case 1:
                                        case 2:
                                        case 4:
                                        case 5:
                                            *
                                            score2 += 1;
                                            break;
                                        case 3:
                                        case 6:
                                            *
                                            score2 += 2;
                                            break;
                                        }
                                        currentMoves++;
                                        moves2++;
                                        move_occurance = 1;
                                        addToMoves(totalMoves, data_each_moves, which_player, r1, c1, r2, c2, movesArr, currentMoves);
                                        system("cls");
                                        printGrid(rows, col, Grid, totalMoves, data_each_moves, movesArr, currentMoves, moves1, moves2, * score1, * score2, MAX, player1name, player2name, t0);
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }

        if (currentMoves == totalMoves)
        {
            fseek(bug,0,SEEK_END);
            fprintf(bug,"End Game\n");
            flag = 0;
            printf("\n");
            printf(ANSI_COLOR_CYAN "GAME ENDED:)\n"
                   ANSI_COLOR_RESET);
            if ( * score1 > * score2)
            {
                fseek(bug,0,SEEK_END);
                fprintf(bug,"Player 1 is the winner with score = %d\n",score1);
                printf(ANSI_COLOR_RED "%s WINS"
                       ANSI_COLOR_RESET, player1name);
                the_one = 1;
            }
            else if ( * score1 < * score2)
            {
                fseek(bug,0,SEEK_END);
                fprintf(bug,"Player 2 is the winner with score= %d\n",score2);
                printf(ANSI_COLOR_BLUE "%s WINS"
                       ANSI_COLOR_RESET, player2name);
                the_one = 2;
            }
            else
            {
                fseek(bug,0,SEEK_END);
                fprintf(bug,"Draw Game\n");
                printf(ANSI_COLOR_CYAN "TIE"
                       ANSI_COLOR_RESET);
                the_one = 0;
            }
            return the_one;
        }
    }
    fclose(bug);
}









#endif // GAME_FUNCTION_H_INCLUDED

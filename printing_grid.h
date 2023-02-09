#ifndef PRINTING_GRID_H_INCLUDED
#define PRINTING_GRID_H_INCLUDED
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
char v = 179,h = 196;
void printGrid(int n, int m, char grid[n][m], int totallines, int y, int moves[totallines][y], int currentmoves, int player1moves, int player2moves, int score1, int score2, int max, char player1name[max], char player2name[max], int t0) {
  system("");
//FILE * bug =fopen("Debugz.txt","w");
//fseek(bug,0,SEEK_END);
  time_t currenttime;
  int current = time( & currenttime);
  int seconds = (current - t0) % 60, minutes = (current - t0) / 60;

  for (int i = 0; i < n; i++) {
    printf("\t\t\t\t\t");
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != h && grid[i][j] != v && grid[i][j] != 'A' && grid[i][j] != 'B') {
        printf("%c", grid[i][j]);
      } else if (grid[i][j] == 'A') {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

      } else if (grid[i][j] == 'B') {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
      } else {
        for (int h = 0; h < currentmoves; h++) {
          if (moves[h][2] == moves[h][4] && moves[h][1] > moves[h][3]) {
            if (j == ((moves[h][2]) * 5) - 4 && i > ((moves[h][3]) * 3) - 2 && i < ((moves[h][1]) * 3) - 2) {
              if (moves[h][0] == 1) printf(ANSI_COLOR_RED);
              else printf(ANSI_COLOR_BLUE);
            }
          } else if (moves[h][2] == moves[h][4] && moves[h][1] < moves[h][3]) {
            if (j == ((moves[h][2]) * 5) - 4 && i < ((moves[h][3]) * 3) - 2 && i > ((moves[h][1]) * 3) - 2) {
              if (moves[h][0] == 1) printf(ANSI_COLOR_RED);
              else printf(ANSI_COLOR_BLUE);
            }
          } else if (moves[h][1] == moves[h][3] && moves[h][2] > moves[h][4]) {
            if (i == ((moves[h][3]) * 3) - 2 && j < ((moves[h][2]) * 5) - 4 && j > ((moves[h][4]) * 5) - 4) {
              if (moves[h][0] == 1) printf(ANSI_COLOR_RED);
              else printf(ANSI_COLOR_BLUE);
            }
          } else {
            if (i == ((moves[h][3]) * 3) - 2 && j > ((moves[h][2]) * 5) - 4 && j < ((moves[h][4]) * 5) - 4) {
              if (moves[h][0] == 1) printf(ANSI_COLOR_RED);
              else printf(ANSI_COLOR_BLUE);
            }
          }

        }
        printf("%c", grid[i][j]);
        printf(ANSI_COLOR_RESET);
      }

    }
    printf("\n");
  }
  printf("\n");

  printf(ANSI_COLOR_RED "Name of player 1: %s\t\t\t\t"
    ANSI_COLOR_RESET, player1name);
  //  fseek(bug,0,SEEK_END);
    //fprintf(bug,"\nPlayer 1 name : %s\n",player1name);
  printf(ANSI_COLOR_BLUE "Name of player 2: %s\n"
    ANSI_COLOR_RESET, player2name);
    //fseek(bug,0,SEEK_END);
    //fprintf(bug,"\nPlayer 2 name : %s\n",player2name);
  printf(ANSI_COLOR_RED "Number of moves for player 1: %d\t\t\t"
    ANSI_COLOR_RESET, player1moves);
    //fseek(bug,0,SEEK_END);
    //fprintf(bug,"Player 1 moves = %d\n",player1moves);
  printf(ANSI_COLOR_BLUE "Number of moves for player 2: %d\n"
    ANSI_COLOR_RESET, player2moves);
    //fseek(bug,0,SEEK_END);
    //fprintf(bug,"Player 2 moves = %d\n",player2moves);
  printf(ANSI_COLOR_RED "score of player 1: %d\t\t\t\t"
    ANSI_COLOR_RESET, score1);
    //fseek(bug,0,SEEK_END);
    //fprintf(bug,"Player 1 score = %d\n",score1);
  printf(ANSI_COLOR_BLUE "score of player 2: %d\n\n"
    ANSI_COLOR_RESET, score2);
    //fseek(bug,0,SEEK_END);
    //fprintf(bug,"Player 2 score = %d\n",score2);
  printf(ANSI_COLOR_MAGENTA "Number of remaining lines: %d"
    ANSI_COLOR_RESET, totallines - currentmoves);
  printf(ANSI_COLOR_MAGENTA "\t\t\ttime passed:  %.2d:%.2d", minutes, seconds);
  printf(ANSI_COLOR_RESET);
  //for time passed

  printf("\n\nfor undo enter 0,0,0,0 for redo enter 1,1,1,1 for save enter 2,2,2,2 for main menue enter 3,3,3,3\n\n");
  //fclose(bug);

}



#endif // PRINTING_GRID_H_INCLUDED

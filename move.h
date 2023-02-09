#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

void move(int r1, int c1, int r2, int c2, int n, int m, char arr[n][m], int difficulty, int which_turn) {
  int realr1, realr2, realc1, realc2;
  realr1 = (3 * r1) - 2;
  realr2 = (3 * r2) - 2;
  realc1 = (5 * c1) - 4;
  realc2 = (5 * c2) - 4;
  if (realc1 == realc2) {
    if (realr1 < realr2) {
      for (int i = realr1 + 1; i < realr2; i++) arr[i][realc1] = v;
    } else {
      for (int i = realr2 + 1; i < realr1; i++) arr[i][realc1] = v;
    }

  }
  if (realr1 == realr2) {
    if (realc2 > realc1) {
      for (int i = realc1 + 1; i < realc2; i++) arr[realr1][i] = h;
    } else
      for (int i = realc2 + 1; i < realc1; i++) arr[realr1][i] = h;

  }

  int k = check_complete(r1, c1, r2, c2, difficulty, n, m, arr);

  if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6) {

    if (which_turn == 1) {
      if (k == 1) {
        if (realc1 < realc2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        }
      } else if (k == 2) {
        if (realc1 < realc2) {
          for (int i = realr1 - 1; i > realr1 - 3; i--) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr1 - 1; i > realr1 - 3; i--) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        }

      } else if (k == 3) {
        if (realc1 < realc2) {
          for (int i = realr1 - 2; i <= realr1 + 2; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr1 - 2; i <= realr1 + 2; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        }
      } else if (k == 4) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'A';
            }
          }
        }
      } else if (k == 5) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 - 1; j > realc1 - 5; j--) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 - 1; j > realc2 - 5; j--) {
              arr[i][j] = 'A';
            }
          }
        }
      } else if (k == 6) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 - 4; j <= realc1 + 4; j++) {
              arr[i][j] = 'A';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 - 4; j <= realc2 + 4; j++) {
              arr[i][j] = 'A';
            }
          }
        }
      }
    } else if (which_turn == 2) {
      if (k == 1) {
        if (realc1 < realc2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        }
      } else if (k == 2) {
        if (realc1 < realc2) {
          for (int i = realr1 - 1; i > realr1 - 3; i--) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr1 - 1; i > realr1 - 3; i--) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        }

      } else if (k == 3) {
        if (realc1 < realc2) {
          for (int i = realr1 - 2; i <= realr1 + 2; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr1 - 2; i <= realr1 + 2; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        }
      } else if (k == 4) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 + 1; j < realc1 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 + 1; j < realc2 + 5; j++) {
              arr[i][j] = 'B';
            }
          }
        }
      } else if (k == 5) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 - 1; j > realc1 - 5; j--) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 - 1; j > realc2 - 5; j--) {
              arr[i][j] = 'B';
            }
          }
        }
      } else if (k == 6) {
        if (realr1 < realr2) {
          for (int i = realr1 + 1; i < realr1 + 3; i++) {
            for (int j = realc1 - 4; j <= realc1 + 4; j++) {
              arr[i][j] = 'B';
            }
          }
        } else {
          for (int i = realr2 + 1; i < realr2 + 3; i++) {
            for (int j = realc2 - 4; j <= realc2 + 4; j++) {
              arr[i][j] = 'B';
            }
          }
        }
      }
    }
  }
}



#endif // MOVE_H_INCLUDED

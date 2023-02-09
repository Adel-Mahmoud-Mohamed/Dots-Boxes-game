#ifndef CHECK_COMPLETE_H_INCLUDED
#define CHECK_COMPLETE_H_INCLUDED

int check_complete(int r1, int c1, int r2, int c2, int difficulty, int rows, int col, char grid[rows][col]) {
char v = 179,h = 196;
  int realr1, realr2, realc1, realc2;
  realr1 = (3 * r1) - 2;
  realr2 = (3 * r2) - 2;
  realc1 = (5 * c1) - 4;
  realc2 = (5 * c2) - 4;

  if (realr1 == realr2) {
    if (realr1 == 1) {
      int adj_r1;
      adj_r1 = realr1 + 3;
      if (grid[realr1 + 1][realc1] == v && grid[realr1 + 1][realc2] == v && grid[adj_r1][(realc1 + realc2) / 2] == h) {
        return 1; //it's a complete box below
      } else {
        return 0;
      }
    } else if (realr1 == 3 * difficulty + 1) {
      int adj_r1;
      adj_r1 = realr1 - 3;
      if (grid[realr1 - 1][realc1] == v && grid[realr2 - 1][realc2] == v && grid[adj_r1][(realc1 + realc2) / 2] == h) {

        return 2; //it's a complete box above
      } else return 0; //not a complete box
    } else {
      int adj_r1, adj_r2;
      adj_r1 = realr1 - 3;
      adj_r2 = realr1 + 3;
      if (grid[realr1 - 1][realc1] == v && grid[realr1 + 1][realc1] == v && grid[realr2 - 1][realc2] == v && grid[realr2 + 1][realc2] == v && grid[adj_r1][(realc1 + realc2) / 2] == h && grid[adj_r2][(realc1 + realc2) / 2] == h) {
        //vertical chain

        return 3;
      } else if (grid[realr1 - 1][realc1] == v && grid[realr2 - 1][realc2] == v && grid[adj_r1][(realc1 + realc2) / 2] == h) {

        return 2; //box above
      } else if (grid[realr1 + 1][realc1] == v && grid[realr2 + 1][realc2] == v && grid[adj_r2][(realc1 + realc2) / 2] == h) {

        return 1; //box below
      } else return 0; //neither a chain nor a box
    }
  } else if (c1 == c2) {
    if (realc1 == 1) {
      int adj_c1;
      adj_c1 = realc1 + 5;
      if (grid[realr1][realc1 + 1] == h && grid[realr2][realc1 + 1] == h && grid[(realr1 + realr2) / 2][adj_c1] == v) {

        return 4; //right box
      } else return 0;
    } else if (realc1 == 5 * difficulty + 1) {
      int adj_c1;
      adj_c1 = realc1 - 5;
      if (grid[realr1][realc1 - 1] == h && grid[realr2][realc1 - 1] == h&& grid[(realr1 + realr2) / 2][adj_c1] == v) {

        return 5; //left box
      } else return 0;
    } else {
      int adj_c1, adj_c2;
      adj_c1 = realc1 - 5;
      adj_c2 = realc2 + 5;
      if (grid[realr1][realc1 + 1] == h && grid[realr1][realc1 - 1] == h && grid[realr2][realc1 + 1] == h && grid[realr2][realc1 - 1] == h && grid[(realr1 + realr2) / 2][adj_c1] == v&& grid[(realr1 + realr2) / 2][adj_c2] == v) {

        return 6; //horizontal chain
      } else if (grid[realr1][realc1 + 1] == h && grid[realr2][realc1 + 1] == h && grid[(realr1 + realr2) / 2][adj_c2] == v) {

        return 4; //right box
      } else if (grid[realr1][realc1 - 1] == h && grid[realr2][realc1 - 1] == h && grid[(realr1 + realr2) / 2][adj_c1] == v) {

        return 5; //left box
      } else return 0; //neither chain nor a box
    }
  }
}



#endif // CHECK_COMPLETE_H_INCLUDED

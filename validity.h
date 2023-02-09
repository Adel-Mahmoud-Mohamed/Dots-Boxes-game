#ifndef VALIDITY_H_INCLUDED
#define VALIDITY_H_INCLUDED

bool validity(int r1, int c1, int r2, int c2, int n, int m, char arr[n][m], int difficulty) {
  int realr1, realr2, realc1, realc2;
  realr1 = (3 * r1) - 2;
  realr2 = (3 * r2) - 2;
  realc1 = (5 * c1) - 4;
  realc2 = (5 * c2) - 4;
  if (abs(r1 - r2) == 1 && abs(c1 - c2) == 0 && arr[(realr1 + realr2) / 2][realc1] != v && arr[(realr1 + realr2) / 2][realc1] != 'A' && arr[(realr1 + realr2) / 2][realc1] != 'B' && (r1 < difficulty + 2) && (c1 < difficulty + 2) && (r2 < difficulty + 2) && (c2 < difficulty + 2))
    return 1;
  else if (abs(c1 - c2) == 1 && abs(r1 - r2) == 0 && arr[realr1][(realc1 + realc2) / 2] != h && arr[realr1][(realc1 + realc2) / 2] != 'A' && arr[realr1][(realc1 + realc2) / 2] != 'B' && (r1 < difficulty + 2) && (c1 < difficulty + 2) && (r2 < difficulty + 2) && (c2 < difficulty + 2))
    return 1;
  else return 0;
}



#endif // VALIDITY_H_INCLUDED

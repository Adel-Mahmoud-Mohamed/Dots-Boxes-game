#ifndef ADD_TO_MOVES_H_INCLUDED
#define ADD_TO_MOVES_H_INCLUDED


void addToMoves(int totalMoves, int y, int x, int r1, int c1, int r2, int c2, int arr[totalMoves][y], int currentmoves)
{

    if (x == 1)
    {
        arr[currentmoves - 1][0] = 1;
        arr[currentmoves - 1][1] = r1;
        arr[currentmoves - 1][2] = c1;
        arr[currentmoves - 1][3] = r2;
        arr[currentmoves - 1][4] = c2;

    }
    if (x == 2)
    {
        arr[currentmoves - 1][0] = 2;
        arr[currentmoves - 1][1] = r1;
        arr[currentmoves - 1][2] = c1;
        arr[currentmoves - 1][3] = r2;
        arr[currentmoves - 1][4] = c2;

    }
}



#endif // ADD_TO_MOVES_H_INCLUDED

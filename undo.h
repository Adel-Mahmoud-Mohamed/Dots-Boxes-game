#ifndef UNDO_H_INCLUDED
#define UNDO_H_INCLUDED

void undo(int rows, int m, char arr[rows][m], int difficulty, int totalmoves, int data, int moves[totalmoves][data], int noofplayers, int * currentMoves, int * no_of_undo, int * score1, int * score2, int * moves1, int * moves2, int * n)
{

    int noofmoves = * currentMoves;
    if (noofplayers == 2)
    {

        int realr1, realc1, realr2, realc2;
        realr1 = (moves[noofmoves - 1][1] * 3) - 2;
        realr2 = (moves[noofmoves - 1][3] * 3) - 2;
        realc1 = (moves[noofmoves - 1][2] * 5) - 4;
        realc2 = (moves[noofmoves - 1][4] * 5) - 4;

        int k = check_complete(moves[noofmoves - 1][1], moves[noofmoves - 1][2], moves[noofmoves - 1][3], moves[noofmoves - 1][4], difficulty, rows, m, arr);

        if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
        {

            switch (k)
            {
            case 1:
            case 2:
            case 4:
            case 5:
                if (moves[noofmoves - 1][0] == 1)
                {
                    * score1 -= 1;
                    break;
                }
                else
                {
                    * score2 -= 1;
                    break;
                }

            case 3:
            case 6:
                if (moves[noofmoves - 1][0] == 1)
                {
                    * score1 -= 2;
                    break;
                }
                else
                {
                    * score2 -= 2;
                    break;
                }
            }

            if (k == 1)
            {
                if (realc1 < realc2)
                {
                    for (int i = realr1 + 1; i < realr1 + 3; i++)
                    {
                        for (int j = realc1 + 1; j < realc1 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr1 + 1; i < realr1 + 3; i++)
                    {
                        for (int j = realc2 + 1; j < realc2 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
            }
            else if (k == 2)
            {
                if (realc1 < realc2)
                {
                    for (int i = realr1 - 1; i > realr1 - 3; i--)
                    {
                        for (int j = realc1 + 1; j < realc1 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr1 - 1; i > realr1 - 3; i--)
                    {
                        for (int j = realc2 + 1; j < realc2 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }

            }
            else if (k == 3)
            {
                if (realc1 < realc2)
                {
                    for (int i = realr1 - 2; i <= realr1 + 2; i++)
                    {
                        for (int j = realc1 + 1; j < realc1 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr1 - 2; i <= realr1 + 2; i++)
                    {
                        for (int j = realc2 + 1; j < realc2 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
            }
            else if (k == 4)
            {
                if (realr1 < realr2)
                {
                    for (int i = realr1 + 1; i < realr1 + 3; i++)
                    {
                        for (int j = realc1 + 1; j < realc1 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr2 + 1; i < realr2 + 3; i++)
                    {
                        for (int j = realc2 + 1; j < realc2 + 5; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
            }
            else if (k == 5)
            {
                if (realr1 < realr2)
                {
                    for (int i = realr1 + 1; i < realr1 + 3; i++)
                    {
                        for (int j = realc1 - 1; j > realc1 - 5; j--)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr2 + 1; i < realr2 + 3; i++)
                    {
                        for (int j = realc2 - 1; j > realc2 - 5; j--)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
            }
            else if (k == 6)
            {
                if (realr1 < realr2)
                {
                    for (int i = realr1 + 1; i < realr1 + 3; i++)
                    {
                        for (int j = realc1 - 4; j <= realc1 + 4; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
                else
                {
                    for (int i = realr2 + 1; i < realr2 + 3; i++)
                    {
                        for (int j = realc2 - 4; j <= realc2 + 4; j++)
                        {
                            arr[i][j] = ' ';
                        }
                    }
                }
            }
        }

        if (realc1 == realc2)
        {
            if (realr1 < realr2)
            {
                for (int i = realr1 + 1; i < realr2; i++) arr[i][realc1] = ' ';
            }
            else
            {
                for (int i = realr2 + 1; i < realr1; i++) arr[i][realc1] = ' ';
            }
        }

        if (realr1 == realr2)
        {
            if (realc2 > realc1)
            {
                for (int i = realc1 + 1; i < realc2; i++) arr[realr1][i] = ' ';
            }
            else
                for (int i = realc2 + 1; i < realc1; i++) arr[realr1][i] = ' ';
        }

        if (moves[noofmoves - 1][0] == 1)
        {
            * moves1 -= 1;
        }
        else *moves2 -= 1;

        if (k == 0)
        {
            if ( * n == 1)
            {
                * n = 2;
            }
            else *n = 1;
        }

        * no_of_undo += 1;
        noofmoves -= 1;

    }
    else if (noofplayers == 1)
    {

        while (1)
        {
            int realr1, realc1, realr2, realc2;
            realr1 = (moves[noofmoves - 1][1] * 3) - 2;
            realr2 = (moves[noofmoves - 1][3] * 3) - 2;
            realc1 = (moves[noofmoves - 1][2] * 5) - 4;
            realc2 = (moves[noofmoves - 1][4] * 5) - 4;
            if (moves[noofmoves - 1][0] == 1)
            {
                int k = check_complete(moves[noofmoves - 1][1], moves[noofmoves - 1][2], moves[noofmoves - 1][3], moves[noofmoves - 1][4], difficulty, rows, m, arr);
                if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                {
                    switch (k)
                    {
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        *
                        score1 -= 1;
                        break;
                    case 3:
                    case 6:
                        *
                        score1 -= 2;
                        break;
                    }

                    if (k == 1)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 2)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 - 1; i > realr1 - 3; i--)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 - 1; i > realr1 - 3; i--)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }

                    }
                    else if (k == 3)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 - 2; i <= realr1 + 2; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 - 2; i <= realr1 + 2; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 4)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 5)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 - 1; j > realc1 - 5; j--)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 - 1; j > realc2 - 5; j--)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 6)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 - 4; j <= realc1 + 4; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 - 4; j <= realc2 + 4; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                }
                if (realc1 == realc2)
                {
                    if (realr1 < realr2)
                    {
                        for (int i = realr1 + 1; i < realr2; i++) arr[i][realc1] = ' ';
                    }
                    else
                    {
                        for (int i = realr2 + 1; i < realr1; i++) arr[i][realc1] = ' ';
                    }
                }
                if (realr1 == realr2)
                {
                    if (realc2 > realc1)
                    {
                        for (int i = realc1 + 1; i < realc2; i++) arr[realr1][i] = ' ';
                    }
                    else
                        for (int i = realc2 + 1; i < realc1; i++) arr[realr1][i] = ' ';
                }

                * moves1 -= 1;
                * no_of_undo += 1;
                noofmoves -= 1;
                * n = 2;
                break;
            }
            else if (moves[noofmoves - 1][0] == 2)
            {
                int k = check_complete(moves[noofmoves - 1][1], moves[noofmoves - 1][2], moves[noofmoves - 1][3], moves[noofmoves - 1][4], difficulty, rows, m, arr);
                if (k == 1 || k == 2 || k == 3 || k == 4 || k == 5 || k == 6)
                {
                    switch (k)
                    {
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                        *
                        score2 -= 1;
                        break;
                    case 3:
                    case 6:

                        *
                        score2 -= 2;
                        break;
                    }
                    if (k == 1)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 2)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 - 1; i > realr1 - 3; i--)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 - 1; i > realr1 - 3; i--)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }

                    }
                    else if (k == 3)
                    {
                        if (realc1 < realc2)
                        {
                            for (int i = realr1 - 2; i <= realr1 + 2; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr1 - 2; i <= realr1 + 2; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 4)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 + 1; j < realc1 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 + 1; j < realc2 + 5; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 5)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 - 1; j > realc1 - 5; j--)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 - 1; j > realc2 - 5; j--)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                    else if (k == 6)
                    {
                        if (realr1 < realr2)
                        {
                            for (int i = realr1 + 1; i < realr1 + 3; i++)
                            {
                                for (int j = realc1 - 4; j <= realc1 + 4; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                        else
                        {
                            for (int i = realr2 + 1; i < realr2 + 3; i++)
                            {
                                for (int j = realc2 - 4; j <= realc2 + 4; j++)
                                {
                                    arr[i][j] = ' ';
                                }
                            }
                        }
                    }
                }
                if (realc1 == realc2)
                {
                    if (realr1 < realr2)
                    {
                        for (int i = realr1 + 1; i < realr2; i++) arr[i][realc1] = ' ';
                    }
                    else
                    {
                        for (int i = realr2 + 1; i < realr1; i++) arr[i][realc1] = ' ';
                    }
                }
                if (realr1 == realr2)
                {
                    if (realc2 > realc1)
                    {
                        for (int i = realc1 + 1; i < realc2; i++) arr[realr1][i] = ' ';
                    }
                    else
                        for (int i = realc2 + 1; i < realc1; i++) arr[realr1][i] = ' ';
                }

                * moves2 -= 1;
                noofmoves -= 1;

            }
        }

    }

    * currentMoves = noofmoves;
}



#endif // UNDO_H_INCLUDED

#include "shayanf.h"
/* Defines different Tetris shapes based on the given number */
void shapes(int num, char arr[20][20])
{
    /* Shapes are represented using '1' in the array */
    if (num == 0)
    {
        arr[0][9] = '1';
        arr[0][10] = '1';
        arr[1][9] = '1';
        arr[1][10] = '1';
    }
    if (num == 1)
    {
        arr[0][8] = '1';
        arr[0][9] = '1';
        arr[1][9] = '1';
        arr[1][10] = '1';
    }
    if (num == 2)
    {
        arr[0][9] = '1';
        arr[1][8] = '1';
        arr[1][9] = '1';
        arr[1][10] = '1';
    }
    if (num == 3)
    {
        arr[0][8] = '1';
        arr[0][9] = '1';
        arr[0][10] = '1';
        arr[0][11] = '1';
    }
    /*

    0 = [][]
        [][]

    1 = [][]
          [][]

    2 =   []
        [][][]

    3 = [][][][]

    */
}
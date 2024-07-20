#define _USE_MATH_DEFINES
#include "shayanf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#define sleepInSeconds(seconds) Sleep((DWORD)(seconds * 1000))
#endif
void delete_2_line(char arr[20][20], int *score)
{
    /* Deletes completed lines (full of '2') and updates the score */
    for (int i = 0; i < 20; i++)
    {
        if (
            (arr[i][0] == '2') && (arr[i][1] == '2') && (arr[i][2] == '2') &&
            (arr[i][3] == '2') && (arr[i][4] == '2') && (arr[i][5] == '2') &&
            (arr[i][6] == '2') && (arr[i][7] == '2') && (arr[i][8] == '2') &&
            (arr[i][9] == '2') && (arr[i][10] == '2') && (arr[i][11] == '2') && (arr[i][12] == '2') && (arr[i][13] == '2') && (arr[i][14] == '2') && (arr[i][15] == '2') && (arr[i][16] == '2') && (arr[i][17] == '2') && (arr[i][18] == '2') && (arr[i][19] == '2'))

        {
            for (int j = 0; j < 20; j++)
            {
                arr[i][j] = '0';
            }
            for (int j = 0; j < 20; j++)
            {
                arr[0][j] = '0';
            }
            for (int j = i; j > 0; j--)
            {
                for (int k = 0; k < 20; k++)
                {
                    arr[j][k] = arr[j - 1][k];
                }
            }
            (*score) += 10;
        }
    }
}
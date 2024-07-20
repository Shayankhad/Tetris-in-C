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
/* Checks if a shape has reached the top of the game board */
int game_over(char arr[20][20])
{
    /* Checks if a shape has reached the top of the game board */
    /* Returns 1 if game over, 0 otherwise */
    int isfull = 0;
    for (int i = 0; i < 20; i++)
    {
        if (arr[1][i] == ('2'))
        {
            isfull = 1;
        }
    }
    return isfull;
}
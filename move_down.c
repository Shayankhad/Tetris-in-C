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
/* Moves the shapes down in the array */
void move_down(char arr[20][20])
{
    /* Moves the shapes down in the array */
    for (int i = 19; i >= 0; i--)
    {
        for (int j = 19; j >= 0; j--)
        {
            if (arr[i][j] == '1')
            {
                arr[i][j] = '0';
                arr[i + 1][j] = '1';
            }
        }
    }
}
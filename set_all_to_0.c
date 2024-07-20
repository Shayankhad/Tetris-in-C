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
/* Sets every char in the array to '0' char */
void set_all_to_0(char arr[20][20])
{
    /* Sets every char in the array to '0' char */
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            arr[i][j] = '0';
        }
    }
}
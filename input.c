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
/* Takes user input and checks if it's valid (either '1' or '2') */
char input(char input)
{
    /* Takes user input and checks if it's valid (either '1' or '2') */
    /* Loops until a valid input is received */
    char input_2;
    while (input = getchar())
    {
        input_2 = input;
        if ((input == '1') || (input == '2'))
        {
            break;
        }
        else
        {
            printf("Please enter a  valid number:\n");
        }
        fflush(stdin);
    }
    return input_2;
}
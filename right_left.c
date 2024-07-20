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

/* Moves the shapes to the right or left based on user input */
void right_left(char arr[20][20], char x)
{
    /* Moves the shapes to the right or left based on user input 
    Checks for collisions with the walls and other shapes */    
    int help_var = 1;
    if ((x == 'a') || (x == 'A'))
    {
        for (int i = 19; i >= 0; i--)
        {
            for (int j = 0; j < 20; j++)
            {
                if ((arr[i][j] == '1')&&(arr[i][j-1] == '2'))
                {
                    help_var = 0;
                }
            }
        }
        for (int i = 19; i >= 0; i--)
        {
            for (int j = 0; j < 20; j++)
            {
                if (arr[i][0] == '1')
                {
                    help_var = 0;
                }
            }
        }
        for (int i = 19; i >= 0; i--)
        {
            for (int j = 0; j < 20; j++)
            {
                if ((arr[i][j] == '1') && (help_var))
                {
                    arr[i][j] = '0';
                    arr[i][j - 1] = '1';
                }
            }
        }
    }
    help_var = 1;
    if ((x == 'd') || (x == 'D'))
    {
        for (int i = 0 ; i<20 ; i++){
            for (int j = 0 ; j<20 ; j++){
                if ((arr[i][j] == '1')&&(arr[i][j + 1] == '2')){
                    help_var = 0; 
                }
            }
        }
        for (int i = 19; i >= 0; i--)
        {
            if (arr[i][19] == '1')
            {
                help_var = 0;
            }
        }
        for (int i = 19; i >= 0; i--)
        {
            for (int j = 19; j >= 0; j--)
            {
                if ((arr[i][j] == '1') && (help_var))
                {
                    arr[i][j] = '0';
                    arr[i][j + 1] = '1';
                }
            }
        }
    }
}
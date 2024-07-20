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

/* Rotates the current Tetris shape based on user input */
void rotate(char arr[20][20], int key, int help_rotate, char choose_rotation)
{
    /* Rotates the current Tetris shape based on user input */
    /* Different rotations for different shapes */    
    if (choose_rotation == '1')
    {
        /*rotate shape 3*/
        if ((key == ' '))
        {
            if (!(help_rotate % 2))
            { /* if help random is even this condition is true*/
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if((i<17)&&(i>0)){
                            if ((arr[i][j] == '1') && (arr[i][j + 1] == '1') && (arr[i][j + 2] == '1') && (arr[i][j + 3] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i - 1][j + 1] = '1';
                                arr[i][j + 1] = '1';
                                arr[i + 1][j + 1] = '1';
                                arr[i + 2][j + 1] = '1';
                            }
                        }
                    }
                }
            }
            else if (help_rotate % 2)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if ((j<18)&&(j>0)){
                            if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i + 2][j] == '1') && (arr[i + 3][j] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i + 1][j - 1] = '1';
                                arr[i + 1][j] = '1';
                                arr[i + 1][j + 1] = '1';
                                arr[i + 1][j + 2] = '1';
                            }
                        }
                    }
                }
            }
        }
        /*rotate shape 1*/
        if ((key == ' '))
        {
            if (!(help_rotate % 2))
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (i<17){
                            if ((arr[i][j] == '1') && (arr[i][j + 1] == '1') && (arr[i + 1][j + 1] == '1') && (arr[i + 1][j + 2] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i][j + 1] = '1';
                                arr[i + 1][j + 1] = '1';
                                arr[i + 1][j] = '1';
                                arr[i + 2][j] = '1';
                            }
                        }
                    }
                }
            }
            else if (help_rotate % 2)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if(j<19){
                            if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i + 1][j - 1] == '1') && (arr[i + 2][j - 1] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i][j - 1] = '1';
                                arr[i][j] = '1';
                                arr[i + 1][j] = '1';
                                arr[i + 1][j + 1] = '1';
                            }
                        }
                    }
                }
            }
        }
        /*rotate shape 2*/
        if ((key == ' '))
        {
            if ((help_rotate % 4) == 0)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if(i<17){
                            if ((arr[i][j] == '1') && (arr[i + 1][j - 1] == '1') && (arr[i + 1][j] == '1') && (arr[i + 1][j + 1] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i][j] = '1';
                                arr[i + 1][j] = '1';
                                arr[i + 1][j + 1] = '1';
                                arr[i + 2][j] = '1';
                            }
                        }
                    }
                }
            }
            else if ((help_rotate % 4) == 1)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if(j>0){
                            if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i + 1][j + 1] == '1') && (arr[i + 2][j] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i][j] = '1';
                                arr[i + 1][j] = '1';
                                arr[i][j + 1] = '1';
                                arr[i][j - 1] = '1';
                            }
                        }
                    }
                }
            }
            else if ((help_rotate % 4) == 2)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if(i<17){
                            if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i][j + 1] == '1') && (arr[i][j - 1] == '1'))
                            {
                                set_1_to_0(arr);
                                arr[i][j] = '1';
                                arr[i + 1][j] = '1';
                                arr[i + 1][j - 1] = '1';
                                arr[i + 2][j] = '1';
                            }
                        }
                    }
                }
            }
            else if ((help_rotate % 4) == 3)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if(j<19)
                        if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i + 1][j - 1] == '1') && (arr[i + 2][j] == '1'))
                        {
                            set_1_to_0(arr);
                            arr[i][j] = '1';
                            arr[i + 1][j - 1] = '1';
                            arr[i + 1][j] = '1';
                            arr[i + 1][j + 1] = '1';
                        }
                    }
                }
            }
        }
    }
    if (choose_rotation == '2')
    {
        /*rotate shape 2*/
        if ((key == ' '))
        {
            if (!(help_rotate % 2))
            { /* if help random is even this condition is true*/
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if ((arr[i][j] == '1') && (arr[i + 1][j] == '1') && (arr[i + 1][j + 1] == '1') && (arr[i + 1][j - 1] == '1')){
                            set_1_to_0(arr);
                            arr[i][j] = '1';
                            arr[i][j + 1] = '1';
                            arr[i][j - 1] = '1';
                            arr[i + 1][j] = '1';
                        }
                    }
                }
            }
            else if (help_rotate % 2)
            {
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if ((arr[i][j] == '1') && (arr[i][j + 1] == '1') && (arr[i][j - 1] == '1') && (arr[i + 1][j] == '1'))
                        {
                            set_1_to_0(arr);
                            arr[i + 1][j] = '1';
                            arr[i + 1][j + 1] = '1';
                            arr[i + 1][j - 1] = '1';
                            arr[i][j] = '1';
                        }
                    }
                }
            }
        }
    }
}
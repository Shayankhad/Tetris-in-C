/*                                                  TETRIS                                                       */
/*---------------------------------------------------------------------------------------------------------------*/
/*Shayan khademi 810102566*/
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

/* 
THIS IS MAIN CODE, BEFORE RUNING THE CODE WRITE THIS CODE IN TERMINAL !!!!!!!!!!!!!!!!!!!!!!!!

gcc 1.c clrscr.c random.c show_arr.c shapes.c set_1_to_0.c set_1_to_2.c set_all_to_0.c move_down.c right_left.c delete_2_line.c game_over.c rotate.c input.c -o e.exe

AND THEN WRITE ./e.exe  IN TERMINAL TO RUN THE CODE!!!!!!!!!!!!!!!!!
*/


int main(void)
{
    int help_var_3 = 1;
    while(help_var_3){
        /* this loop runs the whole game*/
        int score = 0;
        int *p_score = &score;
        char y_x[20][20];
        set_all_to_0(y_x);
        int help_var_2 = 1;
        char choose_rotation;
        /*introduction*/
        printf("Hi! I'm Shayan, Welcome to Tetris's world\n");
        printf("How much rotation per space?\n1) 90 \n2) 180\n");
        choose_rotation = input(choose_rotation);
        int help_random_1 = random();
        int help_random_2 = random();
        int random_arr[2] = {help_random_1 , help_random_2};
        while (help_var_2)
        {
            set_1_to_2(y_x);
            int help_rotate = 0;
            shapes(help_random_1, y_x);
            float help_sleep = 0.2;
            for (int help_var = 1; help_var; help_var += 0)
            {
                char key = '\0';
                int help_key = 0;
                if (kbhit())
                /* this condition check if any key has pressed*/
                {
                    char key = _getch();
                    right_left(y_x, key);
                    if ((key == 'a') || (key == 'd') || (key == 'A') || (key == 'D'))
                    {/*right and left*/
                        help_key = 1;
                    }

                    if (key == ' ')
                    {/*rotation*/
                        rotate(y_x, key, help_rotate, choose_rotation);
                        help_rotate += 1;
                    }
                    if ((key == 's') || (key == 'S'))
                    {/*speed change*/
                        if (help_sleep >= 0.01)
                        {
                            help_sleep /= 2;
                        }
                    }
                }
                clrscr();
                if (!help_key)
                {
                    move_down(y_x);
                }
                show_arr(y_x, score , help_random_2);
                sleepInSeconds(help_sleep);
                for (int j = 0; j < 20; j++)
                {/*this loop checks if the shape reach the botom*/
                    if (y_x[19][j] == '1')
                    {
                        help_var = 0;
                        set_1_to_2(y_x);
                        break;
                    }
                }
                for (int i = 0; i < 20; i++)
                { /*this loop checks if a shape landed on another shape*/
                    for (int j = 0; j < 20; j++)
                    {
                        if ((y_x[i][j] == '1') && (y_x[i + 1][j] == '2'))
                        {
                            set_1_to_2(y_x);
                            help_var = 0;
                        }
                    }
                }
                delete_2_line(y_x, p_score);
                if (game_over(y_x))
                {
                    help_var = 0;
                    help_var_2 = 0;
                    /*this two initialization break 2 loops at the same*/
                }
            }
            help_random_1 = help_random_2;
            help_random_2 = random();
        }
        /*intro*/
        printf("NICE TRY! Your score: %d\n", score);
        printf("Do you want to play again?\n1)Yes\n2)No\n");
        char again;
        again = input(again);/*for ending the whole game*/
        if (again == '1'){
            help_var_3 = 1;
        }
        else if(again == '2'){
            help_var_3 = 0 ; 
        }
    }
}

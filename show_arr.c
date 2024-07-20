#include "shayanf.h"
#include <stdio.h>
void show_arr(char arr[20][20], int score , int help_random_2)
{
    /* Displays the Tetris playground with the current state of the array */

    for (int i = 0; i < 42; i++)
    {
        printf("-");
    }
    printf("      Score: %d\n", score);
    for (int i = 0; i < 20; i++)
    {
        printf("|");
        for (int j = 0; j < 20; j++)
        {
            if (arr[i][j] == '0')
            {
                printf("%s", "  ");
            }
            else if (arr[i][j] == '1')
            {
                printf("%s", "[]");
            }
            else if (arr[i][j] == '2')
            {
                printf("%s", "[]");
            }
        }
        printf("|");
        printf("\n");
    }
    for (int i = 0; i < 42; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("Next shape:\n");
    if (help_random_2 == 0){
        printf("[][]\n[][]\n");
    }
    else if(help_random_2 == 1){
        printf("[][]\n  [][]\n");
    }
    else if(help_random_2 == 2){
        printf("  []\n[][][]\n");
    }
    else if(help_random_2 == 3){
        printf("[][][][]\n");
    }
}
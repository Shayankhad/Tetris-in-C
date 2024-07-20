/*                                                  TETRIS                                                       */
/*---------------------------------------------------------------------------------------------------------------*/
/*Shayan khademi 810102566*/
#define _USE_MATH_DEFINES
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

/* Generates a random number from 0 to 3 */
int random()
{
    srand(clock() + time(NULL) + M_PI);
    return rand() % 4;
}

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
/* Displays the Tetris playground with the current state of the array */

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
/* Sets every '1' char in the array to '0' char */

void set_1_to_0(char arr[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (arr[i][j] == '1')
            {
                arr[i][j] = '0';
            }
        }
    }
}
/* Sets every '1' char in the array to '2' char */

void set_1_to_2(char arr[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (arr[i][j] == '1')
            {
                arr[i][j] = '2';
            }
        }
    }
}
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
/* Deletes completed lines (full of '2') and updates the score */

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
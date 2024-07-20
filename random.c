#define _USE_MATH_DEFINES
#include <math.h>
#include <stddef.h>  
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

/* Generates a random number from 0 to 3 */
int random()
{
    srand(clock() + time(NULL) + M_PI);
    return rand() % 4;
}

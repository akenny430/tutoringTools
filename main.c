#include "millerRabin.h"
#include "messages.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int testNum; 
    int yesNo;

    printf("Enter 0 to terminate program\nEnter some numbers:\n");
    while (scanf("%d", &testNum) > 0)
    {
        // if you enter 0 or a negative number, it ends the program
        if (testNum < 1)
        {
            break;
        }

        // testing and printing whether the numbers are prime or not
        yesNo = isPrime(testNum);
        printMessage(testNum, yesNo);
    }

    return 0;
}

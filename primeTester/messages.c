#include "messages.h"
#include <stdio.h>

// auxiliary function to print out a number being prime
void printPrime(int input)
{
    printf("%10d is \033[32mprime\033[0m\n", input);
}

// auxiliary function to print out that the number is not prime
void printComposite(int input)
{
    printf("%10d is \033[38;5;208mnot prime\033[0m\n", input);
}

// function to print out whether number is prime or not
void printMessage(int input, int isPrime)
{
    if (isPrime)
    {
        printPrime(input);
    }
    else 
    {
        printComposite(input);
    }
}

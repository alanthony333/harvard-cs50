/*
 * generate.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 3 Problem Set
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated (meaning random numbers are < LIMIT)
#define LIMIT 65536

int main(int argc, string argv[])
{
    // prompts user for proper usage which requires 2-3 arguments including ./generate
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // converting the number of random numbers to be printed (from user input) to integer
    int n = atoi(argv[1]);

    // if [s] is supplied (optional seed), it is used by function srand48
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // generate random numbers according to the limit and number of random numbers specified by user
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

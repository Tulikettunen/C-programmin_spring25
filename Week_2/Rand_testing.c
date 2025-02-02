//
// Created by tuuli on 01/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", 6, random_variable);

    // roll a 6-sided die 20 times
    for (int n=0; n != 20; ++n) {
        int x = 7;
        while(x > 6)
            x = 1 + rand()/((7 + 1u)/6); // Note: 1+rand()%6 is biased
        printf("%d ",  x);
    }
}
//
// Created by tuuli on 05/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define MIN 0
#define MAX 100

void print_numbers(const int *array, int count);
int create_random(int min, int max);


void print_numbers(const int *array, int count){
    for (int i = 0; i< count; i++){
        printf("%*d\n", 8, array[i]);
    }
}


int create_random(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(){
    srand(time(NULL));

    int randomlist[SIZE];        //Luo lista random numeroilla
    for (int i = 0; i < SIZE; i++){
        randomlist[i] = create_random(MIN, MAX);
    }

    print_numbers(randomlist, SIZE);

    return 0;
}
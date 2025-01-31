//
// Created by tuuli on 30/01/2025.
//

#include <stdio.h>

int read_range(int low, int high);

int read_range(int low, int high){
    int user_roll;
    printf("Roll a D%d dice, and enter the number you got:\n", high);
    while ((scanf("%d", &user_roll) != 1) || (user_roll < low) || (user_roll > high)){
        while(getchar() != '\n');
        printf("That was not a number between %d-%d. Don'tcha try to cheat on me!\n", low, high);
        printf("Try again:\n");
    }
    while(getchar() != '\n');
    return user_roll;
}

int main(){
    printf("Let's play!\n");
    int tie = 1;
    int lowest = 1;
    int highest = 6;
    int user_roll;

    while (tie == 1) {
        printf("Enter a number between %d and %d.\n", lowest, highest);
        user_roll = read_range(lowest, highest);
        if (user_roll == highest) {
            printf("I got 6. It is a tie!\n");
            tie = 0;
        }
        else {
            printf("I got %d. I win!\n", user_roll + 1);
        }
    }
}
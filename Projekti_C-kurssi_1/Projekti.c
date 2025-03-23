//
// Created by tuuli on 19/03/2025.
//

//Declarations:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAIN_OPTS 4
#define PRINT_PAS_OPTS 2

//Function declarations:
void read_csv();
void reserve_seat();
void print_seatmap();
void print_passengers();
void sort_first();
void sort_last();

int input_handling(int *input, int range);

//Functions:
int input_handling(int *input, int range){
    int holder;
    while( (scanf("%d", &holder) != 1) || (holder < 1) || (holder > range) ){
        while(getchar() != '\n');
        printf("Invalid user input, please read the instructions and try again \n");
    }
    while(getchar() != '\n');
    *input = holder;
    return holder;
}



//Main program:
int main(){
    bool ton = true;
    while (ton){
        int select;
        int * selected = &select;
        printf("Ohjeet valitsemiseen \n");

        switch (input_handling(selected, MAIN_OPTS)) {
        case 1:
            printf("reserve seat case 1 valittu\n");
            //reserve_seat();
            break;
        case 2:
            printf("print seatmap case 2 valittu\n");
            //print_seatmap();
            break;
        case 3:
            printf("print passangers case 3 valittu\n");
            //print_passangers();
            break;
        case 4:
            printf("You have chosen to exit the program.\n"
                "Thank you for visiting us and welcome to start great trips with Airline Seatmanager again!\n");
            ton = false;
            break;
        default:
             printf("Something unexpected went wrong, please try again.");
        }
    }
    return 0;
}
//
// Created by tuuli on 31/01/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_d6();
int roll_d20();
int print_menu();

int print_menu(){
    printf("Tervetuloa nopanheitto ohjelmaan!\n");
    printf("Valitse seuraavista:\n1. Heitä D6 noppaa.\n2. Heitä D20 noppaa.\n3. Lopeta.\n");
    return 0;
}

int roll_d6(){
    printf("Heität D6 noppaa!\n");
    /*srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", 7, random_variable);
     */

    return 0;
}

int roll_d20(){
    printf("Heität d20 noppaa!\n");
    return 0;
}

int main(void){
    int ton = 1;
    int choice;
    while(ton == 1){
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Syötäthän vain numeroita! Valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
            while(getchar() != '\n');
        }
        else{
            switch(choice) {
                case 1:
                    roll_d6();
                    while(getchar() != '\n');
                    break;
                case 2:
                    roll_d20();
                    while(getchar() != '\n');
                    break;
                case 3:
                    ton = 0;
                    while(getchar() != '\n');
                    break;
                default:
                    printf("Syöttämänne valinta ei ole kelvollinen, valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
                    while (getchar() != 'n');
                    break;
            }
        }
    }
    return 0;
}

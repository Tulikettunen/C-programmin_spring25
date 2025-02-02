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
    printf("Valitse seuraavista:\n1. Heitä D6 noppaa.\n2. Heitä D20 noppaa.\n3. Lopeta.\n");
    return 0;
}

int roll_d6(){
    printf("Heität D6 noppaa!\n");
    srand(time(NULL));

    int x = 7;
    while(x > 6) {
        x = 1 + rand()/((7 + 1u)/6);
    }
    printf("Silmäluku: %d \n",  x);
    return 0;
}

int roll_d20(){
    srand(time(NULL));

    printf("Heität d20 noppaa!\n");
    int x = 21;
    while(x > 20) {
        x = 1 + rand()/((21 + 1u)/20);
    }
    printf("Silmäluku:%d \n",  x);
    return 0;
}

int main(void){
    int ton = 1;
    int choice;
    printf("Tervetuloa nopanheitto ohjelmaan!\n");
    while(ton == 1){
        print_menu();
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            printf("Syötäthän vain numeroita! Valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
        }else if (choice == 1) {
            roll_d6();
            while(getchar() != '\n');
        }else if (choice == 2){
            while(getchar() != '\n');
            roll_d20();
        }else if (choice == 3) {
            while(getchar() != '\n');
            ton = 0;
        }else {
            while(getchar() != '\n');
            printf("Syöttämänne valinta ei ole kelvollinen, valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
        }


/*            switch(choice) {
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
                case 4:
                    printf("Syötäthän vain numeroita! Valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
                    break;
                default:
                    printf("Syöttämänne valinta ei ole kelvollinen, valitse 1 Menussa esitetyistä vaihtoehdoista.\n");
                    while (getchar() != 'n');
                    break; */

        }
    return 0;
}

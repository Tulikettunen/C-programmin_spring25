//
// Created by tuuli on 19/03/2025.
//


//INCLUDES:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//
//DECLARATIONS:
//

#define MAIN_OPTS 4
#define PRINT_PAS_OPTS 2
#define ROWS 26
#define LINES (6 * ROWS)
#define FIRSTNL 20
#define LASTNL 40

typedef struct {
    char firstn[FIRSTNL];
    char lastn[LASTNL];
    int row;
    char seat;
}aPassenger;


//
//FUNCTION DECLARATIONS:
//

void create_csv();
void read_csv(aPassenger *passengers);
int input_handling(int *input, int range);  // Tehty ja toimii
char cinput_handling(char *input);
void print_passengers(aPassenger *passengers);
void print_seatmap(aPassenger *passengers);
// tähän asti tehty ja toimii

void reserve_seat();        //Kesken

int compare_first(const void *a, const void *b);
int compare_last(const void *a, const void *b);

void sort_first();      //Tekemättä
void sort_last();       //Tekemättä



//
//FUNCTIONS:
//




void create_csv(){
    FILE *csv_seats = fopen("csv_seat_reservations.csv", "w");

    if (csv_seats == NULL) {    //error message just in case
        printf("Error opening file!\n");
    }

    //create rows 1-26 with loop
    for (int row = 1; row <= 26; row++) {
        //create seat letters A-F with loop
        for (char seat = 'A'; seat <= 'F'; seat++) {
            fprintf(csv_seats, "free,free,%d,%c\n", row, seat);
        }
    }
    fclose(csv_seats);
    printf("CSV file 'seating_chart.csv' has been created successfully.\n");
}


void read_csv(aPassenger *passengers) {
    FILE *csv_seats;
    csv_seats = fopen("csv_seat_reservations.csv", "r");

    if(csv_seats == NULL) {     //error handling
        printf("Unable to open requested file.\n");
    }
    /*else {
        printf("file was successfully opened\n");
    } This was debugging print*/

    int read = 0;
    int rows = 0;
    do {        //reads the file info into a list of structs, passed to function as a pointer
        read = fscanf(csv_seats,
                    "%19[^,],%39[^,],%d,%c\n",
                    passengers[rows].firstn,
                    passengers[rows].lastn,
                    &passengers[rows].row,
                    &passengers[rows].seat);
        if (read == 4) rows++;
        //printf("Read %d values\n", read);  //debugging line

        if (read == LINES && !feof(csv_seats)) {         //more error handling
            printf("Something is off with the file.\n");
        }
        if (ferror(csv_seats)) {
            printf("There was an error when reading file.\n");
        }
    } while (!feof(csv_seats));
    //printf("read_csv() funktion finnished\n"); //debugging line

    fclose(csv_seats);
}


int input_handling(int *input, int range){
    int holder;
    char wrongchr;     // Tää tekee nyt sen pahuksen "bugin" korjauksen, jossa syöte "3dfgdr" hyväksytään, koska siinä on ensin 3. Jessss!! :D
    //while( (scanf("%d", &holder) != 1 ) || (scanf("%d", &wrongchr) == 1) || (holder < 1) || (holder > range) || (wrongchr != '\n') ){
    while( (scanf("%d%c", &holder, &wrongchr) != 2 ) || (holder < 1) || (holder > range) || (wrongchr != '\n') ){
        if (wrongchr != '\n') {
            while(getchar() != '\n');
        }
        printf("Invalid user input, please read the instructions and try again \n");
    }
    *input = holder;
    return holder;
}


char cinput_handling(char *input) {
    char holder;
    //char wrongchr;
    while( (scanf("%c", &holder) ==0 ) || (toupper(holder) < 'A') || (toupper(holder) > 'F') ){
        while(getchar() != '\n');
        printf("Invalid user input, please read the instructions and try again \n");
    }
    while(getchar() != '\n');
    holder = toupper(holder);
    *input = holder;
    return holder;
}


void print_passengers(aPassenger *passengers) {
    int opt;
    int *opti = &opt;
    read_csv(passengers);

    printf("Choose 1 to sort by first name, 2 to sort by last name:\n");
    switch (input_handling(opti, PRINT_PAS_OPTS)) {       //valitaan kumman nimen mukaan lajitellaan
        case 1:
            printf("case 1 valittu, lajitellaan etunimen mukaan\n");
            //sort_first(passengers);
            for (int i = 0; i < LINES; i++) {
                if (strcmp(passengers[i].firstn, "free") != 0){     //Skips the free seats from printing
                    printf("%-20s %-40s, row %-3d, seat %-3c\n",
                           passengers[i].firstn,
                           passengers[i].lastn,
                           passengers[i].row,
                           passengers[i].seat);
                }
            }
            printf("\n");
            break;
        case 2:
            printf("case 2 valittu, lajitellaan sukunimen mukaan\n");
            //sort_last(passengers);
            for (int i = 0; i < LINES; i++)
                if (strcmp(passengers[i].firstn, "free") != 0) {    //Skips the free seats from printing
                    printf("%-20s %-40s, row %-3d, seat %-3c\n",
                           passengers[i].lastn,
                           passengers[i].firstn,
                           passengers[i].row,
                           passengers[i].seat);
                }
            printf("\n");
            break;
        default:
            printf("something went wrong");
        break;
    }
}

void print_seatmap(aPassenger *passengers) {
    read_csv(passengers);


    for (int i = 0; i < LINES; i++) {  // Loop through all rows
        if (passengers[i].seat == 'A') {
            printf("\n%-*d", 4, passengers[i].row);  // Print row number aligned to left
        }

        if (strcmp(passengers[i].firstn, "free") != 0) {
            printf("x ");  // Replaceing the reserved seats with 'x'
        } else {
            printf("%c ", passengers[i].seat);
        }

        if (passengers[i].seat == 'C') {
            printf("  ");  // Add extra space between sections
        }
    }
    printf("\n\n");
}



void reserve_seat(aPassenger *passengers) {
    read_csv(passengers);//opening and updating the saved array of structs and closing it from read mode

    //Modifying the stuff init (through the saved array of structs)

    int chooserow, moreseats;
    char chooseseat;
    char * pchooseseat = &chooseseat;
    int * pchooserow = &chooserow;
    int * pmoreseats = &moreseats;
    bool ton = true;       //(TrueOrNot)
    while (ton) {
        printf("choose the line you want your seat from (1-%d)\n", ROWS);
        input_handling(pchooserow, ROWS);
        printf("Choose a seat A-F:\n");
        cinput_handling(pchooseseat);

        bool found = false;
        for (int i = 0; i < LINES; i++) {    //Looking for the correct line
            if ( (passengers[i].row == chooserow) && (passengers[i].seat == chooseseat) ) {
                found = true;
                if (strcmp(passengers[i].firstn, "free") == 0){
                    printf("Seat is free. Please give us your name (Firstname,Lastname)\n");
                    scanf(" %19[^,], %39[^\n]", passengers[i].firstn, passengers[i].lastn);
                    while (getchar() != '\n');
                    printf("Reservation added.\n");
                }
                else {
                    printf("Seat you wished for is taken, please pick another one,\n");
                }
            }
        }
        // If no seat was found in the loop
        if (!found) {
            printf("No matching seat found. Please enter valid row and seat.\n");
        }
        printf("Do you wish to continue reservation? (1 if yes,2 if no)\n");
        if (input_handling(pmoreseats, 2) ==2) {
            ton = false;
        }
    }

    //Rewriting modified list to .csv file
    FILE *csv_file = fopen("csv_seat_reservations.csv", "w");

    if (csv_file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < LINES; i++) {
        fprintf(csv_file, "%s,%s,%d,%c\n",
                passengers[i].firstn,
                passengers[i].lastn,
                passengers[i].row,
                passengers[i].seat);
    }

    fclose(csv_file);
    printf("File successfully updated.\n");
}


int compare_first(const void *a, const void *b) {
    return strcmp(((aPassenger *)a)->firstn, ((aPassenger *)b)->firstn);
}

int compare_last(const void *a, const void *b) {
    return strcmp(((aPassenger *)a)->lastn, ((aPassenger *)b)->lastn);
}

void sort_first(aPassenger *passengers) {
    qsort(passengers, ROWS, sizeof(aPassenger), compare_first);
}

void sort_last(aPassenger *passengers) {
    qsort(passengers, ROWS, sizeof(aPassenger), compare_last);
}



//
//MAIN PROGRAM:
//

int main(){
    create_csv();
    bool ton = true;
    aPassenger passengers[LINES];

    while (ton){
        int select;
        int * selected = &select;
        printf("Instructions how to use: \n"
               "Choose '1' to Reserve a Seat\n"
               "Choose '2' to Print Seatmap\n"
               "Choose '3' to Print Passengers\n"
               "Choose '4' to quit the program\n"
               ":\n");

        switch (input_handling(selected, MAIN_OPTS)) {
        case 1:
            printf("You chose to Reserve a Seat\n");
            reserve_seat(passengers);
            break;
        case 2:
            printf("You chose to Print a Seatmap\n");
            print_seatmap(passengers);
            break;
        case 3:
            printf("You chose to Print Passangers\n");
            print_passengers(passengers);
            break;
        case 4:
            printf("You have chosen to exit the program.\n"
                "Thank you for visiting us and welcome to start great trips with Airline Seatmanager again!\n");
            ton = false;
            break;
        default:
            printf("Something unexpected went wrong, please try again.");
            break;
        }
    }
    return 0;
}
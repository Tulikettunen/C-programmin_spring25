//
// Created by tuuli on 19/03/2025.
//

//Declarations:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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



//FUNCTION DECLARATIONS:
void create_csv();
void read_csv();
void reserve_seat();
void print_seatmap();
void print_passengers();
void sort_first();
void sort_last();

int input_handling(int *input, int range);  // Tehty ja toimii




//FUNCTIONS:
int input_handling(int *input, int range){
    int holder;
    char wrongchr;     // Tää tekee nyt sen pahuksen "bugin" korjauksen, jossa syöte "3dfgdr" hyväksytään, koska siinä on ensin 3. Jessss!! :D
    while( (scanf("%d%c", &holder, &wrongchr) == 0 ) || (holder < 1) || (holder > range) || (wrongchr != '\n') ){
        while(getchar() != '\n');
        printf("Invalid user input, please read the instructions and try again \n");
    }
    *input = holder;
    return holder;
}

void read_csv(aPassenger *passengers) {
    FILE *csv_seats;
    csv_seats = fopen("csv_seat_reservations", "r");

    if(csv_seats == NULL) {     //error handling
        printf("Unable to open requested file.\n");
    }
    else {
        printf("file was successfully opened");
    }

    int read = 0;
    int rows = 0;
    do {        //reads the file info into a list of structs, passed to function as a pointer
        read = fscanf(csv_seats,
                    "%FIRSTNL[^,],%LASTNL[^,],%d,%c\n",
                    passengers[rows].firstn,
                    passengers[rows].lastn,
                    &passengers[rows].row,
                    &passengers[rows].seat);
        if (read == 4) rows++;

        if (read == LINES && !feof(csv_seats)) {         //more error handling
            printf("Something is off with the file.\n");
        }
        if (ferror(csv_seats)) {
            printf("There was an error when reading file.\n");
        }
    } while (!feof(csv_seats));

    fclose(csv_seats);
}

void print_passengers(aPassenger *passengers) {
    read_csv(passengers);

    int opt;
    switch (input_handling(opt, PRINT_PAS_OPTS)) {       //valitaan kumman nimen mukaan lajitellaan
        case 1:
            printf("case 1 valittu, lajitellaan etunimen mukaan\n");
            //sort_first(passengers);
            for (int i = 0; i < LINES; i++)
                printf("%s %s, row %d, seat %c\n",
                       passengers[i].firstn,
                       passengers[i].lastn,
                       passengers[i].row,
                       passengers[i].seat);
            printf("\n");
            break;
        case 2:
            printf("case 2 valittu, lajitellaan sukunimen mukaan\n");
            //sort_last(passengers);
            for (int i = 0; i < LINES; i++)
                printf("%s %s, row %d, seat %c\n",
                       passengers[i].lastn,
                       passengers[i].firstn,
                       passengers[i].row,
                       passengers[i].seat);
            printf("\n");
            break;
        default:
            printf("something went wrong");
        break;
    }
}

void print_seatmap(aPassenger *passengers) {
    read_csv(passengers);

    for (int i = 0; i < LINES; i++) {       //käy läpi kaikki rivit tiedostosta
        char var = passengers[i].seat;
        if (var == 'A') {       //printataan rivejä: jos istuin on a, tulostaa rivinvaihdon, ja sen jälkeen rivinumeron
            printf("\n%d", passengers[i].row);
            if (strcmp(passengers[i].firstn, "free") != 0) {        //printataan istuimia: tarkistaa onko paikka vapaa, jos ei, lisää x
                printf("x");
            }
            else if (var == 'C') {      //tarkistaa onko paikka C, jos on, lisää tulostukseen välilyönnit käytävää varten
                printf("%c   ", passengers[i].seat);
            }
            else {  //jos paikka on vapaa, kirjoittaa istuimen kirjaimen
                printf("%c", passengers[i].seat);
            }
        }
    }



    char buffer[40];
    int count = 0;
    char seats[10] = "ABCDEF";

    for (int i = 0; i < ROWS; i++) {
        seats[10] = "ABCDEF";

        for (int s = 0; s < 6; s++) {
            if (strcmp(passengers[count].firstn, "free") != 0) {
                char seats[s]= "x";
                sprintf(buffer,"%d, %.3s   %.3s\n", i, seats, seats + 3);
            }
            count++;
        }

    }
}

void create_csv() {
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

//MAIN PROGRAM:
int main(){
    create_csv();
    bool ton = true;
    aPassenger passengers[LINES];

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
            //print_seatmap(passengers);
            break;
        case 3:
            printf("print passangers case 3 valittu\n");
            //print_passangers(passengers);
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
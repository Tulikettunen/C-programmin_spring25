//
// Created by tuuli on 05/03/2025.
/*You need to implement two functions: binary_reader and digit_counter

Binary reader takes a pointer to unsigned int as parameter and returns boolean value.
True means that a binary number was successfully read. Call read_line to read strings that are to be converted
to unsigned integers. Read_line returns true when a line was successfully read and false when
the end of input is reached.

Each valid input line contains a binary number that starts with prefix "0b". There may be white space
at beginning of the line before prefix. When a valid prefix is found binary reader reads binary digits
until it reads a character that is not a '0' or '1'.
Hint: when a valid digit is found shift the current value to left
and and set the new value to least significant bit.

Digit counter returns the minimum number of hexadecimal digits that are needed to print the number given as parameter.
Hint: you need find the leftmost group of 4 bits that have value greater than 0.
*/
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* call this function to read input */
bool read_line(char *line, size_t size);

/* you need to implement the following two functions */
bool binary_reader(unsigned int *pu);
int digit_counter(unsigned int nr);

//
bool binary_reader(unsigned int *pu){
    bool tof = false;
    char wtf = readline(

    return tof;
}

int digit_counter(unsigned int nr){

}

//
int main(int arcg, char **argv)
{
    unsigned int number = 0;

    while(binary_reader(&number)) {
        printf("%11u: %08X, %d\n", number, number, digit_counter(number));
    };

    return 0;

}
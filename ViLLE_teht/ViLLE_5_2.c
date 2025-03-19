//
// Created by tuuli on 07/03/2025.
//
/*Write a function named print_string. Print_string returns number of characters it prints.
Print_string takes two parameters: a character pointer (the string to print)
and a pointer to a function that takes a char as parameter and returns no value.
Print_string must use the function pointer to print the string character by character
and it may not modify the string it prints.*/
#include <stdio.h>

int print_string(char *string, char (*wtf)(char str)){
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        printf("%c", wtf(string[i]));
        count ++;
    }
    return count;
}


int main(){
    print_string(

}
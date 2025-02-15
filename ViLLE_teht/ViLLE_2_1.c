//
// Created by tuuli on 14/02/2025.
//
//Write a function that counts number of upper case letters in a string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int count(char *str){
    int count = 0;
    for (int i = 0; str[i] != 0; i++){
        if (isupper(str[i])){
            count ++;
        }
    }
    return count;
}

int main(){
    char string[30] = "udhgXDHd6xfgdUeg3g'rRGgR";
    //char *stringpoint = string;
    printf("%d uppercase letters found.\n", count(string));
    return 0;
}
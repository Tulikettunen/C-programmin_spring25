//
// Created by tuuli on 14/02/2025.
//
/*Write a program that fills 5 x 3 array so that first column contain numbers 1-5,
second column 6-10 and third column 11-15.

Note! The program may not print anything. The printing is handled by the test bench.
*/

#include <stdio.h>
#include <string.h>



int main(void){
    int matrix[5][3];
    int count = 1;
    for (int u = 0; u < 3; u++){
        for (int i = 0; i < 5; i++){
            matrix[i][u] = count;
            printf("%d\n", count);
            count ++;
        }
    }



    return 0;
}
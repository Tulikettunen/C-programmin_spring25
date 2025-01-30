//
// Created by tuuli on 29/01/2025.
//
#include <stdio.h>

int read_integer(int num);
float average(int sum, int count);

int read_integer(int num){
  printf("Enter a positive integer to calculate, or negative to stop:\n");
  if(scanf("%d", &num) != 1) {
      while(getchar() != '\n');
      printf("Invalid input, try again\n");
  }
  return num;
}

float average(int sum, int count){
  float average = sum / (count * 1.0);
  return average;
}

int main(){
    int sum = 0;
    int count = 0;
    int num = 0;

    printf("Enter an integers and I shall calculate the average!\n");
    while (num >= 0){
        num = read_integer(num);
        if(num > 0) {
            sum += num;
            count++;
            while(getchar() != '\n');
        }
    }

    printf("You entered %d positive numbers. The average is: %.3f \n", count, average(sum, count));
    return 0;
}
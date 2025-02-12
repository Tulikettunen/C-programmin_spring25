//
// Created by tuuli on 05/02/2025.
//
#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

bool read_positive(int *value){
	bool ton = true;
	int number;

	printf("Enter a positive value\n");
	if ((scanf("%d", &number) == 1) && number >0){
	    while(getchar() != '\n');
	    *value = number;
		ton = true;
	}else{
	    while(getchar() != '\n');
	    ton = false;
		printf("Invalid input.\n");
		}

	return ton;
}

int arvauspeli(int num){
	int cheated_no = num * 2 + 20;
	printf("You didn't get it right. I have %d euros.\n", cheated_no);
	return 0;
}

int main(){
	int pos_no = 0;
	int *pos_point = &pos_no;
	int count = 0;
    int truefalse = 1;
	while (truefalse == 1){
		printf("Guess how much money I have!\n");
		if(count == 3){
			truefalse = 0;		//lopeta ohjelma
		}
		else if (read_positive(pos_point) == false){
		    count += 1;
		}
		else{
			arvauspeli(pos_no);
		}
	}

	printf("I give up! See you later!");
	return 0;
}
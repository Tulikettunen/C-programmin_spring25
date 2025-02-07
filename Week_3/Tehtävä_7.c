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
	/*
	while ((scanf("%d", &number) != 1) || number < 0){
		while(getchar() == '\n');
		printf("Invalid input");
		ton = false;
	}
	*/
	if ((scanf("%d", &number) == 1) && number >0){
		*value = number;
		ton = true;
	}else{
		ton = false;
		while(getchar() == '\n');
		printf("Invalid input");
		}

	return ton;
}

int arvauspeli(){


	return 0;
}

int main(){
	int pos_no = 0;
	int *pos_point = &pos_no;
	int count = 0;
	if (read_positive(pos_point) == false){
		count += 1;
	}
	else if(count == 3){
		//lopeta ohjelma
		break;
	}
	else{
		//arvauspeli
	}



	return 0;
}
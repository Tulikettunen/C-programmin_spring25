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
	if ((scanf("%d", &number) == 1) && number >0){      //To do Joku tässä mättää, ei nappaa else rakenteesta false arvoa ja palauta sitä?
		*value = number;        //To do, kirjainsyötteistä osaa siirtyä elseen, miinus syötteestä jää jumiin terminaaliin
		ton = true;     //En jaksaaaaaa väsysleepyheadech just let me sleep goddamnit
	}else{
		ton = false;
		while(getchar() == '\n');
		printf("Invalid input.\n");
		}

	return ton;
}

int arvauspeli(int num){
	int cheated_no = num * 2 + 20;
	printf("You didn’t get it right. I have %d euros.\n", cheated_no);
	return 0;
}

int main(){
	int pos_no = 0;
	int *pos_point = &pos_no;
	int count = 0;
	while (true){
		printf("Guess how much money I have!\n");
		if (read_positive(pos_point) == false){
			count += 1;
		}
		else if(count == 3){
			false;		//lopeta ohjelma
		}
		else{
			arvauspeli(pos_no);
		}
	}

	printf("I give up! See you later!");
	return 0;
}
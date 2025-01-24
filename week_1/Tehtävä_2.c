//
// Created by tuuli on 24/01/2025.
//

#include <stdio.h>

float tax_calculator(float tax, float add_tax, float y_limit, float salary_arr[], int i, float accrual);
char print_result(float salary_arr, float tax_arr);



float tax_calculator(float tax, float add_tax, float y_limit, float salary_arr[], int i, float accrual){

    float tax_arr;

    /* Jos kertymä on suurempi kuin vuosiraja: listaan [i] = kktulo x lisäprosentti
        Tai jos kertymä + kktulo on pienempi kuin vuosiraja: listaan [i] = kktulo x veroprosentti
        Muuten: kertymä + kktulo - vuosiraja = ylimenevä osuus
          Listaan [i] = (ylimenevä * lisäprosentti) + (alimenevä * veroprosentti)
                ylimenevä = kertymä + kktulo - vuosiraja
                alimenevä = kktulo - ylimenevä
            => [(kertymä + kktulo - v.raja) * lisäpros] + {[kktulo - (kertymä + kktulo - v.raja)] * veropros}
            => [(kertymä + kktulo - v.raja) * lisäpros] + [(v.raja - kertymä) * veropros]

        Koko loopin lopuksi lisätään kertymään kktulo
     */

    if (accrual > y_limit) {
        tax_arr = salary_arr[i] * add_tax;
    }
    else if ((accrual + salary_arr[i]) < y_limit){
        tax_arr = salary_arr[i] * tax;
    }
    else {
        tax_arr = (((accrual + salary_arr[i])- y_limit) * add_tax) + ((y_limit - accrual) * tax);
    }
    return tax_arr;
}


int main(){
    float salary_arr [12];
    float tax_arr [12];

    float tax_rate; // muista jakaa 100, jotta saadaan kerroin muotoon.
    float yearly_limit;
    float add_tax_rate; // muista jakaa 100, jotta saadaa kerroin muotoon.
    float accrual = 0.0;

    printf("Please enter your tax rate: \n");
    scanf("%f", &tax_rate);
    tax_rate = tax_rate / 100;
    printf("Please enter your yearly income limit: \n");
    scanf("%f", &yearly_limit);
    printf("Please enter your additional tax rate: \n");
    scanf("%f", &add_tax_rate);
    add_tax_rate = add_tax_rate / 100;

    for (int i = 0; i < 12; i += 1){
        printf("Please enter your salary for month %d:\n", i + 1);
        scanf("%f", &salary_arr[i]);
    }
    for (int i = 0; i < 12; i += 1){
        tax_arr[i] = tax_calculator(tax_rate, add_tax_rate, yearly_limit, salary_arr, i, accrual);
        accrual += salary_arr[i];
    }
    printf("Month" "     salary" "         tax\n");
    for (int i = 0; i < 12; i += 1){
      printf(" %*.d  %*.2f  %*.2f \n", 4, i + 1, 9, salary_arr[i], 10, tax_arr[i]);
    }
    return 0;
}
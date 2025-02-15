//
// Created by tuuli on 15/02/2025.
//
/* Write a function that receives two structures as parameters. Each structure represents a point in plane.
Function calculates and returns distance between the points.
See http://www.purplemath.com/modules/distform.htm for help with the formula. */

#include <stdio.h>
#include <string.h>
#include <math.h>


struct point{
    int x;
    int y;
};


double distance(struct point a, struct point b){
    int xdis = a.x - b.x;
    int ydis = a.y - b.y;
    double hyp = sqrt( pow(xdis, 2) + pow(ydis, 2));
    //laske pythagoraan lauseella hyp. neliöjuuri(xdis^2 + ydis^2)
    return hyp;
}


int main(void) {
    struct point p1 = { 5, 8 };
    struct point p2 = { -3, 3 };
    struct point p3 = { 0, 4 };
    struct point p4 = { 3, 0 };

    printf("%.3f\n", distance(p1, p2));
    printf("%.3f\n", distance(p3, p4));

    return 0;
}
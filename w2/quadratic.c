#include <stdio.h>
#include <math.h>

int main(void){
    float a = 1;
    float b = 5;
    float c = 6;
    
    float discrim = b*b-4*a*c;
    float r1 = (sqrt(discrim)-b)/(2*a);
    float r2 = (-b-sqrt(discrim))/(2*a);
    
    printf("roots = %f\n, %f\n",r1,r2);
}

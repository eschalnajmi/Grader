#include <stdio.h>
#include <math.h>

int main(void){
    int a = 1;
    int b = 1.5;
    int c = -2.5;
    
    float d = b*b-4*a*c;
    
    if(d<0){
        printf("no roots");
    } else if(fabs(d)<1.0e-7){
        float r1 = b/(2*a);
        printf("root: %f\n", r1);
    } else{
        float r1 = (-b+sqrt(d))/(2*a);
        float r2 = (-b-sqrt(d))/(2*a);
        printf("roots: %f\n, %f/n",r1,r2);
    }
}

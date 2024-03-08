
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
 * Complete the code so that 3 command line values are given defining a quadratic equation.
 *   a x^2 + b x + c = 0
 * Find the roots of the equation and display the results
 *
 * Do not alter the print statements - the autograder expects them
 * You should use them at appropriate places in your program 
 */

int main( int argc, char *argv[] ) {
    
    if(argc>3){
        float a = atof(argv[1]);
        float b = atof(argv[2]);
        float c = atof(argv[3]);
        
        float d = b*b-4*a*c;
        
        
        printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c);
        if(d<0){
            printf("0 roots\n");
        } else if(fabs(d)<1.0e-7){
            float root1 = -b/(2*a);
            printf("1 root: %8.3f\n", root1);
        } else{
            float root1 = (-b+sqrt(d))/(2*a);
            float root2 = (-b-sqrt(d))/(2*a);
            printf("2 roots: %8.3f %8.3f\n", root1,root2 );
        }
    } else{
        printf(" Error: Usage:  ./quadratic3 a b c\n");
    }
    
  return 0;
}

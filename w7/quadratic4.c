#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quadraticSolver(float a, float b, float c){
    float d = b*b-4*a*c;
    
    printf(" Solutions for: (%5.2f) x^2 + (%5.2f) x + (%5.2f) = 0\n",a,b,c);
    if(d<0){
        printf("0 roots\n");
        return 0;
    } else if(fabs(d)<1.0e-7){
        float root1 = -b/(2*a);
        printf("1 root: %8.3f\n", root1);
        return root1;
    } else{
        float root1 = (-b+sqrt(d))/(2*a);
        float root2 = (-b-sqrt(d))/(2*a);
        printf("2 roots: %8.3f %8.3f\n", root1,root2 );
        return root1;
        return root2;
    }
}

int main( int argc, char *argv[] ) {
    
    if(argc>3){
        float a = atof(argv[1]);
        float b = atof(argv[2]);
        float c = atof(argv[3]);
        
        quadraticSolver(a,b,c);
        
        }
    else{
        printf(" Error: Usage:  ./quadratic3 a b c\n");
    }
  return 0;
}

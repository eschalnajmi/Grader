#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int combinations(int n, int k){
    int comb;
    
    comb = factorial(n) / factoria(k)*factorial(n-k);
    
    return comb;
}

int factorial(max){
    
    if(max < 0){
        printf("Invalid argument");
        exit();
    }
    
    int max;
    int total = 1;
    
    for(int i=1; i<max+1;i++){
        total = total*i;
    }
    
    printf("%i\n",total);
    
    return total;
}

void main(int argc, char *argv[]){
    
    int max = atoi(argv[1]);
    
    int total = factorial(max);
    
    combinations(total, max);
    
}

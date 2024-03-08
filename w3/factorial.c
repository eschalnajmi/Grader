#include <stdio.h>

int main(void){
    int max = 4;
    int total = 1;
    
    for(int i=1; i<max+1;i++){
        total = total*i;
    }
    
    printf("%i\n",total);
}

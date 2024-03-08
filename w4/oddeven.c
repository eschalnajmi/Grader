
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    
    int data[] = { 5, 7, 3, 8, 15, 12, 6,
                   10, 25, 7, 23, 18, 5, 2, 
                   18, 5, 2, 16, 35, 107, 13, 
                   15, 12, 15, 7, 83, 98, 16 };
    int x = 1;
    int y = 0;
    
    int *odd = (int *) calloc( 16, sizeof(int) );
    int *even = (int *) calloc( 12, sizeof(int) );
    
    for(int i = 0; i<27; i++){
        
        if((data[i]%2)==0){
            
            even[x] = data[i];
            x++;
            
        } else {
            
            odd[y] = data[i];
            y++;
            
        }
        
    }
    
    printf("number of even: %i\n", x);
    printf("number of odd: %i\n", y);
    
    for(int i =0; i<16; i++){
        printf("odd: %i\n", odd[i]);
    }
    
    for(int i = 0; i< 12; i++){
        printf("even: %i\n", even[i]);
    }
    
    free(even);
    free(odd);

    return 0;
    
}

#include <stdio.h>

int main(void){

    int first[4][4];
    int second [4][4];
    int third[4][4];

    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            first[i][j] = 2*i-j;
            second[i][j] = 3 + j - 2*i;
        }
    }
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            third[i][j] = first[i][j]+second[i][j];
        }
    }
    for(int i=0; i<4;i++){
        printf("%i %i %i %i\n", first[i][0], first[i][1],first[i][2],first[i][3]);
    }
    
    for(int i=0; i<4;i++){
        printf("%i %i %i %i\n", second[i][0], second[i][1],second[i][2],second[i][3]);
    }
    
    for(int i=0; i<4;i++){
        printf("%i %i %i %i\n", third[i][0], third[i][1],third[i][2],third[i][3]);
    }
    return 0;
}

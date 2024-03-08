
#include <stdio.h>

int main( void ) {
    int data[] = { 0, 4, 4, 4, 0,
                   1, 0, 1, 2, 1,
                   2, 2, 1, 2, 4,
                   1, 4, 4, 0, 2,
                   2, 2, 2, 4, 4 };
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    int five = 0;
    
    for(int i = 0; i<25; i++){
        if(data[i] == 1){
            one++;
        } else if(data[i] == 2){
            two++;
        } else if(data[i] == 3){
            three++;
        } else if(data[i] == 4){
            four++;
        } else if(data[i] == 5){
            five++;
        }
    }
    
    printf("one: %i\n", one);
    printf("two: %i\n", two);
    printf("three: %i\n", three);
    printf("four: %i\n", four);
    printf("five: %i\n", five);

    return 0;
}

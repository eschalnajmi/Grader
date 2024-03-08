#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc > 1){
        printf("%i\n", atoi(argv[1]));
        printf("%s\n", argv[2]);
        printf("%f\n", atof(argv[3]));
        printf("%s\n", argv[4]);
    }
    return 0;
}

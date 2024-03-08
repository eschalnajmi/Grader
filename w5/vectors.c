#include <stdio.h>
#include <stdlib.h>

int main(void){
    float vec1[] = {1.0, 1.0, 1.0, 1.0};
    float vec2[] = {2.0, 2.0, 2.0, 2.0, 2.0};
    float *vec3;
    
    vec3 = (float *) calloc( 9, sizeof(float) );
    
    for(int i = 0; i < 4; i++){
        vec3[i] = vec1[i];
        printf("%f\n", vec3[i]);
    }
    int j = 0;
    for(int i = 4; i < 9; i++){
        vec3[i] = vec2[j];
        j++;
        printf("%f\n", vec3[i]);
    }
    
    free(vec3);
}

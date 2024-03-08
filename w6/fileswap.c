#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc>1){
        
        //int nums[];
        int nrow = atoi(argv[2]);
        int ncol = atoi(argv[3]);
        
        FILE *fp;
        fp = fopen(argv[1], "r");
        
        FILE *fp2;
        fp2 = fopen(argv[4],"w");
        
        int **array;
        int **nums;
        
        array = (int **) calloc(nrow, sizeof(int*));
        for(int i=0; i<nrow; i++){
            array[i] = (int*)calloc(ncol, sizeof(int));
        }
        nums = (int **) calloc(ncol, sizeof(int*));
        for(int i=0; i<nrow; i++){
            nums[i] = (int*)calloc(nrow, sizeof(int));
        }
        
        //fscanf(fp, "%i", nums[][]);
        
        for(int i=0;i<ncol;i++){
            for(int j = 0; j<nrow; j++){
                fscanf(fp, "%i", &nums[j][i]);
                array[i][j] = nums[j][i];
                fprintf(fp2," %i",array[i][j]);
            }
            fprintf(fp2, " \n");
        }
        
        for(int i=0;i<ncol;i++){
            for(int j = 0; j<nrow; j++){
                printf(" %i", array[i][j]);
            }
            printf(" \n");
        }
        
        free(nums);
        free(array);
        fclose(fp);
        fclose(fp2);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char **argv ) {
    
    // declare variables
    int nrow = atoi(argv[1]);
    int ncol = atoi(argv[2])+1;
    
    // ensuring command line argument valid
    if(argc<4){
        printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
        exit(-1);
    }
    if(nrow < 1 || nrow > 100){
        printf("Requires 1 to 100 students. Exiting.\n");
        exit(-1);
    } else if(ncol < 1 || ncol > 8){
        printf("Requires 1 to 8 grades. Exiting.\n");
        exit(-1);
    }
    
    // open the files
    printf("Input file. Opening.\n");
    FILE *fp;
    fp = fopen(argv[3], "r");
    
    printf("Output file. Opening.\n");
    FILE *fp2;
    fp2 = fopen("averages.txt", "w");
    
    // check if file exists
    if(fp == NULL){
        printf("Input file does not exist. Exiting.\n");
        exit(-1);
    }
    
    // declare the array
    float **array;
    array = (float **) calloc(nrow, sizeof(float*));
    for(int i=0; i<nrow; i++){
        array[i] = (float*)calloc(ncol, sizeof(float));
    }

    // read from file
    for(int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            fscanf(fp, "%f", &array[i][j]);
        }
    }
    
    // validate the ids
    printf("Checking data.\n");
    for(int i = 0; i < nrow; i++){
        int id = array[i][0];
        if(id < 2022000 || id > 2022099){
            printf("Found an invalid student id: %d. Exiting.\n", id );
            exit(-1);
        }
    }
    
    // validate the grades
    for(int i = 0; i < nrow; i++){
        for(int j = 1; j < ncol; j++){
            int id = array[i][0];
            int grade = array[i][j];
            if(grade < -1 || grade > 100){
                printf("Found an invalid grade: id %d grade %d. Exiting.\n", id, grade);
                exit(-1);
            }
            
            // correcting grades
            if(grade == -1){
                array[i][j] = -1;
            } else if(grade < 20){
                printf("Correcting student %d grade %d\n", id,grade );
                array[i][j] = 20;
            } else if(grade > 90){
                printf("Correcting student %d grade %d\n", id,grade );
                array[i][j] = 90;
            }
        }
    }
    
    // calculating averages
    printf("Computing averages.\n");
    for(int i = 0; i < nrow; i++){
        int div = nrow;
        int id = array[i][0];
        float total = 0.0;
        for(int j = 0; j < ncol; j++){
            if(array[i][j] != -1){
                total += array[i][j];
            } else{
                div--;
            }
        }
        float avg = total/div;
        int average = round(avg);
        
        // add averages to file
        fprintf(fp2, " %d %i\n", id, average);
    }
    
    // close remaining files and free memory space
    printf("Output file. Closing.\n");
    fclose(fp2);
    free(array);
    printf("Input file. Closing.\n");
    fclose(fp);

  return 0;
}


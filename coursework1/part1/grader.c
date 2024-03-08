#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char **argv ) {
    
    // ensuring command line argument valid
    if(argc > 1){
        
        // declare the array
        float nums[32][5];
        
        // opening the file
        printf("Output file. Opening.\n");
        FILE *fp2;
        fp2 = fopen("averages.txt", "w");
        
        printf("Input file. Opening.\n");
        FILE *fp;
        fp = fopen(argv[1], "r");
        
        // checking if file exists
        if(fp==NULL){
            printf("Input file does not exist. Exiting.\n");
            exit(-1);
        }
            
        // read from the file
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 5; j++){
                fscanf(fp, "%f", &nums[i][j]);
            }
        }
        
        // close the file
        printf("Input file. Closing.\n");
        fclose(fp);
            
        // validate the ids
        printf("Checking data.\n");
        for(int i = 0; i < 32; i++){
            int id = nums[i][0];
            if(id < 2022000 || id > 2022099){
                printf("Found an invalid student id: %d. Exiting.\n",id);
                exit(-1);
            }
        }
        
        // validate the grades
        for(int i = 0; i < 32; i++){
            for(int j = 1; j < 5; j++){
                int id = nums[i][0];
                int grade = nums[i][j];
                if(grade < 0 || grade > 100){
                    printf("Found an invalid grade: id %d grade %d. Exiting.\n", id,grade );
                    exit(-1);
                }
                
                // correcting grades of students
                if(grade < 20){
                    printf("Correcting student %d grade %d\n", id, grade);
                    nums[i][j] = 20;
                } else if(grade > 90){
                    printf("Correcting student %d grade %d\n", id, grade);
                    nums[i][j] = 90;
                }
            }
        }
        
        // calculating averages
        printf("Computing averages.\n");
        for(int i = 0; i < 32; i++){
            int id = nums[i][0];
            float total = nums[i][1] + nums[i][2] + nums[i][3] + nums[i][4];
            float avg = total/4;
            int average = round(avg);
            
            //adding averages to file
            fprintf(fp2, " %d %i\n", id, average);
        }
        
        // close the output file
        printf("Output file. Closing.\n");
        fclose(fp2);
        
    } else {
        printf("No input file name given. Exiting.\n");
        exit(-1);
    }
    
    return 0;
}


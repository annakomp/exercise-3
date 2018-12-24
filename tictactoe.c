#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "mylib.h"
#include "ec.h"
#include <signal.h>


#define SIZE 3

int main(int argc, char *argv[]){

    int myfd[2], dummy1, dummy2,i;
    char **table, input[4];
    pid_t pid1, pid2;
    coordinates_t coordinates;
    
    
    
    if(pipe(myfd)==-1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    
    pid1=fork();
    

    if (pid1==0){
        /*child 1*/
        alloc_array_2d(&table, SIZE);

        initialise_table(&table, SIZE);
        print_table(&table, SIZE);

        fgets(input,4,stdin);
        printf("%s\n",input);
        
        win_checker(&table, SIZE);

        free_array_2d(&table, SIZE);

    }
    else if (pid1>0){
        pid2=fork();

        if(pid2==0){
            /*child 2*/
            
            alloc_array_2d(&table, SIZE);

            initialise_table(&table, SIZE);
            print_table(&table, SIZE);
            fgets(input,4,stdin);
            printf("%s\n",input);
            
            win_checker(&table, SIZE);

            free_array_2d(&table, SIZE);
            
        }
        else if(pid2>0){
            /*parent*/
            wait(NULL);
        }
        else{
            perror("fork");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
    }
    else{
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    return 0;

}

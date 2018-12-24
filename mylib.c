#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "mylib.h"
 
void alloc_array_2d(char*** A, int size){
    int i;
    *A=(char**)malloc(sizeof(char*)*size);
    if(*A==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<size;i++){
        (*A)[i]=(char*)malloc(sizeof(char)*size);
        if((*A)[i]==NULL){
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
}
 
void free_array_2d(char*** A, int size){
    int i;
    for(i=0;i<size;i++){
        free((*A)[i]);
    }
    free(*A);
}
 
void initialise_table(char ***A, int size){
    int i;
    for(i=0;i<size;i++){
        strcpy((*A)[i], "   ");
    }
}
 
void print_table(char ***A, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%s", (*A)[i]);
        printf("\n");
    }
}
 
void win_checker(char ***A, int size){
    int k;
    for(k=0; k<size; k++){
        if((*A)[k][0]==(*A)[k][1] && (*A)[k][0]==(*A)[k][2] && (*A)[k][0]!=' '){
           
        }
 
        if((*A)[0][k]==(*A)[1][k] && (*A)[0][k]==(*A)[2][k] && (*A)[0][k]!=' '){
           
        }
    }
    if((*A)[0][0]==(*A)[1][1] && (*A)[0][0]==(*A)[2][2] && (*A)[0][0]!=' ') {
       
    }
    if((*A)[0][2]==(*A)[1][1] && (*A)[0][0]==(*A)[2][0] && (*A)[0][2]!=' '){
       
    }
}

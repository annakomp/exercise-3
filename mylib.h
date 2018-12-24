#ifndef MYLIB_H
#define MYLIB_H
void alloc_array_2d(char*** A, int size);
void free_array_2d(char*** A, int size);
void initialise_table(char ***A, int size);
void print_table(char ***A, int size);
void win_checker(char ***A, int size);
typedef struct coordinates{
    int x;
    int y;
}coordinates_t;
#endif

#ifndef NOTA_H
#define NOTA_H

#define MAX_SIZE 100

void insert_grade(float notas[], int *count); // pointer
void remove_grade(float notas[], int *count); // pointer
void update_grade(float notas[], int count);
void display_grades(float notas[], int count);
void display_stats(float notas[], int count);

#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() 
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar(); 
    
    char names[numStudents][50];
    int rollNos[numStudents];
    float marks[numStudents][5][3];
    char grades[numStudents][5];
    for (int s = 0; s < numStudents; s++) {
        printf("\nStudent %d:\n", s+1);
        printf("Enter name: ");
        fgets(names[s], sizeof(names[s]), stdin);
        names[s][strcspn(names[s], "\n")] = '\0'; 
        
        printf("Enter roll number: ");
        char rollNoStr[10];
        fgets(rollNoStr, sizeof(rollNoStr), stdin);
        sscanf(rollNoStr, "%d", &rollNos[s]);
        
        printf("Enter marks for 5 subjects:\n");
        for (int i = 0; i < 5; i++) {
            printf("Subject %d:\n", i+1);
            printf("ISA1: ");
            scanf("%f", &marks[s][i][0]);
            printf("ISA2: ");
            scanf("%f", &marks[s][i][1]);
            printf("ESA: ");
            scanf("%f", &marks[s][i][2]);
        }

        calculateGrades(marks[s], grades[s]); 
        getchar(); 
    }

    printf("\nGrade Cards:\n");
    for (int s = 0; s < numStudents; s++) {
        printf("\nGrade Card for %s (Roll No: %d):\n", names[s], rollNos[s]);
        printf("Subject\tISA1\tISA2\tESA\tGrade\n");
        for (int i = 0; i < 5; i++) {
            printf("%d\t%.2f\t%.2f\t%.2f\t%c\n", i+1, marks[s][i][0], marks[s][i][1], marks[s][i][2], grades[s][i]);
        }
    }

    return 0;
}
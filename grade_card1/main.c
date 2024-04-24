#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


char* readLine() {
    char* line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

int main() 
{
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();
    struct Student *head = NULL;
    
    for (int s = 0; s < numStudents; s++) {
        struct Student *newStudent = createStudent();
        if (newStudent == NULL) {
            printf(" Exit.\n");
            exit(EXIT_FAILURE);
        }
        
        printf("\nStudent %d:\n", s+1);
        printf("Enter name: ");
        char *name = readLine();
        strcpy(newStudent->name, name);
        free(name);
        
        printf("Enter roll number: ");
        scanf("%d", &(newStudent->rollNo));
        getchar(); // Consume newline
        
        printf("Enter marks for 5 subjects:\n");
        for (int i = 0; i < 5; i++) {
            printf("Subject %d:\n", i+1);
            printf("ISA1: ");
            scanf("%f", &(newStudent->marks[i][0]));
            printf("ISA2: ");
            scanf("%f", &(newStudent->marks[i][1]));
            printf("ESA: ");
            scanf("%f", &(newStudent->marks[i][2]));
            getchar(); // Consume newline
        }
        
        calculateGrades(newStudent);
        
        if (head == NULL) {
            head = newStudent;
        } else {
            struct Student *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }

    printf("\nGrade Cards:\n");
    printGradeCards(head);

    freeStudents(head);

    return 0;
}

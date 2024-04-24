#include "student.h"
#include <stdio.h>
#include <stdlib.h>

struct Student *createStudent() {
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    if (student != NULL) {
        student->next = NULL;
    }
    return student;
}

void calculateGrades(struct Student *student) {
    for (int i = 0; i < 5; i++) {
        float totalMarks = 0;
        for (int j = 0; j < 3; j++) {
            totalMarks += student->marks[i][j];
        }
        float avgMarks = totalMarks / 3.0;

        if (avgMarks >= 90) student->grades[i] = 'S';
        else if (avgMarks >= 80) student->grades[i] = 'A';
        else if (avgMarks >= 70) student->grades[i] = 'B';
        else if (avgMarks >= 60) student->grades[i] = 'C';
        else if (avgMarks >= 50) student->grades[i] = 'D';
        else if (avgMarks >= 40) student->grades[i] = 'E';
        else student->grades[i] = 'F';
    }
}

void printGradeCards(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        printf("\nGrade Card for %s (Roll No: %d):\n", current->name, current->rollNo);
        printf("Subject\tISA1\tISA2\tESA\tGrade\n");
        for (int i = 0; i < 5; i++) {
            printf("%d\t%.2f\t%.2f\t%.2f\t%c\n", i+1, current->marks[i][0], current->marks[i][1], current->marks[i][2], current->grades[i]);
        }
        current = current->next;
    }
}

void freeStudents(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
    }
}

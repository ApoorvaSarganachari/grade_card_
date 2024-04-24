#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[50];
    int rollNo;
    float marks[5][3];
    char grades[5];
    struct Student *next;
};

struct Student *createStudent();
void calculateGrades(struct Student *student);
void printGradeCards(struct Student *head);
void freeStudents(struct Student *head);

#endif

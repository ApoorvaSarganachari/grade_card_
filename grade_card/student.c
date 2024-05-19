#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void inputStudentData(char name[], float exam_marks[]) {
    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter marks for the subjects (ISA1, ESA for each subject):\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d - ISA1: ", i + 1);
        scanf("%f", &exam_marks[i * 2]);
        printf("Subject %d - ESA: ", i + 1);
        scanf("%f", &exam_marks[i * 2 + 1]);
    }
}

void loadStudents(Student students[], int *num_students) {
    FILE *file = fopen("marks.csv", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file); // Skip header

    while (fgets(line, sizeof(line), file) && *num_students < MAX_STUDENTS) {
        sscanf(line, "%49[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
               students[*num_students].name,
               &students[*num_students].exam_marks[0], &students[*num_students].exam_marks[1],
               &students[*num_students].exam_marks[2], &students[*num_students].exam_marks[3],
               &students[*num_students].exam_marks[4], &students[*num_students].exam_marks[5],
               &students[*num_students].exam_marks[6], &students[*num_students].exam_marks[7],
               &students[*num_students].exam_marks[8], &students[*num_students].exam_marks[9]);
        (*num_students)++;
    }

    fclose(file);
}

void saveStudents(Student students[], int num_students) {
    FILE *file = fopen("marks.csv", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "name,Physics - Internals,Physics - ESA,PSWC - Internals,PSWC - ESA,Mathematics - Internals,Mathematics - ESA,Electrical - Internals,Electrical - ESA,Mechanical - Internals,Mechanical - ESA\n");
    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
                students[i].name,
                students[i].exam_marks[0], students[i].exam_marks[1],
                students[i].exam_marks[2], students[i].exam_marks[3],
                students[i].exam_marks[4], students[i].exam_marks[5],
                students[i].exam_marks[6], students[i].exam_marks[7],
                students[i].exam_marks[8], students[i].exam_marks[9]);
    }

    fclose(file);
}

void addStudent(Student students[], int *num_students) {
    if (*num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    printf("Enter details for new student:\n");
    inputStudentData(students[*num_students].name, students[*num_students].exam_marks);
    (*num_students)++;
    saveStudents(students, *num_students);
}

void deleteStudent(Student students[], int *num_students) {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the student to delete: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            (*num_students)--;
            break;
        }
    }

    if (found) {
        printf("Student %s deleted successfully.\n", name);
        saveStudents(students, *num_students);
    } else {
        printf("Student %s not found.\n", name);
    }
}

void generateGradeCard(const char name[], const float exam_marks[]) {
    printf("\nGrade Card for %s:\n", name);
    printf("Subject\tISA1\tESA\tTotal\tGrade\n");

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        float total = exam_marks[i * 2] + exam_marks[i * 2 + 1];
        char grade = gradeAssignment(total);
        printf("Subject %d\t%.2f\t%.2f\t%.2f\t%c\n", i + 1, exam_marks[i * 2], exam_marks[i * 2 + 1], total, grade);
    }
}

char gradeAssignment(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

float calculateAverage(float marks[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

int gradePoint(char grade) {
    switch (grade) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        default: return 0;
    }
}

float calculateSGPA(const char grades[]) {
    int totalPoints = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        totalPoints += gradePoint(grades[i]);
    }
    return totalPoints / (float)NUM_SUBJECTS;
}

#include "student.h"
#include <stdio.h>

void calculateGrades(float marks[5][3], char grades[5]) {
    for (int i = 0; i < 5; i++) {
        float totalMarks = 0;
        for (int j = 0; j < 3; j++) {
            totalMarks += marks[i][j];
        }
        float avgMarks = totalMarks / 3.0;

        if (avgMarks >= 90) grades[i] = 'S';
        else if (avgMarks >= 80) grades[i] = 'A';
        else if (avgMarks >= 70) grades[i] = 'B';
        else if (avgMarks >= 60) grades[i] = 'C';
        else if (avgMarks >= 50) grades[i] = 'D';
        else if (avgMarks >= 40) grades[i] = 'E';
        else grades[i]='F';
}
}
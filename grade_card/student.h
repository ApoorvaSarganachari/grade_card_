#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LEN 50
#define NUM_SUBJECTS 5
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    float exam_marks[NUM_SUBJECTS * 2]; // Two marks per subject (ISA1 and ESA)
} Student;

void inputStudentData(char name[], float exam_marks[]);
void loadStudents(Student students[], int *num_students);
void saveStudents(Student students[], int num_students);
void addStudent(Student students[], int *num_students);
void deleteStudent(Student students[], int *num_students);
void generateGradeCard(const char name[], const float exam_marks[]);
float calculateAverage(float marks[], int size);
char gradeAssignment(float avg);
int gradePoint(char grade);
float calculateSGPA(const char grades[]);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;

    loadStudents(students, &num_students);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Grade Cards\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &num_students);
                break;
            case 2:
                deleteStudent(students, &num_students);
                break;
            case 3:
                for (int i = 0; i < num_students; i++) {
                    generateGradeCard(students[i].name, students[i].exam_marks);
                }
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

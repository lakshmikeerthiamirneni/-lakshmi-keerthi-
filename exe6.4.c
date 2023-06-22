#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compare(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    
    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    }
    
    return 0;
}

void sortStudents(struct Student *students, int numStudents) {
    qsort(students, numStudents, sizeof(struct Student), compare);
}

void displayStudents(const struct Student *students, int numStudents) {
    printf("\nStudent details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n",
               students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  // Clear the newline character from the input buffer

    struct Student *students = malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array of structures (e.g., using user input or any other method)

    sortStudents(students, numStudents);
    displayStudents(students, numStudents);

    free(students);
    return 0;
}
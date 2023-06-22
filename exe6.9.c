#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student *students, int numStudents, int k) {
    if (numStudents <= 1) {
        return; // No need to rotate if there's only one or no students
    }

    k = k % numStudents; // Adjust k to handle rotations larger than the array size

    if (k < 0) {
        k = numStudents + k; // Adjust negative k values
    }

    struct Student *temp = malloc(k * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy the last K students to the temporary array
    memcpy(temp, &students[numStudents - k], k * sizeof(struct Student));

    // Shift the remaining students to the right by K positions
    memmove(&students[k], students, (numStudents - k) * sizeof(struct Student));

    // Copy the students from the temporary array to the beginning
    memcpy(students, temp, k * sizeof(struct Student));

    free(temp);
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
    getchar(); // Clear the newline character from the input buffer

    struct Student *students = malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array of structures (e.g., using user input or any other method)

    int k;
    printf("Enter the number of positions to rotate (K): ");
    scanf("%d", &k);
    getchar(); // Clear the newline character from the input buffer

    rotateStudents(students, numStudents, k);
    printf("Array rotated successfully.\n");
    displayStudents(students, numStudents);

    free(students);
    return 0;
}
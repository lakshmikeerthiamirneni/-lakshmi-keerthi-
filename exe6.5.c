#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchStudentByName(const struct Student *students, int numStudents, const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  // Found the student at index i
        }
    }
    
    return -1;  // Student not found
}

void displayStudent(const struct Student *student) {
    printf("Roll No: %d, Name: %s, Marks: %.2f\n",
           student->rollno, student->name, student->marks);
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

    char searchName[20];
    printf("Enter the name of the student to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove the trailing newline character

    int index = searchStudentByName(students, numStudents, searchName);
    if (index != -1) {
        printf("Student found:\n");
        displayStudent(&students[index]);
    } else {
        printf("Student not found.\n");
    }

    free(students);
    return 0;
}
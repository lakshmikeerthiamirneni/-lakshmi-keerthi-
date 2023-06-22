#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int entryNoToDelete = 2;  // Example: EntryNo to delete

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int foundEntry = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo != entryNoToDelete) {
            fputs(line, tempFile);
        } else {
            foundEntry = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data.csv");
    rename("temp.csv", "data.csv");

    if (foundEntry) {
        printf("Entry deleted successfully.\n");
    } else {
        printf("Entry not found.\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int entryNoToDelete = 2;  // Example: EntryNo to delete

    LogEntry logEntries[100];
    int numEntries = 0;

    char line[MAX_LINE_LENGTH];
    int foundEntry = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo != entryNoToDelete) {
            char *token;
            token = strtok(line, ",");
            logEntries[numEntries].entryNo = atoi(token);

            token = strtok
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
    FILE *file = fopen("data.csv", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int entryNoToUpdate = 2;  // Example: EntryNo to update
    float newTemperature = 25.0;  // Example: New Temperature value

    char line[MAX_LINE_LENGTH];
    int foundEntry = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo == entryNoToUpdate) {
            foundEntry = 1;

            // Update the temperature value in the line
            char *token = strtok(line, ",");
            for (int i = 0; i < 2; i++) {
                token = strtok(NULL, ",");
            }

            sprintf(token, "%.2f", newTemperature);

            // Rewind file position and write the updated line
            fseek(file, -strlen(line), SEEK_CUR);
            fputs(line, file);

            break;
        }
    }

    fclose(file);

    if (foundEntry) {
        printf("Entry updated successfully.\n");
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
    FILE *file = fopen("data.csv", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int entryNoToUpdate = 2;  // Example: EntryNo to update
    float newTemperature = 25.0;  // Example: New Temperature value

    LogEntry logEntries[100];
    int numEntries = 0;

    char line[MAX_LINE_LENGTH];
    int foundEntry = 0;

    while (fgets(line, MAX_LINE_LENGTH))
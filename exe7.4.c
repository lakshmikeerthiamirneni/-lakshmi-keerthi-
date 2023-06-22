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

void swap(LogEntry *a, LogEntry *b) {
    LogEntry temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    LogEntry logEntries[100];
    int numEntries = 0;

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *token;
        token = strtok(line, ",");

        logEntries[numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].timestamp, token);

        numEntries++;
    }

    fclose(file);

    // Bubble Sort based on Temperature in descending order
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = 0; j < numEntries - i - 1; j++) {
            if (logEntries[j].temperature < logEntries[j + 1].temperature) {
                swap(&logEntries[j], &logEntries[j + 1]);
            }
        }
    }

    file = fopen("sorted_data.csv", "w");
    if (file == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n", logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }

    fclose(file);

    printf("File sorted and saved as sorted_data.csv\n");

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
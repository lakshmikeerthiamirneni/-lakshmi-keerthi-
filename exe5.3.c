#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} TimePeriod;

// Function to calculate the difference between two time periods
TimePeriod calculateTimeDifference(TimePeriod t1, TimePeriod t2) {
    TimePeriod diff;

    // Convert the time periods to seconds
    int time1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int diffSeconds = (time1 > time2) ? (time1 - time2) : (time2 - time1);

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    TimePeriod t1, t2, diff;

    // Read the first time period from the user
    printf("Enter the first time period:\n");
    printf("Hours: ");
    scanf("%d", &t1.hours);
    printf("Minutes: ");
    scanf("%d", &t1.minutes);
    printf("Seconds: ");
    scanf("%d", &t1.seconds);

    // Read the second time period from the user
    printf("\nEnter the second time period:\n");
    printf("Hours: ");
    scanf("%d", &t2.hours);
    printf("Minutes: ");
    scanf("%d", &t2.minutes);
    printf("Seconds: ");
    scanf("%d", &t2.seconds);

    // Calculate the difference between the time periods
    diff = calculateTimeDifference(t1, t2);

    // Display the difference
    printf("\nDifference between the time periods:\n");
    printf("Hours: %d\n", diff.hours);
    printf("Minutes: %d\n", diff.minutes);
    printf("Seconds: %d\n", diff.seconds);

    return 0;
}
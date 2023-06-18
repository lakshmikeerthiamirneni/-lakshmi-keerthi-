#include <stdio.h>

void findSmallestLargestDigits(int n, ...);

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    findSmallestLargestDigits(n);

    return 0;
}

void findSmallestLargestDigits(int n, ...) {
    if (n <= 0) {
        printf("Not Valid\n");
        return;
    }

    int smallestDigit = 9;
    int largestDigit = 0;

    va_list numbers;
    va_start(numbers, n);

    for (int i = 0; i < n; i++) {
        int currentNumber = va_arg(numbers, int);

        while (currentNumber != 0) {
            int digit = currentNumber % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            currentNumber /= 10;
        }
    }

    va_end(numbers);

    if (smallestDigit == 9 && largestDigit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallestDigit);
        printf("Largest Digit: %d\n", largestDigit);
    }
}
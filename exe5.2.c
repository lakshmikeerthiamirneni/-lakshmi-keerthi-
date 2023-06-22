#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Function to read a complex number from the user
Complex readComplexNumber() {
    Complex num;

    printf("Enter the real part: ");
    scanf("%lf", &num.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &num.imag);

    return num;
}

// Function to write a complex number to the console
void writeComplexNumber(Complex num) {
    printf("Complex number: %.2lf + %.2lfi\n", num.real, num.imag);
}

// Function to add two complex numbers
Complex addComplexNumbers(Complex num1, Complex num2) {
    Complex result;

    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;

    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplexNumbers(Complex num1, Complex num2) {
    Complex result;

    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);

    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    num1 = readComplexNumber();

    printf("\nEnter the second complex number:\n");
    num2 = readComplexNumber();

    printf("\n");

    sum = addComplexNumbers(num1, num2);
    printf("Addition of two complex numbers:\n");
    writeComplexNumber(sum);

    product = multiplyComplexNumbers(num1, num2);
    printf("\nMultiplication of two complex numbers:\n");
    writeComplexNumber(product);

    return 0;
}
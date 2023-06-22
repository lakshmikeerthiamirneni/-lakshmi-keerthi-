#include <stdio.h>

typedef struct {
    int field1;
    double field2;
    char field3;
} Structure;

void swapFields(Structure* s1, Structure* s2) {
    Structure temp;

    // Swap field1
    temp.field1 = s1->field1;
    s1->field1 = s2->field1;
    s2->field1 = temp.field1;

    // Swap field2
    temp.field2 = s1->field2;
    s1->field2 = s2->field2;
    s2->field2 = temp.field2;

    // Swap field3
    temp.field3 = s1->field3;
    s1->field3 = s2->field3;
    s2->field3 = temp.field3;
}

int main() {
    Structure s1, s2;

    // Initialize values for s1
    s1.field1 = 10;
    s1.field2 = 3.14;
    s1.field3 = 'A';

    // Initialize values for s2
    s2.field1 = 20;
    s2.field2 = 2.71;
    s2.field3 = 'B';

    // Display values before swapping
    printf("Before swapping:\n");
    printf("s1: field1 = %d, field2 = %.2lf, field3 = %c\n", s1.field1, s1.field2, s1.field3);
    printf("s2: field1 = %d, field2 = %.2lf, field3 = %c\n", s2.field1, s2.field2, s2.field3);

    // Swap the fields using pointers
    swapFields(&s1, &s2);

    // Display values after swapping
    printf("\nAfter swapping:\n");
    printf("s1: field1 = %d, field2 = %.2lf, field3 = %c\n", s1.field1, s1.field2, s1.field3);
    printf("s2: field1 = %d, field2 = %.2lf, field3 = %c\n", s2.field1, s2.field2, s2.field3);

    return 0;
}
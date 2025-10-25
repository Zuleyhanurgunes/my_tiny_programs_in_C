#include <stdio.h>

int main() {
    int sayi1, sayi2;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &sayi1);

    printf("Enter second number: ");
    scanf("%d", &sayi2);

    printf("Choose an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    if (operator == '+') {
        printf("Result: %d\n", sayi1 + sayi2);
    } else if (operator == '-') {
        printf("Result: %d\n", sayi1 - sayi2);
    } else if (operator == '*') {
        printf("Result: %d\n", sayi1 * sayi2);
    } else if (operator == '/') {
        if (sayi2 != 0)
            printf("Result: %d\n", sayi1 / sayi2);
        else
            printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("This calculator is not able to calculate this problem.\n");
    }

    return 0;
}








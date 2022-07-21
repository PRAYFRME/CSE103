#include <stdio.h>

int main() {
    int base, exponent, result = 1, i = 1;

    printf("Enter base as an integer: ");
    scanf("%d", &base);

    printf("Enter exponent as an integer: ");
    scanf("%d", &exponent);

    while(i <= exponent) {
        result *= base;
        i++;
    }

    printf("\nResult: %d^%d = %d\n", base, exponent, result);
    return 0;
}

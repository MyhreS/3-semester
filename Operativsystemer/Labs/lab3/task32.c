#include <stdio.h>
int main() {
    float A, B;
    float Difference = 0;

    printf("Enter a float please:");
    scanf("%f", &A);
    printf("Enter a second float that is a bit smaller:");
    scanf("%f", &B);

    Difference = A - B;


    printf("The difference between them is %f\n", Difference);
    return 0;

}
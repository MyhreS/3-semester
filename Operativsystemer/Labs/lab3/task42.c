#include <stdio.h>
#include <math.h>
int main() {
    float A, B;
    float Max;

    printf("Enter a float:");
    scanf("%f", &A);
    printf("Enter another float:");
    scanf("%f", &B);
    

    if(A > B)
        Max = B;
    else
        Max = A;
    printf("The lowest value is %f ", Max);
}
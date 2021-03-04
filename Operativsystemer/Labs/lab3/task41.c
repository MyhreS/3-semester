#include <stdio.h>
#include <math.h>
int main() {
    int A, B;
    int Max;

    printf("Enter one integer:");
    scanf("%d", &A);
    printf("Enter another integer:");
    scanf("%d", &B);

    if(A < B)
        Max = B;
    else
        Max = A;
    printf("Max is %d ", Max);
}
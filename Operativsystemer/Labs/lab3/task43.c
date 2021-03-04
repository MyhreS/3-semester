#include <stdio.h>
#include <math.h>
int main() {
    int A, B, C;

    printf("Enter one integer:");
    scanf("%d", &A);
    printf("Enter another integer:");
    scanf("%d", &B);
    printf("Enter a third integer:");
    scanf("%d", &C);

    if(A==B||A==C||B==C)
        printf("One of the integers are equal\n");
    else
        printf("None of the integers are equal\n");
}
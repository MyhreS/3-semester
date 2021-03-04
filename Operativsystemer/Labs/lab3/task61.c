#include <stdio.h>
#include <math.h>

int Calculate_Sum(int A, int B) {
    return (A + B);
}
int main() {
    int A, B;
    printf("Enter one integer:");
    scanf("%d", &A);
    printf("Enter another integer:");
    scanf("%d", &B);
    printf("Sum is %d\n", Calculate_Sum(A,B));
}
#include <stdio.h>
#include <math.h>

int main() {
    for (int a = 0; a < 10; a++) {
        static int i = 1;
        int b = 0;
        
        while (b < 10) {
        printf("%d ", i);
        i++;
        b++;
    }
    printf("\n");
    }
    
}
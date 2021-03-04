#include <stdio.h>

int main() {
    int c;
    
    for(int i = 0; i < 10; i++) {
        int b = 2;
        b = b*2;
        c = b;
        printf("b is=%d, c is=%d\n", b, c);
    }
}
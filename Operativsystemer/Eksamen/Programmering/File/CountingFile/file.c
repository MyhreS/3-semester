#include <stdio.h>

int main() {
    int sum = 0;
    FILE *file;
    int buffer;
    file = fopen("textfile.txt", "r");

    while(!feof(file)) {
        fscanf(file, "%d", &buffer);
        sum += buffer;
    }
    fclose(file);
    printf("%d", sum);

}
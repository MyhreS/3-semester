#include <stdio.h>

int main(){
    char array[100];
    FILE *file;

    file = fopen("textfile.txt", "r");
    
    while(fgets(array, 100, file) != NULL) {
        printf("%s", array);
    }
    printf("%s", array);
    fclose(file);
    
    
    return 0;
}
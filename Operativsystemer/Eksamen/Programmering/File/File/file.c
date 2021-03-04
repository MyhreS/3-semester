#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("textfile.txt", "w");

    //Writing variables to file
    char string1[100] = "Simon";
    int number = 2;
    fprintf(file, "%s\n%d", string1, number);
    fclose(file);

    //Allocating memory
    int n;
    char A; 

    printf("Number of elements in the array:");
    scanf("%d", &n);

    A = (char)malloc(n*sizeof(char));

    //Reading file
    FILE *f = fopen("textfile.txt", "r");

    while(fgets(&A, n, f) != NULL) {
        printf("%s", &A);
    }

    fclose(file);
    
    
    //String is equal to word
    char s1[20];
    printf("\n\n Input word: ");
    scanf("%s", s1);
    
    if(strcmp(s1, "Simon") == 0) {
        printf("\nThey are equal");
    }

}
#include <stdio.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char ch;

    printf("Contents of input.txt:\n");
    while ((ch = fgetc(input_file)) != EOF) {
        putchar(ch);
    }

    fclose(input_file);

    return 0;
}

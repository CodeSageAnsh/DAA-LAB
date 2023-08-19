#include <stdio.h>

void decimalToBinary(int num, FILE *output_file) {
    if (num == 0) {
        fprintf(output_file, "0");
        return;
    }

    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        fprintf(output_file, "%d", binary[j]);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int num;
    while (fscanf(input_file, "%d", &num) == 1) {
        decimalToBinary(num, output_file);
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

#include <stdio.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int n;
    fscanf(input_file, "%d", &n);
    fprintf(output_file, "Enter the number of elements: %d\n", n);

    int arr[n], prefix_sum = 0;

    fprintf(output_file, "Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
        fprintf(output_file, "%d ", arr[i] += prefix_sum);
        prefix_sum = arr[i];
    }
    fprintf(output_file, "\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}

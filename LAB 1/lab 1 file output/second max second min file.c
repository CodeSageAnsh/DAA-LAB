#include <stdio.h>

int main() {
    int n;

   
    FILE *input_file = fopen("input1.txt", "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

   
    fscanf(input_file, "%d", &n);

    int arr[n];


    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }

    
    fclose(input_file);

    int max1, max2, min1, min2;
    max1 = max2 = arr[0];
    min1 = min2 = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

   
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

        fprintf(output_file, "Second Maximum Element: %d\n", max2);
    fprintf(output_file, "Second Minimum Element: %d\n", min2);

   
    fclose(output_file);

    return 0;
}

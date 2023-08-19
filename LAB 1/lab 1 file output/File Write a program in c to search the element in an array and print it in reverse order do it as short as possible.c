#include <stdio.h>

int main() {
    int n, i, search;

    
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

  
    fscanf(input_file, "%d", &n);

    int arr[n];

   
    for (i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }

   
    fclose(input_file);

    
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

  
    printf("Enter the element to search: ");
    scanf("%d", &search);

    int found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = 1;
            break;
        }
    }

    if (found) {
        fprintf(output_file, "Element found at index %d\n", i);
        fprintf(output_file, "Array elements in reverse order: ");
        for (i = n - 1; i >= 0; i--) {
            fprintf(output_file, "%d ", arr[i]);
        }
    } else {
        fprintf(output_file, "Element not found in the array.\n");
    }

   
    fclose(output_file);

    return 0;
}

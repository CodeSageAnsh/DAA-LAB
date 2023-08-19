#include <stdio.h>

int binarySearch(int arr[], int size, int key, int *comparisons) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        (*comparisons)++; 

        if (arr[mid] == key) {
            result = mid;
            right = mid - 1; 
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    FILE *inputFile, *outputFile;
    int size, key, comparisons = 0;

    inputFile = fopen("input.txt", "r"); 

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fscanf(inputFile, "%d", &key);

    fclose(inputFile);

    int position = binarySearch(arr, size, key, &comparisons);

    outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    if (position != -1) {
        fprintf(outputFile, "%d found at index position %d\n", key, position);
    } else {
        fprintf(outputFile, "%d not found in the array.\n", key);
    }

    fprintf(outputFile, "Number of comparisons: %d\n", comparisons);

    fclose(outputFile);

    return 0;
}

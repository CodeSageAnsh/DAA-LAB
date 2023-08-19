#include <stdio.h>

void insertionSort(int arr[], int size, int *comparisons) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArrayToFile(int arr[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice, size, comparisons = 0;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    const char *inputFile, *outputFile;

    switch (choice) {
        case 1:
            inputFile = "inAsce.txt";
            outputFile = "outInsAsce.txt";
            break;
        case 2:
            inputFile = "inDesc.txt";
            outputFile = "outInsDesc.txt";
            break;
        case 3:
            inputFile = "inRand.txt";
            outputFile = "outInsRand.txt";
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Error opening the input file %s\n", inputFile);
        return 1;
    }

    fscanf(input, "%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++) {
        fscanf(input, "%d", &arr[i]);
    }

    fclose(input);

    insertionSort(arr, size, &comparisons);
    printArrayToFile(arr, size, outputFile);

    printf("Before Sorting: Content of the input file\n");
    printf("After Sorting: Content of the output file\n");
    printf("Number of Comparisons: %d\n", comparisons);
    printf("Scenario: %s-case\n", comparisons == 0 ? "Best" : "Worst");

    return 0;
}

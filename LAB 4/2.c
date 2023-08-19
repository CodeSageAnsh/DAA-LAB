#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparisons = 0;  // Global variable to count comparisons

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void read_input(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < size; i++) fscanf(file, "%d", &arr[i]);
    fclose(file);
}

void write_output(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < size; i++) fprintf(file, "%d ", arr[i]);
    fclose(file);
}

int main() {
    int option;
    while (1) {
        printf("MAIN MENU (QUICK SORT)\n1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 4) {
            printf("Exiting the program.\n");
            break;
        }

        const char *input_filenames[] = {"inAsce1.txt", "inDesc1.txt", "inRand1.txt"};
        const char *output_filenames[] = {"outQuickAsce1.txt", "outQuickDesc1.txt", "outQuickRand1.txt"};

        if (option >= 1 && option <= 3) {
            int size;
            FILE *input_file = fopen(input_filenames[option - 1], "r");
            fscanf(input_file, "%d", &size);
            int arr[size];
            for (int i = 0; i < size; i++) fscanf(input_file, "%d", &arr[i]);
            fclose(input_file);

            printf("Before Sorting: ");
            for (int i = 0; i < size; i++) printf("%d ", arr[i]);
            printf("\n");

            comparisons = 0;
            quick_sort(arr, 0, size - 1);

            printf("After Sorting: ");
            for (int i = 0; i < size; i++) printf("%d ", arr[i]);
            printf("\n");

            printf("Number of Comparisons: %d\n", comparisons);
            if (comparisons <= size / 2) {
                printf("Scenario: Best-case\n");
            } else {
                printf("Scenario: Worst-case\n");
            }

            write_output(output_filenames[option - 1], arr, size);
        } else {
            printf("Invalid option. Please choose a valid option.\n");
        }
    }
    return 0;
}

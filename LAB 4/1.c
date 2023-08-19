#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int merge_sort(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        comparisons += merge_sort(arr, left, mid);
        comparisons += merge_sort(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;
        int left_half[n1], right_half[n2];

        memcpy(left_half, &arr[left], n1 * sizeof(int));
        memcpy(right_half, &arr[mid + 1], n2 * sizeof(int));

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            comparisons++;
            arr[k++] = (left_half[i] <= right_half[j]) ? left_half[i++] : right_half[j++];
        }

        while (i < n1) arr[k++] = left_half[i++];
        while (j < n2) arr[k++] = right_half[j++];
    }
    return comparisons;
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
        printf("MAIN MENU (MERGE SORT)\n1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 4) {
            printf("Exiting the program.\n");
            break;
        }

        const char *input_filename, *output_filename;

        if (option == 1) {
            input_filename = "inAsce.txt";
            output_filename = "outMergeAsce.txt";
        } else if (option == 2) {
            input_filename = "inDesc.txt";
            output_filename = "outMergeDesc.txt";
        } else if (option == 3) {
            input_filename = "inRand.txt";
            output_filename = "outMergeRand.txt";
        } else {
            printf("Invalid option. Please choose a valid option.\n");
            continue;
        }

        FILE *input_file = fopen(input_filename, "r");
        int size;
        fscanf(input_file, "%d", &size);
        int arr[size];
        for (int i = 0; i < size; i++) fscanf(input_file, "%d", &arr[i]);
        fclose(input_file);

        printf("Before Sorting: ");
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");

        clock_t start_time = clock();
        int comparisons = merge_sort(arr, 0, size - 1);
        clock_t end_time = clock();

        printf("After Sorting: ");
        for (int i = 0; i < size; i++) printf("%d ", arr[i]);
        printf("\n");

        printf("Number of Comparisons: %d\n", comparisons);
        printf("Execution Time: %ld nanoseconds\n", (end_time - start_time));

        write_output(output_filename, arr, size);
    }
    return 0;
}

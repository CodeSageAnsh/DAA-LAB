#include <stdio.h>

int main() {
    int arr[10000], i, j, n, count = 0;
    FILE *inputFile;
    inputFile = fopen("input.txt", "r"); 

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    int duplicateArr[10000]; 
    int duplicateCount[10000]; 
    int duplicateIndex = 0; 

    for (i = 0; i < n; i++) {
        int isDuplicate = 0;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate) {
            int found = 0;

            for (j = 0; j < duplicateIndex; j++) {
                if (duplicateArr[j] == arr[i]) {
                    found = 1;
                    duplicateCount[j]++;
                    break;
                }
            }

            if (!found) {
                duplicateArr[duplicateIndex] = arr[i];
                duplicateCount[duplicateIndex] = 2;
                duplicateIndex++;
            }
        }
    }

    FILE *outputFile;
    outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    fprintf(outputFile, "Total duplicate numbers in the array: %d\n", duplicateIndex);

    if (duplicateIndex > 0) {
        fprintf(outputFile, "Duplicate numbers and their occurrences:\n");
        for (i = 0; i < duplicateIndex; i++) {
            fprintf(outputFile, "%d occurs %d time(s)\n", duplicateArr[i], duplicateCount[i]);
        }
    }

    fclose(outputFile);

    return 0;
}

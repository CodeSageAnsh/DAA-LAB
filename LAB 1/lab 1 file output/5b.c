#include <stdio.h>

int getMaxRepeatingElement(int array[], int n) {
    int maxElement = array[0];
    int maxCount = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (array[j] == array[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElement = array[i];
        }
    }

    return maxElement;
}

int main() {
    int n;
    FILE *inputFile;
    inputFile = fopen("in.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &array[i]);
    }

    fclose(inputFile);

    int maxElement = getMaxRepeatingElement(array, n);
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] == maxElement) {
            maxCount++;
        }
    }

    printf("Maximum Repeating Element: %d\n", maxElement);
    printf("Occurrences: %d\n", maxCount);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *inputFile, *outputFile;
    int array[MAX_SIZE];
    int numElements = 0;
    int sum = 0;
    int max, min;
    double average;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    while (fscanf(inputFile, "%d", &array[numElements]) == 1) {
        sum += array[numElements];
        numElements++;
    }


    fclose(inputFile);

    if (numElements == 0) {
        printf("No elements found in the input file.\n");
        return 1;
    }

    
    average = (double)sum / numElements;

   
    max = min = array[0];
    for (int i = 1; i < numElements; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }


    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }


    printf("Array Elements:\n");
    fprintf(outputFile, "Array Elements:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", array[i]);
        fprintf(outputFile, "%d ", array[i]);
    }
    printf("\n");
    fprintf(outputFile, "\n");

   
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Maximum Element: %d\n", max);
    printf("Minimum Element: %d\n", min);

    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Average: %.2f\n", average);
    fprintf(outputFile, "Maximum Element: %d\n", max);
    fprintf(outputFile, "Minimum Element: %d\n", min);

    
    fclose(outputFile);

    return 0;
}

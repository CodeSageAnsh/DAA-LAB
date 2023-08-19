#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2, int N) {
    for (int i = 0; i < p2; i++) {
        EXCHANGE(&p1[N - 1], &p1[N - 2]);
    }
}

int main() {
    int N;
    FILE *inputFile;
    inputFile = fopen("input0.txt", "r"); 

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%d", &A[i]);
    }

    int p2;
    fscanf(inputFile, "%d", &p2);

    fclose(inputFile);

    ROTATE_RIGHT(A, p2, N);

    FILE *outputFile;
    outputFile = fopen("output0.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    fprintf(outputFile, "Before ROTATE: ");
    for (int i = 0; i < N; i++) {
        fprintf(outputFile, "%d ", A[i]);
    }

    fprintf(outputFile, "\nAfter ROTATE: ");
    for (int i = 0; i < N; i++) {
        fprintf(outputFile, "%d ", A[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);

    return 0;
}

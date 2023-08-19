#include <stdio.h>


void decimalToBinary(FILE *inFile, FILE *outFile, int n) {
    if (n <= 0) return; 

    int decimal;
    if (fscanf(inFile, "%d", &decimal) != 1)
        return; 

    
    int binary[32]; 
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        fprintf(outFile, "%d", binary[j]);
    }
    fprintf(outFile, "\n");

    decimalToBinary(inFile, outFile, n - 1);
}

int main() {
    FILE *inputFile, *outputFile;
    int n;

    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

  
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        fclose(inputFile);
        return 1;
    }

    
    printf("Enter the value of 'n': ");
    scanf("%d", &n);


    decimalToBinary(inputFile, outputFile, n);

  
    fclose(inputFile);
    fclose(outputFile);

    printf("Binary values of the first %d decimal numbers have been stored in the output file.\n", n);

    return 0;
}

#include <stdio.h>


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    FILE *inputFile, *outputFile;
    int num1, num2, result;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening the input file.\n");
        return 1;
    }


    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening the output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2)
    {
        result = gcd(num1, num2);
        fprintf(outputFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("GCD values have been calculated and stored in the output file.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
void decimalToBinary(int num, FILE *out) {
    if (num > 1)
        decimalToBinary(num / 2, out);

    fprintf(out, "%d", num % 2);
}

int main() {
    FILE *inputFile, *outputFile;
    int n, count = 0, number;


    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    
    printf("Enter the number of decimal numbers to convert: ");
    scanf("%d", &n);


    while (count < n && fscanf(inputFile, "%d", &number) == 1) {
        decimalToBinary(number, outputFile);
        fprintf(outputFile, "\n"); 
        count++;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Binary values written to output.txt\n");

    return 0;
}

#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;
    int max, min;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];

        if (i == 0) {
            max = arr[i];
            min = arr[i];
        } else {
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
    }

    average = (float)sum / n;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display Array Elements\n");
        printf("2. Calculate Sum\n");
        printf("3. Calculate Average\n");
        printf("4. Find Maximum Element\n");
        printf("5. Find Minimum Element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Sum: %d\n", sum);
                break;
            case 3:
                printf("Average: %.2f\n", average);
                break;
            case 4:
                printf("Max Element: %d\n", max);
                break;
            case 5:
                printf("Min Element: %d\n", min);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

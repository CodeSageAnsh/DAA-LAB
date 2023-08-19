#include <stdio.h>

int main() {
    int arr[10000], i, j, n, count = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

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

    printf("Total duplicate numbers in the array: %d\n", duplicateIndex);

    if (duplicateIndex > 0) {
        printf("Duplicate numbers and their occurrences:\n");
        for (i = 0; i < duplicateIndex; i++) {
            printf("%d occurs %d time(s)\n", duplicateArr[i], duplicateCount[i]);
        }
    }

    return 0;
}

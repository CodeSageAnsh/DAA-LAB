#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], prefix_sum = 0;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        printf("%d ", arr[i] += prefix_sum);
        prefix_sum = arr[i];
    }
    printf("\n");

    return 0;
}

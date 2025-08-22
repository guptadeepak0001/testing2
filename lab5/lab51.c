#include <stdio.h>

int binarySearchLeftmost(int arr[], int n, int target, int *comparisons) {
    int left = 0, right = n - 1, result = -1;
    *comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // overflow-safe mid
        (*comparisons)++;                     // counts iterations, not exact comparisons

        if (arr[mid] == target) {
            result = mid;       // store index
            right = mid - 1;    // search left half for earlier occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;     // go right
        } else {
            right = mid - 1;    // go left
        }
    }
    return result;
}

int main() {
    int n, target, comparisons;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n]; // C99 VLA; if your compiler doesn't support VLAs, use malloc
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &target);

    int pos = binarySearchLeftmost(arr, n, target, &comparisons);

    if (pos != -1)
        printf("Element found at index %d (position %d in 1-based indexing).\n", pos, pos + 1);
    else
        printf("Element not found.\n");

    printf("Number of comparisons (iterations): %d\n", comparisons);
    return 0;
}

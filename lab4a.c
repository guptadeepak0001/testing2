// WAP for insertion sort using the binary search.
#include <stdio.h>

// Iterative binary search to find the index to insert the element
int binarySearch(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (item == arr[mid])
            return mid + 1;

        if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    return low;
}

// Insertion sort using binary search
void insertionSortBinary(int arr[], int n) {
    int i, j, selected, loc;

    for (i = 1; i < n; i++) {
        selected = arr[i];
        // Find location where selected should be inserted
        loc = binarySearch(arr, selected, 0, i - 1);

        // Shift elements to right to make room
        for (j = i - 1; j >= loc; j--)
            arr[j + 1] = arr[j];

        arr[loc] = selected;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {5, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSortBinary(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

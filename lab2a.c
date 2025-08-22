#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


void ROTATE_RIGHT(int *p1, int p2) {
    int i;
    
    for (i = p2 - 1; i > 0; i--) {
        EXCHANGE(p1 + i, p1 + i - 1);
    }
}


int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p2 = 4; 

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    ROTATE_RIGHT(arr, p2);

    printf("\nArray after rotating first %d elements to the right by 1: ", p2);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int maximum(int arr[], int n) {
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (res < arr[i]) {
            res = arr[i];
        }
    }
    return res;
}

void print(int arr[], int n, int i, int max) {
    if (max <= 0) {
        return;
    }
    if (i == n) {
        printf("\n");
        print(arr, n, 0, max - 1);
    } 
    else {
        if (arr[i] >= max) {
            printf("** ");
        } else {
            printf("   ");
        }
        print(arr, n, i + 1, max);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxVal = maximum(arr, n);
    print(arr, n, 0, maxVal);
    return 0;
}


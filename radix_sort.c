#include <stdio.h>
#include <stdlib.h>

// função para pegar o maior número
int getMax(int arr[], int n) {
    int i;
	int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// função para contar cada número
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
	int i;

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// função radix sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
	int exp;

    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// printar
void printall(int arr[], int n) {
    int i;
    
	for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[] = {87, 153, 29, 266, 104, 212, 45, 298, 171, 63, 211, 9, 
	278, 192, 118, 54, 276, 95, 240, 143, 7, 183, 36, 200, 67, 124, 289, 
	41, 176, 82, 223, 13, 268, 55, 197, 118, 90, 145, 211, 284};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printall(arr, n);

    radixSort(arr, n);

    printf("Array ordenado: \n");
    printall(arr, n);

    return 0;
}

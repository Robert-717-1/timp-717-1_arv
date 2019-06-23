#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

void sort_Shell(int* array, int n) {
    int denominator = n;
    int temp;
    bool found;
    do {
        found = false;
        if (denominator != 1) {
            denominator /= 2;
            found = true;
        }
        for (int i = 0; i < n; i++) {
            if (n > i + denominator) {
                for (int j = i + denominator; j <= i + denominator ; j++) {
                    if (array[i] > array[j]) {
                        temp = array[i]; array[i] = array[j]; array[j] = temp;
                        found = true;
                    }
                }
            }
        }
    } while(found);
}

void main() {
    int n;
    scanf("%d", &n);
    int* array = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    sort_Shell(array, n);
    for (int i = 0; i < n; i++) {
        if(i != n - 1) printf("%d ", array[i]);
        else  printf("%d", array[i]);
    }
    printf("\n");
}

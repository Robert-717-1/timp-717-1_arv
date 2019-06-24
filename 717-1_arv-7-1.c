#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int sorting_function(int *arr, int first, int last) {
    int const_first = first;
    int const_last = last;
    int mid = ((last - first) / 2) + first;
    int temp;
    int new_temp = last;
        for (int i = first; i <= mid; i++) {
            if (arr[i] >= arr[mid]) {
                for (int j = new_temp; j >= mid; j--) {
                    if (arr[j] <= arr[mid]) {
                        temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                        new_temp = j--;
                        break;
                    }
                }
            }
        }
        last = mid;
        if ((mid - const_first) > 1) sorting_function(arr, first, last);
        else if ((mid - const_first) == 1) {
                if (arr[const_first] > arr[mid]) {
                    temp = arr[const_first]; arr[const_first] = arr[mid]; arr[mid] = temp;
                }
        }
        first = mid; last = const_last;
        if ((const_last - mid) > 1) sorting_function(arr, first, last);
        else if ((const_last - mid) == 1) {
                if (arr[const_last] < arr[mid]) {
                    temp = arr[const_last]; arr[const_last] = arr[mid]; arr[mid] = temp;
                }
        }
    return 0;
}

void main() {
    int arr_len;
    scanf("%d", &arr_len);
    int* arr = (int*)malloc(arr_len*sizeof(int));
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &arr[i]);
    }
    int first = 0;
    int last = arr_len - 1;
    bool found;
    do {
        sorting_function(arr, first, last);
        found = false;
        for (int i = 0; i < arr_len; i++) {
           for (int j = 1; j < arr_len; j++) {
               if (arr[i] > arr[j]) {
                   found = true;
                   break;
               }
               i++;
           }
        }
    } while(found);
    for (int i = 0; i < arr_len; i++) {
        if (i != arr_len - 1) printf("%d ", arr[i]);
        else printf("%d", arr[i]);
    }
    printf("\n");
}

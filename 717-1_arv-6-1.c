#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<stdbool.h>

int sorting_function(int *arr, int arr_len) {
    int count = 0;
    if (arr_len < 2) return 0;
    int new_arr_len = arr_len - 1;
    int temp;
    bool found;
    do {
        found = false;
        if (count != 0) new_arr_len = (new_arr_len / 4) * 3;
        if (new_arr_len == 0) new_arr_len = 1;
        for (int i = 0; i < arr_len; i++) {
            if (arr_len > i + new_arr_len) {
                for (int j = i + new_arr_len; j <= i + new_arr_len; j++) {
                    if (arr[i] > arr[j] && count == 0) {
                        temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                        found = true;
                        break;
                    }
                    else if (arr[i] > arr[j] && count != 0) {
                            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                            found = true;
                    }
                }
            }
            else {
                for (int j = 0 + new_arr_len - 1; j <= 0 + new_arr_len - 1; j++) {
                    if (arr[i] < arr[j] && count == 0) {
                        temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                        found = true;
                        break;
                    }
                    else if (arr[i] < arr[j] && count != 0) {
                            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
                            found = true;
                    }
                }
            }
        }
        count++;
    } while(found);
    return 0;
}

void main () {
    setlocale(LC_ALL, "Rus");
    int arr_len;
    scanf("%d", &arr_len);
    int* arr = (int*)malloc(arr_len* sizeof(int));
    for (int i = 0; i < arr_len; i++) {
        scanf("%d", &arr[i]);
    }
    sorting_function(arr, arr_len);
    for (int i = 0; i < arr_len; i++) {
            if (i == arr_len - 1) {
                printf("%d", arr[i]);
            }
            else printf("%d ", arr[i]);
    }
    printf("\n");
}


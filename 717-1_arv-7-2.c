#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

int pyramidal_sorting(int* arr, int arr_len) {
    int temp, const_temp_number, temp_number, temp_indeks;
    bool found = false;
    for (int i = arr_len - 1; i >= 0; i--) {
        temp_indeks = i;
        const_temp_number = 2 * i;
        temp_number = const_temp_number;
        do {
            found = false;
            if (temp_number + 1 < arr_len) {
                if (temp_number + 2 < arr_len) {
                    if (arr[temp_number + 1] <= arr[temp_number + 2]) {
                        if (arr[temp_indeks] > arr[(2 * temp_indeks) + 1]) {
                            temp = arr[temp_indeks]; arr[temp_indeks] = arr[temp_number + 1]; arr[temp_number + 1] = temp;
                            temp_indeks = temp_number + 1;
							temp_number = 2 * (temp_number + 1);
							found = true;
                        }
                    }
                    else {
                        if (arr[temp_indeks] > arr[(2 * temp_indeks) + 2]) {
                            temp = arr[temp_indeks]; arr[temp_indeks] = arr[temp_number + 2]; arr[temp_number + 2] = temp;
                            temp_indeks = temp_number + 2;
                            temp_number = 2 * (temp_number + 2);
                            found = true;
                        }
                    }
                }
                else {
                    if (arr[temp_indeks] > arr[(2 * temp_indeks) + 1]) {
                        temp = arr[temp_indeks]; arr[temp_indeks] = arr[temp_number + 1]; arr[temp_number + 1] = temp;
                        temp_indeks = temp_number + 1;
                        temp_number = 2 * (temp_number + 1);
                        found = true;
                    }
                }
            }
            if (temp_number + 1 >= arr_len) found = false;
        } while(temp_number + 1 < arr_len && found != false);
    }

    int* new_arr = (int*)malloc(arr_len*sizeof(int));
    for (int i = 0; i < arr_len; i++) {
        for (int j = arr_len - 1; j >= 0; j--) {
            new_arr[i] = arr[j];
            i++;
        }
    }

    for (int i = arr_len - 1; i >= 0; i--) {
        temp_indeks = i;
        const_temp_number = 2 * i;
        temp_number = const_temp_number;
        do {
            found = false;
            if (temp_number + 1 < arr_len) {
                if (temp_number + 2 < arr_len) {
                    if (new_arr[temp_number + 1] >= new_arr[temp_number + 2]) {
                        if (new_arr[temp_indeks] < new_arr[(2 * temp_indeks) + 1]) {
                            temp = new_arr[temp_indeks]; new_arr[temp_indeks] = new_arr[temp_number + 1]; new_arr[temp_number + 1] = temp;
                            temp_indeks = temp_number + 1;
							temp_number = 2 * (temp_number + 1);
							found = true;
                        }
                    }
                    else {
                        if (new_arr[temp_indeks] < new_arr[(2 * temp_indeks) + 2]) {
                            temp = new_arr[temp_indeks]; new_arr[temp_indeks] = new_arr[temp_number + 2]; new_arr[temp_number + 2] = temp;
                            temp_indeks = temp_number + 2;
                            temp_number = 2 * (temp_number + 2);
                            found = true;
                        }
                    }
                }
                else {
                    if (new_arr[temp_indeks] < new_arr[(2 * temp_indeks) + 1]) {
                        temp = new_arr[temp_indeks]; new_arr[temp_indeks] = new_arr[temp_number + 1]; new_arr[temp_number + 1] = temp;
                        temp_indeks = temp_number + 1;
                        temp_number = 2 * (temp_number + 1);
                        found = true;
                    }
                }
            }
            if (temp_number + 1 >= arr_len) found = false;
        } while(temp_number + 1 < arr_len && found != false);
    }

    for (int i = 0; i < arr_len; i++) {
        for (int j = arr_len - 1; j >= 0; j--) {
            arr[i] = new_arr[j];
            i++;
        }
    }
    free(new_arr);

    for (int i = 1; i < arr_len; i++) {
        temp_indeks = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[temp_indeks]) {
                temp = arr[j]; arr[j] = arr[temp_indeks]; arr[temp_indeks] = temp;
                temp_indeks = j;
            }
            else if (arr[j] <= arr[temp_indeks]) break;
            if (j == 0) break;
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
    pyramidal_sorting(arr, arr_len);
    for (int i = 0; i < arr_len; i++) {
        if (i < arr_len - 1) printf("%d ", arr[i]);
        else printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
}

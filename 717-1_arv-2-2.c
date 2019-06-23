#include<stdio.h>
#include<malloc.h>
#include<math.h>


void main () {
    unsigned int n;
    int result = 0;
    scanf("%u", &n);
    int* x = (int*)malloc(n*sizeof(int));
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0 ; i < n; i++) {
        result += (((i + 1) + 1) % 2) * pow(x[i], 3);
    }
    printf("%d\n", result);
}

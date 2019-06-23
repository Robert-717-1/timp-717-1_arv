#include<stdio.h>
#include<malloc.h>


void main() {
    unsigned int n;
    double arithmetical_mean = 0;
    scanf("%u", &n);
    int *x = (int*)malloc(n* (sizeof(int)));
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
            arithmetical_mean += x[i];
    }
    arithmetical_mean /= n;
    printf("%.1lf\n", arithmetical_mean);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, k;
    float P;
    scanf("%d %d", &N, &k);
    P = (N - k) * 100/N;
    printf("%.2f%% of %d sportsmen finished\n", P, N);
    return 0;
}

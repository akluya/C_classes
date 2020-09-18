#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i;
    double m = 0, a[1001], d = 0, r;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%lg", &a[i]);
        m = m + a[i];
    }
    r = m/n;
    for(i = 0; i < n; i++)
    {
        d += (a[i] - r)*(a[i] - r);
    }
    printf("%lg %lg\n", r, sqrt(d/n));

    return 0;
}

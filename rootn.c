#include <stdio.h>
#include <stdlib.h>

double pow(double x, int n)
{
    int k;
    double t;
    t = x;
    if ( n == 0)
        return 1;
    k = 1;
    while(k < n)
    {
        t *= x;
        k++;
    }
    return t;
}

int main()
{
    int n;
    double a, x, x_, d;
    d = 1;
    scanf("%d %lg", &n, &a);
    x = 1;
    if (a == 0)
    {
        printf("0\n");
        return 0;
    }
    while(d > 0.000001 || d < -0.000001)
    {
        x_ = ((n - 1)*x + a / pow(x, n - 1)) / n;
        d = x_ - x;
        x = x_;
    }
    printf("%lg\n", x);
    return 0;
}

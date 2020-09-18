#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, n = 1000, i;
    double sinx, f, s;
    scanf("%d", &x);
    s = sinx = f = (x % 360) * M_PI/180;
    for (i = 2; i < (2*n + 1); i += 2)
    {
        s *= -(f * f/(i*(i + 1)));
        sinx += s;
    }
    printf("%lg\n", sinx);
    return 0;
}

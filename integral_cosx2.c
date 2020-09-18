#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b;
    double dx, x, s, n, m;
    s = 0;
    dx = 1e-5;
    scanf("%d %d", &a, &b);
    //n = a * M_PI/180;
    //m = b * M_PI/180;
    //printf("%lf %lf %lf %lf\n", n, m, cos(n), cos(m));
    if (b > a)
    {
        n = a * M_PI/180;
        m = b * M_PI/180;
    }
    else
    {
        n = b * M_PI/180;
        m = a * M_PI/180;
    }
    for( x = n; x <= m; x += dx )
        s += (cos(x*x) + cos((x+dx)*(x+dx)))* dx /2;

    printf("%lg\n", a < b ? s : -s);//lg - спецификатор, убирающий лишние нули с конца
    return 0;
}

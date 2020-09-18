#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define cor0(x) ((x) > -1e-10 && (x) < 1e-10 ? 0 : (x))

int main()
{
    double a, b, c, x1, x2, y, D;
    scanf("%lf %lf %lf", &a, &b, &c);
    D = b*b - 4*a*c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                printf("R\n");
            else
                printf("NO\n");
        }
        else
        {
            x1 = -c/b;
            printf("%lf\n", cor0(x1));
        }
    }
    else
    {
        if (D >= 0)
        {
            y = sqrt(D);
            x1 = (-b + y)/(2*a);
            x2 = (-b - y)/(2*a);
            if (D == 0)
                printf("%lf\n", cor0(x2));
            else if (x1 < x2)
                printf("%lf %lf\n", cor0(x1), cor0(x2));
            else
                printf("%lf %lf\n", cor0(x2), cor0(x1));
        }
        else
            printf("NO\n");
    }
    return 0;
}




    /*if (a == 0 && b == 0 && c == 0)// a*x^2=0;
        printf("R\n");
    else if (a == 0 && b != 0)// bx+c=0 1;
    {
        x1 = -c/b;
        printf("%lf\n", x1 == 0 ? fabs(x1) : x1);
    }
    else if (a == 0 && b == 0)
        printf("NO\n");
    else if (a != 0)
    {
        if (b*b >= 4*a*c)
        {
            y = sqrt(b*b - 4*a*c);
            x1 = (-b + y)/(2*a);
            x2 = (-b - y)/(2*a);
            if (y == 0)
                printf("%lf\n", x2 == 0 ? fabs(x2) : x2);
            else if (x1 < x2)
                printf("%lf %lf\n", x1 == 0 ? fabs(x1) : x1, x2 == 0 ? fabs(x2) : x2);
            else
                printf("%lf %lf\n", x2 == 0 ? fabs(x2) : x2, x1 == 0 ? fabs(x1) : x1);
        }
        else
            printf("NO\n");
    }
    return 0;
}*/

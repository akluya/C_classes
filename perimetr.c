#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double length(double a, double b, double c, double d)
{
    return sqrt((a - b)*(a - b) + (c - d)*(c - d));
}

double perimeter(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double ab, bc, ac;
    ab = length(x1, x2, y1, y2);
    bc = length(x2, x3, y2, y3);
    ac = length(x1, x3, y1, y3);
    return ab + bc + ac;
}

int main()
{
    double x1, y1, x2, y2, x3, y3, per;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    per = perimeter(x1, y1, x2, y2, x3, y3);
    printf("%lf\n", per);
    return 0 ;
}

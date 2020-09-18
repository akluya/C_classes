#include <stdio.h>
#include <stdlib.h>

void order(char *a, short *b, int *c, long *d, long long *e, float *f, double *g, long double *h, char *s);

int main()
{
    char a;
    short b;
    int c;
    long d;
    long long e;
    float f;
    double g;
    long double h;
    char s[21];
    scanf("%hhd %hd %d %ld %lld %f %lg %Lg %s", &a, &b, &c, &d, &e, &f, &g, &h, s);
    order(&a, &b, &c, &d, &e, &f, &g, &h, s);
    printf("%hhd %hd %d %ld %lld %0.f %.0lf %.0Lf %s\n", a, b, c, d, e, f, g, h, s);
    return 0;
}

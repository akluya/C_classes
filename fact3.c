#include <stdio.h>
#include <stdlib.h>


unsigned long long fact3(unsigned char n, unsigned char k)
{
    int i;
    long long int f = 1;
    for(i = 1; i <= k; i++)
        f *= (n + i - 1);
    return f;
}




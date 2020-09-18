#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int strins(char *t, unsigned int size, const char *s, unsigned int idx)
{
    unsigned int i, j, n;
    if(t == NULL || s == NULL)
        return -1;
    for(i = 0; s[i]; i++);
    for(j = 0; t[j]; j++);
    if(i + j >= size)
        return -2;
    if(idx > j)
        return -3;
    for(n = i + j; n + 1 > idx + i; n--)
    {
        t[n] = t[n - i];
    }
    for(j = 0; j < i; j++)
        t[idx + j] = s[j];
    return 0;
}

int main()
{
    char s[10] = "test";
    int i;
    //printf("%s\n", s);
    i = strins(s, 10, "", 0);
    printf("%d\n", i);
    printf("%s\n", s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1001];
    int k = 0, n = 0, i;
    scanf("%s", s);
    for (i = 0; s[i] != '\0'; i++)
        if(i % 2 == 0)//нечётные места
            k += s[i] - '0';
        else//чётные места
            n += s[i] - '0';
    if((k - n) % 11 == 0)
        puts("YES");
    else
        puts("NO");


    return 0;
}

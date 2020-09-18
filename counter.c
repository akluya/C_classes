#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    printf("%d\n", (a + b)%n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    printf("x^2%+dx%+d\n", (-x1 - x2), (x1 * x2));
    return 0;
}

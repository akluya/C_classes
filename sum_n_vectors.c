#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x[100000], y[100000], z[100000], sx = 0, sy = 0, sz = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        sx += x[i];
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        sy += y[i];
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &z[i]);
        sz += z[i];
    }
    printf("%d\n", sx);
    printf("%d\n", sy);
    printf("%d\n", sz);
    return 0;
}

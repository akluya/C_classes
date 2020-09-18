#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if(x2 < x3 || y2 < y3 || x4 < x1 || y4 < y1)
    {
        printf("NO\n");
    }
    /*if(x4 < x1 || y4 < y1)
    {
        printf("NO");
    }*/
    /*else
    {
          if(x3 <= x2)
            {
                if(y3 <= y2)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
    }*/
    else
        printf("YES\n");

    return 0;
}

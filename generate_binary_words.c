#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, k, i, a[21];
	scanf_s("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		if (i <= (n - k))
		{
			a[i] = 0;
			printf("%d\n", a[i]);
		}
		else
		{
			a[i] = 1;
			printf("%d\n", a[i]);
		}
	}
	
	
	return 0;
}
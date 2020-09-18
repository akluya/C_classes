#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define cor0(x) ((x) > -1e-6 && (x) < 1e-6 ? 0 : (x))

int main()
{
	int i = 0;
	double a, b, fr = 1, fb, fa, r = 1;
	scanf("%lg %lg", &a, &b);
	fa = tan(a) - a;
	fb = tan(b) - b;
	if ( ((fb > 0) && (fa > 0)) || ((fb < 0) && (fa < 0)) )
	{
		printf("-1\n");
		return 0;
	}
	if( fb > fa ) //возрастающая и проходит через ноль
	{
		while ((b - a) >= 1e-10)
		{
			r = (b + a)/2;
			fr = tan(r) - r;
			if ( fr < 0 )
			{
				fa = fr;
				a = r;
			}
			else
			{
				fb = fr;
				b = r;
			}
			i++;
		}
		printf("%.10lf\n", cor0(r));
		printf("%d\n", i);
	}

	else
	{
		while ((b - a) >= 1e-10)
		{
			fr = (fb + fa)/2;
			r = (b + a)/2;
			if (fa > 0 && fr < 0 )
			{
				fb = fr;
				b = r;
			}
			else
			{
				fa = fr;
				a = r;
			}
			i++;
		}
		printf("%.10lg\n", cor0(r));
		printf("%d\n", i);
	}
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int i, k;
	double  r = 0.1, mu = 1e7, L = 5.4e6, lambda = 390, ro = 8.9e3, c = 360, cs = 3710, eps = 1e-20, q0 = 1e6, U, R = 8.314, hi, T, x;
	double Tf[30], vf[30];
	U = 0.75 * L / R;
	hi = lambda / ro / c;
	Tf[0] = 0;
	vf[0] = q0 * (1 - r) / (ro * L);
	//printf("%g %g\n", Tf[0], vf[0]);

	FILE *output;
	
	if ((output = fopen("output.txt", "w")) != NULL) //весь цикл - расчёт vf и Tf для различных q0
	{
		fprintf(output, "q0\tTf\tvf\n");
		for (k = 1; k <= 1000; k++)
		{
			q0 = k * 1e6;
			for ( i = 1; i <= 30; i++)
			{
				Tf[i] = U / (log(cs / vf[i - 1]));
				vf[i] = q0 * (1 - r) / (ro * (c * Tf[i] + L));
				//printf("%f %f\n", Tf[i], vf[i]);
			}

			//printf("%f %f\n", Tf[15], vf[15]);

			fprintf(output, "%f\t%f\t%f\n", q0, Tf[30], vf[30]);
		}
			
		fclose(output);
	}

	FILE *output_1;

	if ((output_1 = fopen("output_1.txt", "w")) != NULL) //весь цикл - расчёт vf и Tf для различных q0
	{		
			q0 =  1e7;
			fprintf(output_1, "q0 %d\n", q0);
			fprintf(output_1, "x\tT\n");
			for (i = 1; i <= 30; i++)
			{
				Tf[i] = U / (log(cs / vf[i - 1]));
				vf[i] = q0 * (1 - r) / (ro * (c * Tf[i] + L));
			}

			x = 0;
			while (x <= 5)
			{
				T = (Tf[30] + q0 * (1 - r) / (ro * c * (mu * hi - vf[30])))*exp(-1 * vf[30] * x / hi) - q0 * (1 - r) / ro / c / (mu*hi - vf[30]) * exp(-1 * mu*x);
				fprintf(output_1, "%f\t%f\n", x, T);
				x = x + 0.001;
			}

		fclose(output_1);
	}
	

	/*for (int i = 1; i < 15; i++)
	{
		Tf[i] = U / (log(cs / vf[i - 1]));
		vf[i] = q0 * (1 - r) / (ro * (c * Tf[i] + L));
		printf("%f %f\n", Tf[i], vf[i]);
	}

	i = 2;
	while (((Tf[i] - Tf[i - 1]) / Tf[i - 1]) < eps)
	{
		//printf("%f %f\n", Tf[i], vf[i]);
		i++;
	}
	//printf("%f %f\n", Tf[i], vf[i]);*/
	scanf_s("%d", &k);

	return 0;
}
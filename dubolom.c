#include <stdio.h>
#include <stdlib.h>

struct soldier
{
	double n;
	double height;
};

typedef struct soldier Soldier;

int doubletobool(double a)
{
	if(a > 0)
		return 1;
	if(a < 0)
		return -1;
	return 0;
}

int sort1(const void* p1, const void* p2)
{
	return doubletobool(((Soldier*)p1)->n - ((Soldier*)p2)->n);
}

int sort2(const void* p1, const void* p2)
{
	double res = ((Soldier*)p2)->height - ((Soldier*)p1)->height;
	if(res == 0)
		res = ((Soldier*)p1)->n - ((Soldier*)p2)->n;
	return doubletobool(res);
}

int main(void)
{
	int N, i;
	Soldier* mass;
	scanf("%d", &N);
	mass = (Soldier*)malloc(sizeof(Soldier) * N);
	for(i = 0; i < N; i++)
		scanf("%lf", &mass[i].n);
	qsort(mass, N, sizeof(Soldier), sort1);
	mass[0].height = mass[0].n;
	for(i = 1; i < N; i++)
		mass[i].height = mass[i].n - mass[i - 1].n;
	qsort(mass, N, sizeof(Soldier), sort2);
	for(i = 0; i < N; i++)
		printf("%lg ", mass[i].n);
	printf("\n");
	free(mass);
	return 0;
}
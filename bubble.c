#include <stdio.h>

#define N_MAX 100

void sort(int A[], unsigned n) {
	unsigned i, j;
	for (i = n - 1; i >= 1; i--)
		for (j = 0; j < i; j++)
			//exchange every two unsorted neighbors
			if (A[j] > A[j+1]) {
				int tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
}

int main(void) {
	int A[N_MAX];
	unsigned n, i;
	printf("Enter the dimension: ");
	scanf("%u", &n);
	if (n > N_MAX) {
		printf("Error! Too many!\nMax = %u\n", N_MAX);
		return -1;
	}
	printf("Enter %u elements: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, n);
	printf("Your sorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

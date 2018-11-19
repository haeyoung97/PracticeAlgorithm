#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int *A = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N - i; j++) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}
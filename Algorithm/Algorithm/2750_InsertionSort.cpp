#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int *A = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int i = 1, j = 0, tmp = 0;

	while (i != N) {
		tmp = A[i];
		j = i - 1;
		while (1) {
			if (tmp < A[j]) {
				A[j + 1] = A[j];
				j--;
			}
			else {
				A[j + 1] = tmp;
				i++;
				break;
			}
			if (j < 0) {
				A[j + 1] = tmp;
				i++;
				break;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}
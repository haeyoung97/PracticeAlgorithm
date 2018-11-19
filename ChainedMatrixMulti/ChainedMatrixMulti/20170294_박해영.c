#include <stdio.h>
#include <stdlib.h>

int minmult(int n, const int * d, int **P);
void order(int i, int j);

int **P; // order 함수에서 array P를 처리하기 위해 전역변수로 처리

int main() {
	int n;
	printf("Input tho number of matrices :  ");
	scanf("%d", &n);
	int *d = (int*)malloc(sizeof(int*)*(n + 1));
	P = (int**)malloc(sizeof(int**)*(n + 1));
	for (int i = 0; i < n + 1; i++) {
		P[i] = (int *)malloc(sizeof(int)*(n + 1));
		for (int j = 0; j < n + 1; j++) {
			P[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int n, m;
		printf("%d번째 행렬의 size (m X n) : ", i + 1);
		scanf("%d%d", &m, &n);
		if (i == 0) {
			d[i] = m;
		}
		d[i + 1] = n;
	}

	int result = minmult(n, d, P);
	printf("\nMinimum Multiplication of A1-A%d : %d\n", n, result);
	printf("Order of Minimun Multiplocation : ");
	order(1, n);
	printf("\n\n");
	return 0;
}

int minmult(int n, const int * d, int **P) {
	int i, j, k, diagonal;
	int **M = (int**)malloc(sizeof(int**)*(n + 1));
	for (int i = 0; i < n + 1; i++) {
		M[i] = (int *)malloc(sizeof(int)*(n + 1));
		for (int j = 0; j < n + 1; j++) {
			M[i][j] = 0;
		}
	}
	printf("\n\n");
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			for (k = i; k <= j - 1; k++) {
				if (M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j] < M[i][j] || M[i][j] == 0) {
					M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
					P[i][j] = k;
				}

			}
		}
	}
	printf("\ndiagonal = %d 일 때, M 행렬의 결과\n", diagonal);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%3d ", M[i][j]);
		}
		printf("\n");
	}
	printf("\ndiagonal = %d 일 때, P 행렬의 결과\n", diagonal);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%3d ", P[i][j]);
		}
		printf("\n");
	}
	return M[1][n];
}

void order(int i, int j) {
	int k;
	if (i == j) printf("A%d", i);
	else {
		k = P[i][j];
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}
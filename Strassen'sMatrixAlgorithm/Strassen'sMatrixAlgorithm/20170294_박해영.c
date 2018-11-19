#include <stdio.h>
#include <stdlib.h>

void Strassen(int n, int **A, int **B, int **C);

int main() {
	int size;
	printf("Input : the product of 2 n x n matrices A and B\n");
	printf("Matrix size : ");
	scanf("%d", &size);
	// matrix A and B 2차원 배열로 생성
	int **A = (int**)malloc(sizeof(int *)*size), **B = (int**)malloc(sizeof(int *)*size), **C = (int**)malloc(sizeof(int *)*size);
	for (int i = 0; i < size; i++) {
		A[i] = (int *)malloc(sizeof(int)*size);
		B[i] = (int *)malloc(sizeof(int)*size);
		C[i] = (int *)malloc(sizeof(int)*size);
	}

	printf("Input : Matrix A value\n");
	for (int i = 0; i < size; i++) {
		printf("%d row of Matrix A : ", i + 1);
		for (int j = 0; j < size; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("Input : Matrix B value\n");
	for (int i = 0; i < size; i++) {
		printf("%d row of Matrix B : ", i + 1);
		for (int j = 0; j < size; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	Strassen(size, A, B, C);

	printf("\nOutPut : Matrix C\n\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%3d ", C[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < size; i++) {
		free(A[i]); free(B[i]);	free(C[i]);
	}
	free(A); free(B); free(C);


	return 0;
}

void Strassen(int n, int **A, int **B, int **C) {
	if (n <= 2) {
		C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
		C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
		C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
		C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	}
	else {
		int **A11 = (int**)malloc(sizeof(int*)*n / 2), **A12 = (int**)malloc(sizeof(int*)*n / 2);
		int **A21 = (int**)malloc(sizeof(int*)*n / 2), **A22 = (int**)malloc(sizeof(int*)*n / 2);
		int **B11 = (int**)malloc(sizeof(int*)*n / 2), **B12 = (int**)malloc(sizeof(int*)*n / 2);
		int **B21 = (int**)malloc(sizeof(int*)*n / 2), **B22 = (int**)malloc(sizeof(int*)*n / 2);
		int **M1 = (int**)malloc(sizeof(int*)*n / 2), **M2 = (int**)malloc(sizeof(int*)*n / 2), **M3 = (int**)malloc(sizeof(int*)*n / 2);
		int **M4 = (int**)malloc(sizeof(int*)*n / 2), **M5 = (int**)malloc(sizeof(int*)*n / 2), **M6 = (int**)malloc(sizeof(int*)*n / 2);
		int **M7 = (int**)malloc(sizeof(int*)*n / 2), **tmp1 = (int**)malloc(sizeof(int*)*n / 2), **tmp2 = (int**)malloc(sizeof(int*)*n / 2);
		for (int i = 0; i < n / 2; i++) {
			A11[i] = (int *)malloc(sizeof(int)*n / 2);
			A12[i] = (int *)malloc(sizeof(int)*n / 2);
			A21[i] = (int *)malloc(sizeof(int)*n / 2);
			A22[i] = (int *)malloc(sizeof(int)*n / 2);
			B11[i] = (int *)malloc(sizeof(int)*n / 2);
			B12[i] = (int *)malloc(sizeof(int)*n / 2);
			B21[i] = (int *)malloc(sizeof(int)*n / 2);
			B22[i] = (int *)malloc(sizeof(int)*n / 2);
			M1[i] = (int *)malloc(sizeof(int)*n / 2);
			M2[i] = (int *)malloc(sizeof(int)*n / 2);
			M3[i] = (int *)malloc(sizeof(int)*n / 2);
			M4[i] = (int *)malloc(sizeof(int)*n / 2);
			M5[i] = (int *)malloc(sizeof(int)*n / 2);
			M6[i] = (int *)malloc(sizeof(int)*n / 2);
			M7[i] = (int *)malloc(sizeof(int)*n / 2);
			tmp1[i] = (int *)malloc(sizeof(int)*n / 2);
			tmp2[i] = (int *)malloc(sizeof(int)*n / 2);
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][n / 2 + j];
				A21[i][j] = A[n / 2 + i][j];
				A22[i][j] = A[n / 2 + i][n / 2 + j];
				B11[i][j] = B[i][j];
				B12[i][j] = B[i][n / 2 + j];
				B21[i][j] = B[n / 2 + i][j];
				B22[i][j] = B[n / 2 + i][n / 2 + j];

			}
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1[i][j] = A11[i][j] + A22[i][j];
				tmp2[i][j] = B11[i][j] + B22[i][j];
			}
		}
		Strassen(n / 2, tmp1, tmp2, M1);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1[i][j] = A21[i][j] + A22[i][j];
			}
		}
		Strassen(n / 2, tmp1, B11, M2);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp2[i][j] = B12[i][j] - B22[i][j];
			}
		}
		Strassen(n / 2, A11, tmp2, M3);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp2[i][j] = B21[i][j] - B11[i][j];
			}
		}
		Strassen(n / 2, A22, tmp2, M4);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1[i][j] = A11[i][j] + A12[i][j];
			}
		}
		Strassen(n / 2, tmp1, B22, M5);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1[i][j] = A21[i][j] - A11[i][j];
				tmp2[i][j] = B11[i][j] + B12[i][j];
			}
		}
		Strassen(n / 2, tmp1, tmp2, M6);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				tmp1[i][j] = A12[i][j] - A22[i][j];
				tmp2[i][j] = B21[i][j] + B22[i][j];
			}
		}
		Strassen(n / 2, tmp1, tmp2, M7);

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
				C[i][n / 2 + j] = M3[i][j] + M5[i][j];
				C[n / 2 + i][j] = M2[i][j] + M4[i][j];
				C[n / 2 + i][n / 2 + j] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
			}
		}

		for (int i = 0; i < n / 2; i++) {
			free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
			free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
			free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
			free(M5[i]); free(M6[i]); free(M7[i]);
			free(tmp1[i]); free(tmp2[i]);
		}
		free(A11); free(A12); free(A21); free(A22);
		free(B11); free(B12); free(B21); free(B22);
		free(M1); free(M2); free(M3); free(M4);
		free(M5); free(M6); free(M7);
		free(tmp1); free(tmp2);

	}
	return;
}

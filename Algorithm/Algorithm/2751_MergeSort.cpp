#include <stdio.h>
#include <stdlib.h>

void mergesort(int N, int *A);
void merge(int h, int m, int *S, int *G, int *A);

int main() {
	int N;
	scanf("%d", &N);
	int *A = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	mergesort(N, A);	

	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}

	return 0;
}
void mergesort(int N, int *A) { 
	if (N > 1) {
		int h = N / 2, m = N - h;
		int *S = (int*)malloc(sizeof(int)*h), *G = (int*)malloc(sizeof(int)*m);
		for (int i = 0; i < h; i++) {
			S[i] = A[i];
		}
		for (int i = 0; i < m; i++) {
			G[i] = A[i+h];
		}
		mergesort(h, S);
		mergesort(m, G);
		merge(h, m, S, G, A);
	}
}

void merge(int h, int m, int *S, int *G, int *A) {
	int i = 0, j = 0, k = 0;
	while (i < h && j < m) {
		if (S[i] < G[j]) {
			A[k] = S[i];
			i++;
		}
		else {
			A[k] = G[j];
			j++;
		}
		k++;
	}
	if (i == h) {
		for (; j < m;j++) {
			A[k] = G[j];
			k++;
		}
	}
	else {
		for (; i < h;i++) {
			A[k] = S[i];
			k++;
		}
	}
}
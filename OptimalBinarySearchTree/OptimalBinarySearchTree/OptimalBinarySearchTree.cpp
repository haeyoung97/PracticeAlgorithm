#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct nodetype { 
	char key[20];
	nodetype* left;
	nodetype* right;
};
typedef nodetype* node_pointer;

float *p;
void optsearchtree(int n, float const* p, float& minavg, int** R);
float Prob(int i, int j); // Probability의 i부터 j까지의 합

int main() {
	int n; float minavg;

	printf("Input of Tree size : ");
	scanf("%d", &n);
	p = (float*)malloc(sizeof(float)*n);
	int **R = (int**)malloc(sizeof(int*)*(n + 2));
	for (int i = 0; i < n + 2; i++) {
		R[i] = (int *)malloc(sizeof(int)*(n + 1));
	}
	node_pointer np = (node_pointer)malloc(sizeof(nodetype)*n);
	
	for (int i = 0; i < n; i++) {
		printf("%d번째 key of tree : ", i + 1);
		scanf("%s", &(np[i].key));
		printf("%d번째 Probability of tree : ", i + 1);
		scanf("%f", &p[i]);
	}
	optsearchtree(n, p, minavg, R);
	printf("\nTotal Search Time of Optimal binary tree : %f\n", minavg);
	return 0;
}

void optsearchtree(int n, float const* p, float& minavg, int** R) { 
	int i, j, k, diagonal; 
	float **A = (float**)malloc(sizeof(float*)*(n+2));
	for (int i = 0; i < n + 2; i++) {
		A[i] = (float *)malloc(sizeof(float)*(n+1));
	}
	for (int i = 0; i < n + 2; i++) { //모든 배열 0으로 초기화
		for (int j = 0; j < n + 1; j++) {
			A[i][j] = 0;
			R[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++) { 
		A[i][i] = p[i-1]; R[i][i] = i;
	} 
	
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal; 
			float Pro = Prob(i, j);
			for (k = i; k <= j; k++) {
				if (A[i][j] == 0 || (A[i][k - 1] + A[k + 1][j]) < A[i][j]) {
					A[i][j] = A[i][k - 1] + A[k + 1][j];
					R[i][j] = k;
				}
			}
			A[i][j] += Pro;
		}
		minavg = A[1][n];
	} 
	printf("\n@@@    A array     @@@\n");
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%3f ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n@@@     R array     @@@\n");
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 1; j++) {
			printf("%3d ", R[i][j]);
		}
		printf("\n");
	}
}

float Prob(int i, int j) {
	float sum = 0;
	for (int k = i; k <= j; k++) {
		sum += p[k-1];
	}
	return sum;
}

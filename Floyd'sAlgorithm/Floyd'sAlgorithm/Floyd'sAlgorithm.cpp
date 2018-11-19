#include <stdio.h>
#include <stdlib.h>

#define INFI 100000000;
void floyd2(int v, int *const *const W, int **D, int **P);
void path(int sv, int ev, int **P);

int main() {
	int v, sv,ev,w;
	printf("Nunber of vertices on the graph : ");
	scanf("%d", &v);
	int **W = (int**)malloc(sizeof(int *)*(v + 1)), **D = (int**)malloc(sizeof(int *)*(v + 1)), **P = (int**)malloc(sizeof(int *)*(v + 1));
	for (int i = 0; i < v+1; i++) {
		W[i] = (int *)malloc(sizeof(int)*(v + 1));
		D[i] = (int *)malloc(sizeof(int)*(v + 1));
		P[i] = (int *)malloc(sizeof(int)*(v + 1));
	}
	for (int i = 0; i < v + 1; i++) {
		for (int j = 0; j < v + 1; j++) {
			if (i == j) {
				W[i][j] = 0;
			}
			else {
				W[i][j] = INFI;
			}
		}
	}
	printf("Input : startVertex endVertex weigh ( Input End : 0 0 0 )\n");
	while (1) {
		printf("Input : ");
		scanf("%d%d%d", &sv, &ev, &w);
		if (sv == 0) {
			break;
		}
		W[sv][ev] = w;
	 }
	
	floyd2(v, W, D, P);
	printf("\nMatrix of D\n");
	for (int i = 1; i < v + 1; i++) {
		for (int j = 1; j < v + 1; j++) {
			printf("%3d ", D[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix of P\n");
	for (int i = 1; i < v + 1; i++) {
		for (int j = 1; j < v + 1; j++) {
			printf("%3d ", P[i][j]);
		}
		printf("\n");
	}
	printf("\nWrite down the path you want. (startVertex endVertex) : ");
	scanf("%d%d", &sv, &ev);
	if (P[sv][ev] == 0) {
		printf("No path found.\n");
	}
	else {
		printf("v%d", sv);
		path(sv, ev, P);
		printf(" -> v%d", ev);
	}
	
	return 0;
}

void floyd2(int v, int *const *const W, int **D, int **P) {
	for (int i = 0; i < v + 1; i++) {
		for (int j = 0; j < v + 1; j++) {
			P[i][j] = 0;
			D[i][j] = W[i][j];
		}
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void path(int sv, int ev, int **P) {
	if (P[sv][ev] != 0) {
		path(sv, P[sv][ev], P);
		printf(" -> v%d", P[sv][ev]);
		path(P[sv][ev], ev, P);
	}
}
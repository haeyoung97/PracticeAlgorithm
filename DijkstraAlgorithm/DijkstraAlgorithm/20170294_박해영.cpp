#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<pair<int, pair<int, int>>> set_edges;
typedef vector<vector<int>> graph;

void dijkstra(int N, const graph W, set_edges* F);

#define INFI 100000000

int main() {
	int N, v1, v2, w;
	printf("Input Number of Vertices : ");
	scanf("%d", &N);
	graph W = graph(N + 1, vector<int>(N + 1, INFI));

	printf("Input Format : StartVertex EndVertex and Weight\nFinish Input : 0 0 0\n");
	while (1) {
		printf("Input : ");
		scanf("%d%d%d", &v1, &v2, &w);
		if (v1 == 0)
			break;
		W[v1][v2] = w;
	}
	printf("\n< W array >\n\n");
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (i == j || i == 0 || j == 0)
				W[i][j] = 0;
			if (W[i][j] == INFI)
				printf("INF  ");
			else
				printf("%d  ", W[i][j]);
		}
		printf("\n");
	}
	set_edges F;
	dijkstra(N, W, &F);
	printf("\n< Single-Source Shortest Paths >\n\n");
	for (int i = 0; i < F.size(); i++) {
		printf("<%d> ( v%d, v%d ),  weight = %d\n", i + 1, F[i].second.first, F[i].second.second, F[i].first);
	}

	return 0;
}

void dijkstra(int N, const graph W, set_edges* F) {
	int i, vnear;
	vector<int> touch = vector<int>(N + 1);
	vector<int> length = vector<int>(N + 1);
	for (i = 2; i <= N; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}
	int cnt = N - 1;
	while (cnt--) {
		int min = INFI;
		for (i = 2; i <= N; i++) {
			if (length[i] >= 0 && length[i] <= min) {
				min = length[i];
				vnear = i;
			}
		}
		F->push_back(make_pair(W[touch[vnear]][vnear], make_pair(touch[vnear], vnear)));
		for (i = 2; i <= N; i++) {
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct nodetype {
	int parent;
	int depth;
};

vector<nodetype> U;
typedef vector<pair<int, pair<int, int>>> set_edges;

void initial(int N);
bool equal(int p, int q);
void merge(int p, int q);
int find(int i);
void makeset(int i);
void kruskal(int n, int m, set_edges E, set_edges* F);

#define INFI 100000000

int main() {
	int N, M, v1, v2, w;
	set_edges E, F;

	printf("Input Number of Vertices : ");
	scanf("%d", &N);
	printf("Input Number of Edges : ");
	scanf("%d", &M);

	printf("Input Format : Two Vertices and Weight\n");
	for(int i = 0;i<M;i++) {
		printf("Input %d : ",i+1);
		scanf("%d%d%d", &v1, &v2, &w);
		E.push_back(make_pair(w, make_pair(v1, v2)));
	}

	U = vector<nodetype>(N + 1);
	kruskal(N, M, E, &F);

	printf("\n<  Minimum Spanning Tree  >\n\n");
	for (int i = 0; i < F.size(); i++) {
		printf("<%d> ( v%d, v%d ),  weight = %d\n",i+1, F[i].second.first, F[i].second.second, F[i].first);
	}
	return 0;
}

void kruskal(int n, int m, set_edges E, set_edges* F) {
	int i, j, p, q, e = 0;

	sort(E.begin(), E.end()); // C++에서 제공하는 퀵소트 기반 sort 함수

	initial(n+1);
	
	while (F->size() < n - 1) {
		i = E[e].second.first;
		j = E[e].second.second;
		p = find(i);
		q = find(j);
		if (!equal(p, q)) {
			merge(p, q);
			F->push_back(make_pair(E[e].first, make_pair(i, j)));
		}
		e++;
	}
}

void makeset(int i) { // 모두 각각 하나의 vertex로 구분
	U[i].parent = i;
	U[i].depth = 0;
}

int find(int i) {
	int j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;
}

void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth += 1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth)
		U[p].parent = q;
	else
		U[q].parent = p;
}
bool equal(int p, int q) {
	if (p == q)
		return true;
	else
		return false;
}

void initial(int N) {
	for (int i = 0; i < N; i++)
		makeset(i);
}
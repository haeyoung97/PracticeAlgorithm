#include <iostream>
#include <vector>

using namespace std;

int result;
void dfs(int root);

vector<vector<int>> v;
vector<bool> check;

int main() {
	int N,M;
	scanf("%d", &N);
	
	v = vector<vector<int>>(N + 1);
	check = vector<bool>(N + 1, true);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	dfs(1);
	printf("%d\n", result-1);
	return 0;
}

void dfs(int root) {
	if (!check[root])
		return;

	check[root] = false;
	result++;

	for (int i = 0; i < v[root].size(); i++) {
		dfs(v[root][i]);
	}
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> check;
queue<pair<int, int>> q;

int main() {
	int M, N, size, result = 0;
	scanf("%d%d", &M, &N);
	v = vector<vector<int>>(N,vector<int>(M));
	check = vector<vector<bool>>(N, vector<bool>(M,true));
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &v[i][j]);
			if (v[i][j] == -1)
				check[i][j] = false;
			if (v[i][j] == 1) {
				q.push(make_pair(j,i));
				check[i][j] = false;
			}	
		}
	}
	size = q.size();
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = node.first + dx[i];
			int y = node.second + dy[i];

			if (x >= 0 && x < M && y >= 0 && y < N && check[y][x]) {
				check[y][x] = false;
				q.push(make_pair(x, y));
				v[y][x] = 1;
			}
		}
		size--;
		if (size == 0) {
			result++;
			size = q.size();
		}
	}
	result--;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j]) {
				result = -1;
				break;
			}
		}
		if (result == -1)
			break;
	}
	
	printf("%d\n", result);

	return 0;
}
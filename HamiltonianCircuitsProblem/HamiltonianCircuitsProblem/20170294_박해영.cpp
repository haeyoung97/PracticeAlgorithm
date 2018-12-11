#include <iostream>
#include <vector>

using namespace std;

void hamiltonian(int i);
bool promising(int i);

vector<vector<bool>> W;
vector<int> vindex;
int n, cnt;

int main() {
	printf("Input number of vertices :");
	scanf("%d", &n);
	W = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
	vindex = vector<int>(n + 1, 0);
	printf("If there is an edge on the graph, write down two vertices.\n");
	printf("Input : two vertices ( finish Input : 0 0 )\n");
	while (1) {
		int v1, v2;
		printf("Input : ");
		scanf("%d%d", &v1, &v2);
		if (v1 == 0)
			break;
		W[v1][v2] = true; W[v2][v1] = true;
	}
	cnt = 1;
	vindex[0] = 1;
	printf("\n< Hamiltonian Circuits >\n\n");
	hamiltonian(0);
	printf("\n");
	return 0;
}

void hamiltonian(int i) {
	int j;
	if (promising(i)) {
		if (i == n - 1) {
			printf(" <%d> 1 -> ", cnt);
			for (int k = 1; k <= n - 1; k++)
				printf("%d -> ", vindex[k]);
			printf("1 \n");
			cnt++;
		}
		else {
			for (j = 2; j <= n; j++) {
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}
		}
	}
}

bool promising(int i) {
	int j; bool flag;

	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]]) // 출발점과 현재 정점이 연결이 되어있지 않다면
		flag = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]]) // 현재 정점과 이전 정점이 연결이 되어있지 않다면
		flag = false;
	else {
		flag = true;
		j = 1;
		while (j < i && flag) {
			if (vindex[i] == vindex[j]) // 이전 방문했던 노드를 또 방문했다면
				flag = false;
			j++;
		}
	}
	return flag;
}
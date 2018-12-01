#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> W;
vector<int> vcolor;
int n, m, cnt;


void m_coloring(int i);
bool promising(int i);

int main() {
	printf("Input number of vertices :");
	scanf("%d", &n);
	printf("Input number of color : ");
	scanf("%d", &m);
	W = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	vcolor = vector<int>(n + 1, 0);
	printf("If there is an edge on the graph, write down two vertices.\n");
	printf("Input : two vertices ( finish Input : 0 0 )\n");
	while (1) {
		int v1, v2;
		printf("Input : ");
		scanf("%d%d", &v1, &v2);
		if (v1 == 0)
			break;
		W[v1][v2] = 1; W[v2][v1] = 1;
	}
	cnt = 1;
	printf("\n< %d-coloring number of cases >\n\n", m);
	m_coloring(0);

	return 0;
}

void m_coloring(int i) {
	int color;

	if (promising(i)) {
		if (i == n) {
			printf(" <%d> ", cnt);
			for (int k = 1; k < n + 1; k++)
				printf("%d  ", vcolor[k]);
			printf("\n");
			cnt++;
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
		}
	}

}

bool promising(int i) {
	int j = 1;
	bool flag = true;

	while (j < i && flag) {
		if (W[i][j] && vcolor[i] == vcolor[j])
			flag = false;
		j++;
	}
	return flag;
}
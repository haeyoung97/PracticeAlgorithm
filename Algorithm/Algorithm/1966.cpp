#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	queue<int> q;
	queue<pair<int, int>> v;
	for (int i = 0; i < num; i++) {
		int N, M;
		scanf("%d%d", &N, &M);
		for (int j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			v.push(make_pair(j,tmp));
		}

		int cnt = N, index = 0;
		while (cnt--) {
			int max = 0;
			for (int j = 0; j<=cnt;j++) {
				if (max < v.front().second) {
					max = v.front().second;
					index = v.front().first;
				}
				v.push(v.front());
				v.pop();
			}

			for (int j = 0; j < v.size(); j++) {
				v.push(v.front());
				v.pop();
			}

			while (1) {
				if (index == v.front().first && max == v.front().second) {
					v.pop();
					break;
				}
				else {
					v.push(v.front());
					v.pop();
				}
			}
			q.push(index);
		}
		int result = 1;
		for (int j = 0; j < N; j++) {
			if (q.front() == M) {
				printf("%d\n", result);
				break;
			}
			else {
				result++;
				q.push(q.front());
				q.pop();
			}
		}
		while (!q.empty()) q.pop();
		while (!v.empty()) v.pop();
	}

	return 0;
}
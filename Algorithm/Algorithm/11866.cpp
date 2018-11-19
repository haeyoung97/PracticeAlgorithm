#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int M;
	scanf("%d", &M);
	int cnt = 1;
	printf("<");
	while (q.size() != 1) {
		if (cnt % M == 0) {
			printf("%d, ", q.front());
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}
	printf("%d>\n", q.front());
	q.pop();
	return 0;
}
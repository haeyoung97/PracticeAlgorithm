#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	queue<int> q;
	while (N != 0) {
		char str[100];
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			int num;
			scanf("%d", &num);
			q.push(num);
		}
		else if (!strcmp(str, "pop")) {
			if (!q.empty()) {
				printf("%d\n", q.front());
				q.pop();
			}
			else {
				printf("-1\n");
			}

		}
		else if (!strcmp(str, "size"))
			printf("%d\n", q.size());
		else if (!strcmp(str, "empty"))
			printf("%d\n", q.empty());
		else if (!strcmp(str, "front")) {
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("-1\n");
		}
		else if (!strcmp(str, "back")) {
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("-1\n");
		}
		N--;
	}


	return 0;
}
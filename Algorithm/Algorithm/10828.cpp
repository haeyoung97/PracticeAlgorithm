#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	stack<int> s;

	while (N != 0) {
		char str[100];
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			int num;
			scanf("%d", &num);
			s.push(num);
		}
		if (!strcmp(str, "pop")) {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else {
				printf("-1\n");
			}
			
		}
		else if (!strcmp(str, "size"))
			printf("%d\n", s.size());
		else if (!strcmp(str, "empty"))
			printf("%d\n", s.empty());
		else if (!strcmp(str, "top")) {
			if (!s.empty()) 
				printf("%d\n", s.top());
			else 
				printf("-1\n");
		}
		N--;
	}


	return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int N;
	bool flag = true;
	scanf("%d", &N);
	getchar();

	stack<char> s;

	for (int i = 0; i < N; i++) {
		while (1) {
			char ch;
			scanf("%c", &ch);

			if (ch == '\n')
				break;

			if (ch == '(') {
				s.push(ch);
			}
			else {
				if (!s.empty()) {
					s.pop();
				}
				else {
					flag = false;
					continue;
				}	
			}
		}
		if (s.empty() && flag)
			printf("YES\n");
		else
			printf("NO\n");
		while (!s.empty()) s.pop();
		flag = true;
	}

	return 0;
}
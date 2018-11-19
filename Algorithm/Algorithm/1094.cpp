#include <iostream>
#include <stack>

using namespace std;

int main() {
	int X, B = 64;
	int sum = 64;
	stack<int> s;
	scanf("%d", &X);

	s.push(B);
	while (1) {
		if (sum > X) {
			int div = s.top();
			div = div / 2;
			s.pop();
			s.push(div);
			if (sum - div >= X) {
				sum = sum - div;
			}
			else {
				s.push(div);
			}
		}
		else {
			break;
		}
	}

	printf("%d\n", s.size());

	return 0;
}
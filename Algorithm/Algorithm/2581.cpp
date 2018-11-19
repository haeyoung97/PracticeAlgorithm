#include <iostream>

using namespace std;

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	int sum = 0, min = 10000;

	for (int i = M; i <= N; i++) {
		int j = 1;
		while (1) {
			j++;
			if (i == 1)
				break;
			if (j == i) {
				if (min > i)
					min = i;
				sum += i;
				break;
			}
			if (i % j == 0) { // 나머지 = 0, 소수X
				break;
			}
		}
	}

	if (sum != 0)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1\n");


	return 0;
}
#include <iostream>

using namespace std;

int coef(int N, int K);

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	int result = coef(N, K);

	printf("%d\n", result);


	return 0;
}

int coef(int N, int K) {
	if (N == K || K == 0)
		return 1;
	return coef(N - 1, K) + coef(N - 1, K - 1);
}
#include <iostream>

using namespace std;

int coef(int N, int K);

int memo[1000][1000] = {0};

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
	else if (memo[N][K] != 0)
		return memo[N][K];
	else {
		memo[N][K] = (coef(N - 1, K) % 10007 + coef(N - 1, K - 1) % 10007) % 10007;
		return memo[N][K];
	}
}
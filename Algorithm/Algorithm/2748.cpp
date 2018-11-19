#include <iostream>

using namespace std;

typedef unsigned long long int lli;

lli fibo(int n);
lli memo[91] = { 0,1,1 };

int main() {
	int n;
	scanf("%d", &n);
	int ans = fibo(n);

	printf("%llu\n", ans);

	return 0;
}

lli fibo(int n) {
	if (n <= 2)
		return memo[n];
	else if (memo[n] != 0)
		return memo[n];
	else {
		memo[n] = fibo(n - 1) + fibo(n - 2);
		return memo[n];
	}
}

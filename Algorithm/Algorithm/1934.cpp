#include <iostream>

using namespace std;

int gcd(int A, int B);

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int A, B, g;
		scanf("%d%d", &A, &B);
		if (A >= B)
			g = gcd(A, B);
		else
			g = gcd(B, A);
		printf("%d\n", (A*B) / g);
	}


	return 0;
}

int gcd(int A, int B) {
	if (B == 0)
		return A;
	else
		return gcd(B, A%B);
}
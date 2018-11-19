#include <iostream>

using namespace std;
typedef unsigned long long llu;

llu gcd(llu A, llu B);

int main() {
	llu A, B, g;
	scanf("%llu%llu", &A, &B);
	if (A > B)
		g = gcd(A, B);
	else
		g = gcd(B, A);

	while (g--)
		printf("1");
	printf("\n");

	return 0;
}

llu gcd(llu A, llu B) {
	if (B == 0)
		return A;
	else
		return gcd(B, A%B);
}
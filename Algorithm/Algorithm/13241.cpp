#include <iostream>

using namespace std;
typedef long long int lld;

lld gcd(lld A, lld B);

int main() {
	lld A, B, g;
	scanf("%lld%lld", &A, &B);
	if (A > B)
		g = gcd(A, B);
	else
		g = gcd(B, A);

	printf("%lld\n", (A*B)/g);

	return 0;
}

lld gcd(lld A, lld B) {
	if (B == 0)
		return A;
	else
		return gcd(B, A%B);
}
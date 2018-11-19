#include <iostream>
#include <vector>

using namespace std;

int gcd(int A, int B);

int main() {
	int N, g;
	scanf("%d", &N);
	vector<int> v = vector<int>(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}


	for (int i = 1; i < N; i++) {
		if (v[0] > v[i])
			g = gcd(v[0], v[i]);
		else
			g = gcd(v[i], v[0]);

		printf("%d/%d\n", v[0] / g, v[i] / g);
	}

	return 0;
}

int gcd(int A, int B) {
	if (B == 0)
		return A;
	else
		return gcd(B, A%B);
}
#include <iostream>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	if (N < 100) {
		printf("%d\n", N);
	}
	else if (N >= 100 && N <= 110) {
		printf("%d\n", 99);
	}
	else {
		int ans = 99, cnt = N-110, M = 110;
		while (cnt--) {
			int i, j, k, tmp;
			M++;
			tmp = M;
			i = tmp % 10;
			tmp = tmp / 10;
			j = tmp % 10;
			k = tmp / 10;
			if ((j - i) == (k - j)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int M, N;
	scanf("%d%d", &M, &N);

	// true = 소수, false = 소수X
	vector<bool> v = vector<bool>(N+1, true);
	v[0] = false; v[1] = false;
	int i = 1;
	while (1) {
		if (i == (int)sqrt(N + 1))
			break;
		i++;
		if (v[i] == true) {
			int c = 2;
			for (int j = i+i; j < N+1; j = i*c) {
				v[j] = false;
				c++;
			}
		}
	}
	
	for (int i = M; i < N+1; i++) {
		if (v[i] == true)
			printf("%d\n", i);
	}

	return 0;
}
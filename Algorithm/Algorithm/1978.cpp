#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v = vector<int>(N);
	for(int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &tmp);
		v[i] = tmp;
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		int j = 1;
		while (1) {
			j++;
			if (v[i] == 1)
				break;
			if (j == v[i]) {
				result++;
				break;
			}
			if (v[i] % j == 0) {
				break;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
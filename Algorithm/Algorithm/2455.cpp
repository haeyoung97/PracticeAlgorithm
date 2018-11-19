#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> s, v;
	s = vector<int>(4);
	v = vector<int>(4);

	for (int i = 0; i < 4; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		s[i] = t1;
		v[i] = t2;
	}
	int max = v[0]-s[0];
	for (int i = 1; i < 4; i++) {
		if (max < max + v[i] - s[i]) {
			max = max + v[i] - s[i];
		}
	}

	printf("%d\n", max);


	return 0;
}
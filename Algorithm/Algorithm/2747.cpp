#include <iostream>

using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	int v[46];
	
	v[0] = 0;
	v[1] = 1;

	for (int i = 2; i <= n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}

	printf("%d\n",v[n] );

	return 0;
}

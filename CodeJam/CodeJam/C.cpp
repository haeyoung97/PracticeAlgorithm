#include <iostream>

using namespace std;
typedef unsigned long long int llu;

int main() {
	int T;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, P;
		scanf("%d%d", &N, &P);
		llu count = 1;
		char str[100][50];
		for (int j = 0; j < N; j++) {
			count *= 2;
		}
		for (int j = 0; j < P; j++) {
			scanf("%s", str[j]);
		}
		for (int j = 0; j < P-1; j++) {
			for (int k = j + 1; k < P; k++) {
				int sizeN = strlen(str[j]), sizeM = strlen(str[k]),bias=0,max = 0;
				if (sizeN < sizeM) {
					bias = sizeN;
					max = sizeM;
				}	
				else {
					bias = sizeM;
					max = sizeN;
				}
				if (strncmp(str[j], str[k], bias)==0) {
					int size = N - max;
					llu minus = 1;
					while (size--) {
						minus *= 2;
					}
					count += minus;
				}
				
			}
		}
		for (int k = 0; k < P; k++) {
			int size = N - strlen(str[k]);
			llu minus = 1;
			while (size--) {
				minus *= 2;
			}
			count -= minus;
		}
		printf("Case #%d: %llu\n", i + 1, count);
	}


	return 0;
}
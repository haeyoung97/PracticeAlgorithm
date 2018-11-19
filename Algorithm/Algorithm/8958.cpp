#include <stdio.h>

int main() {
	int result = 0, n = 0;
	char arr[81];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr);
		int j = 0, cnt = 1;
		while (arr[j] != '\0') {
			if (arr[j] == 'O') {
				result += cnt;
				cnt++;
			}
			else
				cnt = 1;
			j++;
		}
		printf("%d\n", result);
		while (j--) {
			arr[j] = ' ';
		}
		result = 0;
	}


	return 0;
}
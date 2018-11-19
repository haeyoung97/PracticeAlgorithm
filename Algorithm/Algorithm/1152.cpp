#include <stdio.h>
#include <string.h>

int main() {
	char arr[1000001];
	scanf("%[a-zA-Z ]", arr);
	int i = 0, cnt = 1;
	while (arr[i] == ' ') {
		i++;
	}
	while (arr[i] != '\0') {
		if (arr[i] == ' ') cnt++;
		i++;
	}
	i--;
	while (arr[i] == ' ') {
		cnt--;
		i--;
	}


	printf("%d\n", cnt);

	return 0;
	;
}
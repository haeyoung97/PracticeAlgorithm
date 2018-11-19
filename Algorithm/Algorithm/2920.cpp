#include <stdio.h>

int main() {
	int arr[9];
	int i = 0;
	for (int j = 0; j < 8; j++) {
		scanf("%d", &arr[j]);
	}
	
	if (arr[0] == 8) {
		while (arr[i] != '\0') {
			if (arr[i] != (8 - i)) {
				printf("mixed");
				break;
			}
			i++;
			if (i == 7) {
				printf("descending");
				break;
			}
		}
	
	}
	else if (arr[0] == 1) {
		while (arr[i] != '\0') {
			if (arr[i] != (1 + i)) {
				printf("mixed");
				break;
			}
			i++;
			if (i == 7) {
				printf("ascending");
				break;
			}
		}
	}
	else {
		printf("mixed");
	}


	return 0;
}
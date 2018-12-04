#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> w;
vector<string> include;
int W;

void sum_of_subsets(int i, int weight, int total);
bool promising(int i, int weight, int total);

int main() {
	int n, total = 0;
	printf("Input number of Item : ");
	scanf("%d",&n);
	printf("Input number of maximum weight : ");
	scanf("%d", &W);

	w = vector<int>(n + 1, 0);
	include = vector<string>(n + 1);
	for (int i = 1; i < n + 1; i++) {
		int tmpW;
		printf("Input weight of Item w%d : ", i);
		scanf("%d", &tmpW);
		w[i] = tmpW;
		total += tmpW;
	}
	printf("\n< Sum of subsets >\n\n");
	sum_of_subsets(0, 0, total);
	printf("\n");
	return 0;
}

void sum_of_subsets(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			for (int j = 1; j <= i; j++) {
				printf("include w%d : %s\n", j, include[j].c_str());
			}
		}
		else {
			include[i + 1] = "yes";
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = "no";
			sum_of_subsets(i + 1, weight, total - w[i + 1]);
		}
	}
}

bool promising(int i, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];
int N;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		int max = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i]) {
				max = max > dp[j] ? max : dp[j];
				dp[i] = max + 1;
			}
		}
	}
	sort(dp + 1, dp + N + 1);
	printf("%d\n", dp[N]);
}
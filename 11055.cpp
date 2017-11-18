#include <stdio.h>
int N;
int arr[1002];
int dp[1002];
int max = 0;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = dp[i] > dp[j] + arr[i] ? dp[i] : dp[j] + arr[i];
			}
		}
		max = max > dp[i] ? max : dp[i];
	}
	printf("%d", max);
}

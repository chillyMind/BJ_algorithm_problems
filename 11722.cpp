#include <stdio.h>

int N;
int arr[1001];
int dp[1001];
int mx = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
		}
		mx = mx > dp[i] ? mx : dp[i];
	}
	printf("%d", mx);
}
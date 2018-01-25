#include <stdio.h>
int n;
int arr[1001];
int dp[1001];
int ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n+1; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = dp[i] > dp[j] + arr[i] ? dp[i] : dp[j] + arr[i];
		}
		ans = dp[i] > ans ? dp[i] : ans;
	}
	printf("%d", ans);
}
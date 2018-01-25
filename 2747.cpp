#include <stdio.h>
int n;
int dp[46];
int main() {
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n+1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	printf("%d", dp[n]);
}
#include <stdio.h>
int n;
long long dp[1001];
int main() {
	scanf("%d", &n);
	if (n == 0) { printf("%d", 1); return 0; }
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	printf("%d\n", dp[n - 1]);
}

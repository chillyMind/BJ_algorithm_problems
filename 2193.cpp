#include <stdio.h>

int N; 
long long dp[91][2];

int main() {
	scanf("%d", &N);
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	printf("%lld", dp[N][0] + dp[N][1]);
}
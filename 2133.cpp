#include <stdio.h>

int n;
int dp[31];

int main() {
	scanf("%d", &n);
	if (n % 2==1) { printf("0"); return 0; }
	dp[1] = 3;
	dp[2] = 5;
	dp[3] = 11;
	dp[4] = 19;
	for (int i = 5; i <= n; i++) {
		dp[i] = dp[i - 2] * 4 - dp[i - 4];
	}
	printf("%d", dp[n-1]);
}
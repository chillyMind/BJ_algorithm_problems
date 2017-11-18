#include <stdio.h>
#include <stdlib.h>

int N;
int res;
int dp[1000001];

int main() {
	scanf("%d", &N);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}
	printf("%d", dp[N] % 15746);
}
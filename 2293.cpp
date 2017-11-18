#include <stdio.h>

int n, k;
int dp[10001];
int cost[101];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cost[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= cost[i])
				dp[j] += dp[j - cost[i]];
		}
	}
	printf("%d", dp[k]);
}
#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a):(b))

int n;
int p[1002];
int dp[1002];

int main() {
	scanf("%d", &n);
	dp[0] = 0;
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &p[i]);
		for (int j = 1; j <= i; j++)
			dp[i] = MAX(dp[i], dp[i-j]+ p[j]);
	}
	printf("%d", dp[n]);
}
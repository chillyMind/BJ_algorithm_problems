#include <stdio.h>
#define LL long long
int t,n,m;
LL dp[31][31];

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= 30; i++) {
		dp[i][i] = 1;
		dp[1][i] = i;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = i+1; j < 30; j++) {
			for (int k = j - 1; k >= i - 1; k--) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	while (t--) {
		scanf("%d %d", &n, &m);
		printf("%lld\n", dp[n][m]);
	}
}

/*
3
2 2
1 5
13 29
*/
#include <stdio.h>

using namespace std;

int n;
long long ans;
long long dp[101][11];
const int MOD = 1000000000;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j<=9; j++)
			dp[i][j] = dp[i - 1][j + 1] % MOD + dp[i - 1][j - 1] % MOD;
	}
	for (int i = 0; i <= 9; i++)
		ans = (ans + dp[n][i]%MOD)%MOD;
	printf("%lld", ans%MOD);
}
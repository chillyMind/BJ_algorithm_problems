#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dp[1000001];
int main() {
	scanf("%d", &n);
	memset(dp, 0x3f3f3f, sizeof(dp));
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i],1 + dp[i/2]);
		}
		if (i%3 == 0) {
			dp[i] = min(dp[i],1 + dp[i/3]);
		}
		dp[i] = min(dp[i],1 + dp[i - 1]);
	}
	printf("%d", dp[n]);
}
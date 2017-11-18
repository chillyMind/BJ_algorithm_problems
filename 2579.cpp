#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int st[301];
int dp[301];

int main() {
	scanf("%d", &n);
	st[0] = 0;
	for (int i = 1; i <=n; i++) {
		scanf("%d", &st[i]);
	}
	dp[0] = 0;
	dp[1] = st[1];
	dp[2] = dp[1] + st[2];
	dp[3] = max(st[3] + st[2], dp[1] + st[3]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + st[i], dp[i - 3] + st[i] + st[i - 1]);
	}
	printf("%d", dp[n]);
}
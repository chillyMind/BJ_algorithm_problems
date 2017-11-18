#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long arr[1000001];
long long dp[1000001];

int main() {
	scanf("%d", &n);
	long long ans = -2e9;
	for (int i = 1; i <= n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		arr[i] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans,dp[i]);
	}
	printf("%lld", ans);
}
#include <stdio.h>
using namespace std;

int n;
long long dp[100001];

int main() {
	dp[0] = 1;
	dp[1] = 3;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1]%9901 + dp[i - 1]%9901 - dp[i - 2]%9901 + 2*dp[i - 2])%9901;
	}	
	printf("%d", dp[n]%9901);
}
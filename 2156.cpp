#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int w[10001];
int dp[10001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &w[i]);
	}
	dp[0] = 0;
	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i-1], max(dp[i - 3] + w[i] + w[i-1], dp[i - 2] + w[i]));
	}
	printf("%d", dp[N]);
}
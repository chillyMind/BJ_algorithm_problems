#include <stdio.h>
#include <stdlib.h>
#include <vector>

int s;
int depth[501][501];
int dp[501][501];
int res=0;

int max(int a, int b) {
	return (a > b) ? a : b;
}
int main() {
	scanf("%d", &s);
	for (int i = 1; i <= s; i++) {
		for (int j = 0; j < i; j++) {
			//int tmp;
			scanf("%d", &depth[i][j]);
			//depth[i].push_back(tmp);
		}
	}
	dp[1][0] = depth[1][0];
	for (int i = 2; i <= s; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + depth[i][j];
		}
	}

	for (int i = 1; i<=s ; i++){
		for (int j = 0; j < i; j++) {
			res = max(dp[i][j], res);
		}
	}
	printf("%d", res);
}
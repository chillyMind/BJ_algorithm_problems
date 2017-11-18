#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int c[1001][3];
int dp[1001][3];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + c[i][j];
		}
	}
	printf("%d", min(dp[N][0], min(dp[N][1], dp[N][2])));
}
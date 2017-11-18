#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
int p[2][1002];
int dp[1002][1002];
int ans = 0;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)scanf("%d", &p[0][i]);
	for (int i = 1; i <= m; ++i)scanf("%d", &p[1][i]);
	sort(p[0] + 1, p[0] + n + 1);
	sort(p[1] + 1, p[1] + m + 1);

	if (n < m) {
		swap(n, m);
		swap(p[0], p[1]);
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j] = INF;

	dp[0][0] = 0;
	for (int j = 0; j <= m; ++j) {
		for (int i = 0; i <= n; ++i) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(p[0][i + 1] - p[1][j + 1]));
		}
	}
	printf("%d", dp[n][m]);
}
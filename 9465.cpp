#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
int arr[4][100003];
int dp[4][100003];

int main() {
	scanf("%d", &t);
	while(t--) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &arr[i][j]);
				//dp[i][j] = max(dp[i - 1][j] + arr[i][j-1],dp[i][j-2] + arr[i][j]+arr[i-1][j-1]);
			}
		}
		for (int i = 1; i <= n; i++) {
			dp[1][i] = max(dp[1][i - 1], arr[1][i] + dp[2][i - 1]);
			dp[2][i] = max(dp[2][i - 1], arr[2][i] + dp[1][i - 1]);
		}
		printf("%d\n", max(dp[2][n], dp[1][n]));
	}
}
#include <stdio.h>
#include <vector>
using namespace std;

long long dp[2][101];
vector<int> ans;
int t, n, mx=0;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int tmp;
		scanf("%d", &tmp);
		mx = mx < tmp ? tmp : mx;
		ans.push_back(tmp);
	}
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[0][1] = 1; 
	dp[1][1] = 1;
	dp[0][2] = 1;
	dp[1][2] = 2;
	for (int i = 3; i <= mx/2+1; i++) {
		dp[0][i] = dp[1][i-1] + dp[1][i - 3];
		dp[1][i] = dp[0][i] + dp[0][i - 2];
	}
	for (int i = 0; i < ans.size(); i++) {
		int n = ans[i];
		printf("%lld\n", dp[(n + 1) % 2][(n + 1) / 2]);
	}
}
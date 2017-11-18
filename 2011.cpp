#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
#define MOD 1000000

int dp[5001];
int ans;
string str;

int main() {
	ios::sync_with_stdio(false);

	cin >> str;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= str.length(); i++) {
		int cur = str[i-1] - 48;
		int prev = str[i - 2] - 48;
		if (cur != 0) dp[i] = dp[i - 1] % MOD;
		int tmp = prev * 10 + cur;
		if (tmp >= 10 && tmp <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}
	if (str[0] - 48 == 0 && str.length() == 1) {
		printf("%d", 0);
	}else{
		printf("%d", dp[str.length()]);
	}
}
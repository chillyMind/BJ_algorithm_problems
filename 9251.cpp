#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1;
string str2;
int dp[1010][1010];

int main() {
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d", dp[str1.size()][str2.size()]);
}

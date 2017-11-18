#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string str1;
string str2;
int dp[4001][4001], mx;

int main() {
	cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				mx = mx > dp[i][j] ? mx : dp[i][j];
			}
		}
	}
	printf("%d", mx);
}
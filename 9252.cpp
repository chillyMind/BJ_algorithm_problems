#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str1;
string str2;
vector<char> ans;
int dp[1002][1002];


int main() {
	ios::sync_with_stdio(false);
	cin >> str1 >> str2;
	for (int i = 1; i <= str2.size(); i++) {
		char s1_c = str2[i - 1];
		for (int j = 1; j <= str1.size(); j++) {
			char s2_c = str1[j - 1];
			if (s1_c == s2_c) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}/*
	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++)
			printf("%3d", dp[i][j]);
		printf("\n");
	}*/
	printf("%d\n", dp[str2.size()][str1.size()]);
	int x, y;
	x = str2.size();
	y = str1.size();
	while (1) {
		if (dp[x][y] == dp[x - 1][y]) {
			x--;
		}
		else if (dp[x][y] == dp[x][y - 1]) {
			y--;
		}
		else if (dp[x][y] != dp[x][y - 1] && dp[x][y] != dp[x - 1][y]) {
			ans.push_back(str1[y - 1]);
			x--; y--;
		}
		if (x == 0 || y == 0) break;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
}
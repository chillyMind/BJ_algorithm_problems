#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int t;
int m, n, k;
int mat[27][27];
int cnt = 2;
int eachCnt[BUFSIZ];
vector<int> ans;
vector<pair<int, int>> v;

bool dfs(int x, int y) {
	if (mat[x][y] > 1) {
		return false;
	}
	if (mat[x][y] == 0) {
		return false;
	}
	mat[x][y] = cnt;
	eachCnt[cnt]++;
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
	return true;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			int tmpint;
			scanf("%1d", &tmpint);
			mat[i][j] = tmpint;
			if(tmpint ==1) v.push_back(make_pair(i, j));
		}			
	}
	int tmpans;
	for (int j = 0; j < v.size(); j++) {
		if(dfs(v[j].first, v[j].second))cnt++;
	}
	printf("%d\n", cnt-2);
	for (int i = 2; i < cnt; i++) {
		ans.push_back(eachCnt[i]);
		//printf("%d\n", eachCnt[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}

/*
7
0110100
0110101
1110101
0000111
0000000
0000000
0000000
*/
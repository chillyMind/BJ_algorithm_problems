#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
int t;
int m,n,k;
int mat[52][52];
vector <int> ans;

bool dfs(int x, int y) {
	if (mat[x][y]==2) {
		return false;
	}
	if (mat[x][y] == 0) {
		return false;
	}
	mat[x][y] = 2;
	dfs(x + 1, y);
	dfs(x, y+1);
	dfs(x -1 , y);
	dfs(x, y - 1);
	return true;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int tmpans=0;
		vector <pair<int, int>> v;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x+1, y+1));
			mat[x+1][y+1] = 1;
		}
		for (int j = 0; j < k; j++) {
			if(dfs(v[j].first, v[j].second)) tmpans++;
		}
		ans.push_back(tmpans);
		memset(mat, 0, sizeof(mat));
	}
	for (int i = 0; i < t; i++)
		printf("%d\n", ans[i]);
}
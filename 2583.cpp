#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int m, n, k;
int cnt;
int eachCnt[BUFSIZ];
int board[101][101];
vector<int> ans;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y) {
	board[y][x] = cnt;
	eachCnt[cnt]++;
	//printf("curr y = %d x = %d %d %d (%d,%d)\n", y, x, cnt, board[y][x], m, n);
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%3d",board[i][j]);
	//	}
	//	printf("  %d\n", i);
	//}
	for (int i = 0; i < 4; i++) {
		if ((x+dx[i] > -1) && (y + dy[i] > -1) && (y + dy[i] < m) && (x + dx[i] < n)) {
			if (board[y + dy[i]][x + dx[i]] == 0) {
				//printf("next (y,x) [%d %d]\n", y + dy[i], x + dx[i]);
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = b; j < d; j++) {
			for (int l = a; l < c; l++) {
				board[j][l] = -1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <	n; j++) {
			if (board[i][j] == 0){
				cnt++;
				dfs(j,i);
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) {
		ans.push_back(eachCnt[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}
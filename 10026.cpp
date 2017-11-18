#include <stdio.h>
#include <vector>
#include <cstring>

int n;
int mat[102][102];
bool visited[102][102];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0,-1, 1 };

void dfs(int r, int c, int color, bool flag) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int tr = r + dx[i];
		int tc = c + dy[i];
		if (tr > 0 && tc > 0 && tr <= n && tc <= n)
			if (flag) {
				if (!visited[tr][tc] && (mat[tr][tc] == color)) {
					dfs(tr, tc, color, flag);
				}
			}
			else {
				if (!visited[tr][tc] && ((color!=0) == (mat[tr][tc]!=0))) {
					dfs(tr, tc, color, flag);
				}
			}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char tmpstring[102];
		scanf("%s", &tmpstring);
		for (int j = 0; j <= n; j++) {
			int tmpinput;
			if (tmpstring[j] == 'R') tmpinput = 2;
			if (tmpstring[j] == 'G') tmpinput = 1;
			if (tmpstring[j] == 'B') tmpinput = 0;
			mat[i][j+1] = tmpinput;
		}
	}
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && mat[i][j] == 0) {
				dfs(i, j, 0, 1); ans1++;
			}
			if (!visited[i][j] && mat[i][j] == 1) {
				dfs(i, j, 1, 1); ans1++;
			}
			if (!visited[i][j] && mat[i][j] == 2) {
				dfs(i, j, 2, 1); ans1++;
			}
			
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && mat[i][j] == 0) {
				dfs(i, j, 0, 0); ans2++;
			}
			if (!visited[i][j] && (mat[i][j] != 0)) {
				dfs(i, j, 1, 0); ans2++;
			}

		}
	}
	printf("%d %d", ans1, ans2);
}
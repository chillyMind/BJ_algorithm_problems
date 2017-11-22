#include <stdio.h>
#include <cstring>
using namespace std;

int mp[51][51];
int dr[] = { -1 , 1 , 0 , 0, 1, 1, -1,-1 };
int dc[] = { 0,0 , -1 , 1 ,1, -1, 1, -1};
int w, h, cnt;
bool visited[51][51];


void dfs(int r, int c) {
	visited[r][c] = true;
	for (int i = 0; i < 8; i++) {
		int tr = dr[i] + r;
		int tc = dc[i] + c;
		if (tr > -1 && tc > -1 && tr < h && tc < w && !visited[tr][tc] && mp[tr][tc]==1) {
			dfs(tr, tc);
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &mp[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && mp[i][j]==1) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}
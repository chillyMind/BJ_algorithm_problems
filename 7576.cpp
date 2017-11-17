#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int m, n,ans;
int mp[1001][1001];
int cnt = 0;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0 ,-1,1 };
queue <pair<int, int>> q;

void print() {
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", mp[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			if (mp[i][j] == 0) {
				cnt++;
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		ans = mp[tmp.first][tmp.second] > ans? mp[tmp.first][tmp.second] : ans;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tr = tmp.first + dr[i];
			int tc = tmp.second + dc[i];
			if (tr > -1 && tr < n && tc > -1 && tc < m) {
				if (mp[tr][tc] == 0) {
					mp[tr][tc] = mp[tmp.first][tmp.second] + 1;
					q.push(make_pair(tr, tc));
					cnt--;
					//print();
				}
			}
		}
	}
	printf("%d", cnt > 0 ? -1 : ans - 1);
}

/*
6 4
0 1 0 0 0 0
0 0 0 0 -1 -1
0 0 0 0 -1 0
0 0 0 0 -1 0
*/
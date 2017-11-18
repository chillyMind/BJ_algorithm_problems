#include <stdio.h>
#include <queue>
#include <iostream>
#include <string>
#include <tuple>
#include <cstring>
struct iii {
	int level, row, col;
	int min;
};
using namespace std;


bool mp[32][32][32];
int chk[32][32][32];
int dl[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };
iii s;
iii e;
queue<iii> q;
int L, R, C;

int main() {
	while (scanf("%d %d %d", &L, &R, &C) == 3) {
		while (!q.empty())q.pop();
		memset(chk, 0, sizeof(chk));
		bool hasEcaped = false;
		int cnt = 0;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				string tstring;
				cin >> tstring;
				for (int k = 1; k <= C; k++) {
					if (tstring[k - 1] == 'S') {
						mp[i][j][k] = true;
						s = { i,j,k,0 };
					}
					else if (tstring[k - 1] == '.') {
						mp[i][j][k] = true;
					}
					else if (tstring[k - 1] == '#') {
						mp[i][j][k] = false;
					}
					else if (tstring[k - 1] == 'E') {
						mp[i][j][k] = true;
						e = { i,j,k,0 };
					}
				}
			}
		}
		q.push(s);
		while (!q.empty()) {
			iii c = q.front();
			q.pop();
			if (c.level == e.level && c.row == e.row && c.col == e.col) {
				hasEcaped = true;
				cnt = c.min;
				break;
			}
			mp[c.level][c.row][c.col] = 0;
			for (int i = 0; i < 6; i++) {
				int tl = c.level + dl[i];
				int tr = c.row + dr[i];
				int tc = c.col + dc[i];
				if (tl > 0 && tr > 0 && tc > 0 && tl <= L && tr <= R && tc <= C) {
					if (mp[tl][tr][tc] != 0 && !chk[tl][tr][tc]) {
						q.push({ tl,tr,tc,c.min + 1 });
						chk[tl][tr][tc] = 1;
					}
				}
			}
		}
		if (hasEcaped) {
			printf("Escaped in %d minute(s).\n", cnt);
		}
		else {
			printf("Trapped!\n");
		}
	}
}
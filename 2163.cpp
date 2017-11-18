#include <stdio.h>

int N, M;
int cnt = 0;

void solve(int sx, int ex, int sy, int ey) {
	if (sx == ex && sy == ey) return;
	cnt++;
	int mx = (sx + ex) / 2;
	int my = (sy + ey) / 2;
	if (ex - sx > ey - sy) {
		solve(sx, mx, sy, ey);
		solve(mx + 1, ex, sy, ey);
	}
	else {
		solve(sx, ex, sy, my);
		solve(sx, ex, my + 1, ey);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	solve(1,N,1, M);
	printf("%d", cnt);
}
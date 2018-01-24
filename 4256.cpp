#include <stdio.h>

int t, n;
int PRE[1001];
int INO[1001];
int rn;

void solve(int s, int e) {
	int cur = rn;
	if (s > e || e < s) return;
	rn++;
	if (s == e) {
		printf("%d ", INO[s]);
		return;
	}
	int tm;
	for (int i = 0; i <= e; i++) {
		if (PRE[cur] == INO[i]) {
			tm = i;
			break;
		}
	}
	solve(s, tm - 1);
	solve(tm + 1, e);
	printf("%d ", INO[tm]);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		rn = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &PRE[i]);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &INO[j]);
		}
		solve(0, n - 1);
		printf("\n");
	}
}
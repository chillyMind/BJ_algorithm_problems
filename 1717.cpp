#include <stdio.h>
int n, m;
int parent[1000001];

int fid(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = fid(parent[x]);
	}
}


void uni(int x, int y) {
	x = fid(x);
	y = fid(y);
	parent[y] = x;
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int c,a, b;
		scanf("%d %d %d", &c, &a, &b);
		if (c==1) {
			printf("%s\n", fid(a) == fid(b) ? "YES" : "NO");
		}
		else {
			uni(a, b);			
		}
	}
	return 0;
}
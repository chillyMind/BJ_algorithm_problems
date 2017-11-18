#include <stdio.h>
int n, m, ans = 0;
int parent[101];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
		if (Find(i)==1) ans++;
	printf("%d", ans-1);
	return 0;
}
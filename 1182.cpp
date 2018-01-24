#include <stdio.h>
int n, s, arr[21], ans;

void dfs(int c, int sum, int m) {
	//printf("curr = %d %d sum = %d select = %d\n", c, arr[c],sum,m);
	if (c == n - 1) {
		if (sum == s && m != 0) {
			//printf("%d %d %d\n", c, sum, m);
			ans += 1;
		}
		return;
	}
	dfs(c + 1, sum + arr[c + 1], m + 1);
	dfs(c + 1, sum, m);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(-1, 0, 0);
	printf("%d", ans);
}
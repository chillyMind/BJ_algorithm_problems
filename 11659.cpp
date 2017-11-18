#include <stdio.h>

int sum[100001];
int n,m ;

int main() {
	scanf("%d %d", &n, &m);
	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum[i + 1] += sum[i]+a;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a < b ? sum[b] - sum[a - 1] : sum[a] - sum[b - 1]);
	}
}
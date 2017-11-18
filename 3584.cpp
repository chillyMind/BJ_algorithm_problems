#include <stdio.h>
#include <cstring>
using namespace std;

int t, n, ans;
bool visited[1000001];
int p[1000001];
int tmpd;

int main() {
	scanf("%d", &t);
	while (t--) {
		int a, b;
		memset(p, 0, sizeof(p));
		memset(visited, 0, sizeof(visited));
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			int tmpa, tmpb;
			scanf("%d %d", &tmpa, &tmpb);
			p[tmpb] = tmpa;
		}
		scanf("%d %d", &a, &b);
		if (a == b) ans = a;
		while (a != b) {
			visited[a] = true;
			visited[b] = true;
			if (visited[p[a]]&&p[a]!=0) {
				ans = p[a];
				break;
			}
			if (visited[p[b]]&&p[b]!=0) {
				ans = p[b];
				break;
			}
			a = p[a];
			b = p[b];
			if (a == b) ans = a;
		}
		printf("%d\n", ans);
	}
}
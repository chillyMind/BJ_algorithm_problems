#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, depth;
vector<int> v[10001];
//map<int, int> ans;
int dfn[10001];
int low[10001];
bool ans[10001];

void dfs(int h, bool f) {
	dfn[h] = ++depth;
	int low = n;
	int vcnt = 0;
	for (auto t : v[h]) {
		if (!dfn[t]) {
			dfs(t, 0);
			if (dfn[t] == dfn[h]) ans[h] = true;
			vcnt++;
		}
		low = min(low, dfn[t]);
	}
	dfn[h] = low;
	if (f) ans[h] = vcnt >= 2;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) dfs(i, 1);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (ans[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		if (ans[i])printf("%d ", i);
	}
}
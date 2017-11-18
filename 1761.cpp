#include <vector>
#include <stdio.h>

using namespace std;

int n, m;
vector<pair<int,int>> v[40001];
int depth[40001];
pair<int,int> parent[40001];
bool visited[40001];
vector<int> ans;

void dfs(int n, int d) {
	visited[n] = true;
	depth[n] = d;
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i].first;
		if (!visited[t]) {
			dfs(t, d + 1);
			parent[t] = make_pair(n,v[n][i].second);
		}
	}
}

int lca(int x, int y) {
	int distance = 0;
	while (depth[x] != depth[y]) {
		if (depth[x] > depth[y]) {
			distance += parent[x].second;
			x = parent[x].first;
		}
		else {
			distance += parent[y].second;
			y = parent[y].first;
		}
	}
	while (x != y) {
		distance += parent[x].second;
		distance += parent[y].second;
		x = parent[x].first;
		y = parent[y].first;
	}
	return distance;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int tmpa, tmpb,tmpc;
		scanf("%d %d %d", &tmpa, &tmpb,&tmpc);
		v[tmpa].push_back(make_pair(tmpb,tmpc));
		v[tmpb].push_back(make_pair(tmpa,tmpc));
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
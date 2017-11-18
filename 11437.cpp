#include <vector>
#include <stdio.h>

using namespace std;

int n ,m;
vector<int> v[50001];
int depth[50001];
int parent[50001];
bool visited[50001];
vector<int> ans;

void dfs(int n, int d,int p) {
	visited[n] = true;
	depth[n] = d;
	parent[n] = p;
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i];
		if (!visited[t]) {
			dfs(t,d+1,n);
		}
	}
}

int lca(int x, int y) {
	while (depth[x] != depth[y]) {
		if (depth[x] > depth[y]) {
			x = parent[x];
		}
		else {
			y = parent[y];
		}
	}
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int tmpa, tmpb;
		scanf("%d %d", &tmpa, &tmpb);
		v[tmpa].push_back(tmpb);
		v[tmpb].push_back(tmpa);
	}
	dfs(1, 0, 0);
	scanf("%d", &m);	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}	
}
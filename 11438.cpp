#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
vector <int> v[100001];
vector <int> ans;
bool visited[100001];
int d[100001];
int p[100001][21];

int n,m;

void dfs(int n) {
	visited[n] = true;	
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i];
		if (!visited[t]) {
			d[t] = d[n] + 1;
			p[t][0] = n;
			for (int i = 1; i <= 20; i++)
				p[t][i] = p[p[t][i - 1]][i - 1];				
			dfs(t);
		}
	}
}


int lca(int x, int y) {
	if (d[x] < d[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (1 << i <= d[x] - d[y]) x = p[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (p[x][i] != p[y][i]) {
			x = p[x][i];
			y = p[y][i];
		}		
	}
	return p[x][0];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}
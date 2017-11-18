#include <vector>
#include <iostream>

using namespace std;
vector<int> graph[10001];
int num = 0;

int visit[1001];
void dfs(int here) {
	visit[here] = 1;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visit[there] == 0) {
			dfs(there);
		}
	}
}

void addEdge(int u, int v) {
	graph[u].push_back(v);
	graph[v].push_back(u);
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			dfs(i);
			num++;
		}
	}
	printf("%d", num);
}
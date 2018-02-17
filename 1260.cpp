#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> node[10000];
int n, m, v;
bool visited[10000];
queue<int> q;

void dfs(int cur) {
	printf("%d ", cur);
	visited[cur] = true;
	for (int i = 0; i < node[cur].size(); i++) {
		int t = node[cur][i];
		if (!visited[t]) {
			dfs(t);
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		node[t1].push_back(t2);
		node[t2].push_back(t1);
	}
	for (int i = 0; i < n; i++) {
		sort(node[i].begin(), node[i].end());
	}
	dfs(v);
	printf("\n");
	memset(visited, false, sizeof(visited));
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < node[cur].size(); i++) {
			int t = node[cur][i];
			if (!visited[t]) {
				visited[t] = true;
				q.push(t);
			}
		}
	}
}
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> v[101];
int visited[101];

void dfs(int n,bool r) {
	if(!r)visited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i];
		if (!visited[t]) {
			dfs(t,0);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			scanf("%d", &tmp);
			if(tmp)	v[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
		for (int j = 1; j <= n; j++)
			printf("%d ", visited[j]);
		memset(visited, 0, sizeof(visited));
		printf("\n");
	}
}
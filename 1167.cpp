#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, ans;

vector<pair<int, int>> v[100001];
bool visited[100001];

pair<int,int> tmpnode = make_pair(0,0);

void dfs(int n, int depth) {
	//printf("[%d]\n",n);
	visited[n] = true;
	if (v[n].size() == 1 && visited[v[n][0].first]) {
		//printf("leaf %d\n", n);
		if (depth > tmpnode.second) {
			tmpnode = make_pair(n, depth);			
		}
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i].first;
		if (!visited[t]) {/*
			printf("%d to %d", n, t);
			printf("_w : %d\n",t,v[n][i].second);*/
			dfs(t, depth + v[n][i].second);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		while (1) {
			int tmpa, tmpb;
			scanf("%d", &tmpa);
			if (tmpa == -1) break;
			scanf("%d", &tmpb);
			v[a].push_back(make_pair(tmpa, tmpb));
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(tmpnode.first, 0);
	printf("%d\n", tmpnode.second);

}
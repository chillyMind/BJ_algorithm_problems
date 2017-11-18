#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
int n=1, m=1;
int cnt;
vector<int> v[501];
vector<int> ans;
bool visited[501];
bool dfs(int n,int from) {
	bool isTree = true;
	visited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int tv = v[n][i];
		if (!visited[tv]) {
			if (!dfs(tv, n)) {
				isTree = false;
			};
		}
		else {
			if (tv != from) {
				//printf("none tree\n");
				isTree = false;
				continue;
			}
		}
	}
	return isTree;
}

int main() {
	while (!(n == 0 && m == 0)) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int tmpa, tmpb;
			scanf("%d %d", &tmpa, &tmpb);
			v[tmpa].push_back(tmpb);
			v[tmpb].push_back(tmpa);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				//printf("launcehd %d\n", i);
				if(dfs(i,i)) cnt++;
			}
		}
		ans.push_back(cnt);
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		memset(visited, false, sizeof(visited));
		cnt = 0;
	}
	for (int i = 0; i < ans.size()-1; i++) {
		if (ans[i] > 1) {
			printf("Case %d: A forest of %d trees.\n", i + 1, ans[i]);
		}
		else if (ans[i] == 1) {
			printf("Case %d: There is one tree.\n", i + 1);
		}
		else {
			printf("Case %d: No trees.\n", i + 1);
		}
	}	
}
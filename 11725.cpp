#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> edge[100001];
int ans[100001];

void dfs(int curr, int prev){
	ans[curr] = prev;
	for (int i = 0; i < edge[curr].size(); i++) {
		if(ans[edge[curr][i]] == 0)
			dfs(edge[curr][i],curr);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int tmpp, tmpa;
		scanf("%d %d", &tmpp, &tmpa);
		edge[tmpp].push_back(tmpa);
		edge[tmpa].push_back(tmpp);
	}
	dfs(1,1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
}
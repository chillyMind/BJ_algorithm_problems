#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n;
int s, e;
int m;
int ans; //
vector<int> edge[1001];
bool visited[1001];
bool dfind = false;

int dfs(int curr, int d) {
	int tmpans = 0;
	if (visited[curr]) {
		return 0;
	}
	if (curr == e) {
		dfind = true;
		return d;
	}
	d++;
	visited[curr] = true;
	for (int i = 0; i < edge[curr].size(); i++) {
		tmpans += dfs(edge[curr][i], d);
	}
	return tmpans;
}

int main() {
	scanf("%d %d %d %d", &n, &s, &e, &m);
	for (int i = 0; i < m; i++) {
		int tmpp, tmpc;
		scanf("%d %d", &tmpp, &tmpc);
		edge[tmpp].push_back(tmpc);
		edge[tmpc].push_back(tmpp);
	}
	ans = dfs(s, 0);
	if (dfind) {
		printf("%d", ans);
	}
	else {
		printf("%d", -1);
	}
}

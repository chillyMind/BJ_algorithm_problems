#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m, t = 0;
int mp[301][301];
bool visited[301][301];

typedef struct ice {
	int r;
	int c;
	int size;
}Ice;
vector<Ice> ice;

void dfs(int r, int c) {
	if (visited[r][c] || mp[r][c] <= 0) return;
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int tr = dx[i] + r;
		int tc = dy[i] + c;
		if (tr <= n && tc <= m && mp[tr][tc] > 0 ){
			if (!visited[tr][tc]) {
				dfs(tr, tc);
			}
		}
	}
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf(" %2d ", mp[i][j]);
		}
		printf("\n");
	}
}
int melt(int r, int c) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int tr = dx[i] + r;
		int tc = dy[i] + c;
		if (!visited[tr][tc]) {
			ret++;
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {			
			scanf("%d", &mp[i][j]);
			if (mp[i][j] > 0) {
				Ice tice;
				tice.r = i; tice.c = j; tice.size = mp[i][j];
				ice.push_back(tice);

			}
		}
	}
	int init=0;
	int curr = 0;
	for (int i = 0; i < ice.size(); i++) {
		if (!visited[ice[i].r][ice[i].c]) {
			dfs(ice[i].r, ice[i].c);
			init++;
		}
	}
	curr = init;
	while (init == curr) {
		int tmp=0;
		t++;
		for (int i = 0; i < ice.size(); i++) {
			if (ice[i].size > 0) {
				int tmp = melt(ice[i].r, ice[i].c);
				ice[i].size -= tmp;
				mp[ice[i].r][ice[i].c] -= tmp;
			}		
		}
		//print();
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < ice.size(); i++) {
			if (ice[i].size <= 0) {
				continue;
			}
			if (!visited[ice[i].r][ice[i].c]) {
				dfs(ice[i].r, ice[i].c);
				tmp++;
			}
		}
		//printf("curr = %d\n", tmp);
		curr = tmp;
	}
	for (int i = 0; i < ice.size(); i++) {
		if (ice[i].size > 0) {
			printf("%d", t);
			return 0;
		}
	}
	printf("%d", 0);
	return 0;
}
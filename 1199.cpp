#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Bridge{
	int h, t;
	Bridge(int a, int b) {
		if (a < b)swap(a, b);
		h = a; t = b;
	}
};

int n;
vector<int> G[1001];
vector<int> ans;
int isVisited[1001][1001];
int degree[1001];
int edge_cnt = 0;
bool globalbool = false;

bool search(int n,int root) {
	if (n == root && edge_cnt == 0) {
		ans.push_back(n);
		return true;
	}
	bool isFound = false;
	for (int i = 0; i < G[n].size(); i++) {
		int t = G[n][i];
		if (isVisited[n][t] > 0) {
			isVisited[n][t]--;
			isVisited[t][n]--;
			edge_cnt -= 2;
			if (isFound = search(t, root)) {
				ans.push_back(n);
				return true;
			}
			isVisited[n][t]++;
			isVisited[t][n]++;
			edge_cnt += 2;
		}
	}
	return isFound;
}
bool exs() {
	for (int i = 1; i <= n; i++) {
		if (degree[i] % 2 != 0)
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			if (a != 0) {
				G[i].push_back(j);
				isVisited[i][j] = a;
				degree[i] += a;
				edge_cnt += a;
			}
		}
	}
	if (exs()) {
		search(1, 1);
		int i = ans.size();
		while (i--) {
			printf("%d ", ans[i]);
		}
	}else {
		printf("-1");
	}
}
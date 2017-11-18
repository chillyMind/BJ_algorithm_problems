#include <vector>
#include <stdio.h>

using namespace std;
vector<int> v[51];
int n, x;
int root;
int cnt = 0;

void dfs(int n) { // n 에서 dfs를 하세요
	//printf("[%d]\n", n);
	if (v[n].empty()) {
		cnt++;
		return;
	}
	else if (v[n].size() == 1 && v[n][0] == x) {
		cnt++;
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i];
		if (t != x) {
			dfs(t);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == -1) {
			root = i;
		}else{
			v[tmp].push_back(i);
		}
	}

	scanf("%d", &x);
	if (x != root) {
		dfs(root);
	}
	printf("%d", cnt);
}
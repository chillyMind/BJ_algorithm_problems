#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
int t,cnt;

vector<int> v[1001];
bool visitied[1001];

void dfs(int n) {
	visitied[n] = true;
	int t = v[n][0];
	if (visitied[t]){
		cnt++;
		return;
	}
	dfs(t);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			v[i].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visitied[i])
				dfs(i);
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		memset(visitied, 0, sizeof(visitied));
		cnt = 0;
	}
}
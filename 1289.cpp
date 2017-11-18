#include <vector>
#include <stdio.h>

using namespace std;
int n;
long long dist;
vector<pair<int,int>> v[100001];
bool visited[100001];
const int MOD = 1000000007;

long long dfs(int n) {
	long long tmpdist = 1;
	visited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int u = v[n][i].first;
		int uw = v[n][i].second;
		if (!visited[u]) {
			long long tmp = (uw *dfs(u))%MOD;
			dist += (tmp*tmpdist)%MOD;
			tmpdist = (tmpdist + tmp)%MOD;
		}		
	}
	return tmpdist;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	dfs(1);
	printf("%lld", dist%MOD);
}
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define ii pair<int,int>
#define INF 1e8;

int dp[1010][1010];
ii path[1010][1010];
vector<int> ans;
ii w[1010];
int mincost = INF;
ii minpair;

int dist(ii a,ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int N, M;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &w[i].first, &w[i].second);
	}
	w[0] = make_pair(1,1);
	w[1004] = make_pair(N,N);
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			int mx = max(i, j) + 1;
			int dis1 = dp[i][j] + dist(w[mx], w[i]);
			int dis2 = dp[i][j] + dist(w[mx], j == 0 ? w[1004] : w[j]);
			if (dp[mx][j] > dis1) {
				dp[mx][j] = dis1;
				path[mx][j] = make_pair(i, j);
			}
			if(dp[i][mx] > dis2){
				dp[i][mx] = dis2;
				path[i][mx] = make_pair(i,j);
			}
			//printf("[%d %d (%d)] > %d // %d %d %d %d\n", i, j, mx, dp[i][j], dp[mx][j], dp[i][mx],dis1,dis2);
		}
	}
	for (int i = 0; i < M; i++) {
		if (mincost > dp[M][i]) {
			mincost = dp[M][i];
			minpair = make_pair(M, i);
		}
		if(mincost > dp[i][M]) {
			mincost = dp[i][M];
			minpair = make_pair(i,M);
		}
	}
	printf("%d\n", mincost);
	int a = minpair.first;
	int b = minpair.second;
	while (1) {
		int tx = path[a][b].first;
		int ty = path[a][b].second;
		ans.push_back(tx != a ? 1 : 2);
		a = tx;
		b = ty;
		if (tx == 0 && ty == 0) break;
	}
	for (int i = ans.size()-1; i >= 0; i--) {
		printf("%d\n", ans[i]);
	}
}
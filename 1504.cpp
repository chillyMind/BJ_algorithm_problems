#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1e8

struct Edge {
	int t;
	long long w;
	Edge(int a, long long b) {
		t = a;
		w = b;
	}
	bool operator<(const Edge& e) const{
		return w > e.w;
	}
};

vector<Edge> v[801];
priority_queue<Edge> pq;
long long dist[2][801];
int N, E, cv1, cv2;

int main(){
	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		v[a].push_back(Edge(b, c));
		v[b].push_back(Edge(a, c));
	}
	
	scanf("%d %d", &cv1, &cv2);
	for (int i = 0; i <= N; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
	}
	pq.push(Edge(cv1, 0));
	dist[0][cv1] = 0;
	while (!pq.empty()) {
		long long w = pq.top().w;
		int c = pq.top().t;
		pq.pop();
		if (w > dist[0][c]) continue;
		for (int i = 0; i < v[c].size(); i++) {
			long long tw = w + v[c][i].w;
			int tc = v[c][i].t;
			if (dist[0][tc] > tw) {
				dist[0][tc] = tw;
				pq.push(Edge(tc, tw));
			}
		}
	}
	pq.push(Edge(cv2, 0));
	dist[1][cv2] = 0;
	while (!pq.empty()) {
		long long w = pq.top().w;
		int c = pq.top().t;
		pq.pop();
		if (w > dist[1][c]) continue;
		for (int i = 0; i < v[c].size(); i++) {
			long long tw = w + v[c][i].w;
			int tc = v[c][i].t;
			if (dist[1][tc] > tw) {
				dist[1][tc] = tw;
				pq.push(Edge(tc, tw));
			}
		}
	}
	/*for (int i = 1; i <= N; i++) {
		printf("dist %d : %d\n", i, dist[0][i]);
		printf("dist %d : %d\n", i, dist[1][i]);
	}*/
	long long ans[2];
	if (dist[0][1] == INF || dist[0][cv2] == INF || dist[1][N] == INF) {
		ans[0] = INF;
	}else{
		ans[0] = dist[0][1] + dist[0][cv2] + dist[1][N];
	}
	if (dist[1][1] == INF || dist[1][cv1] == INF || dist[0][N] == INF) {
		ans[1] = INF;
	}
	else {
		ans[1] = dist[1][1] + dist[1][cv1] + dist[0][N];
	}
	ans[0] = ans[0] < ans[1] ? ans[0] : ans[1];
	printf("%lld", ans[0] == INF? -1 : ans[0]);
	return 0;
}
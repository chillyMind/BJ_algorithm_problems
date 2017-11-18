#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9;
struct Edge {
	int e;
	long long w;
	Edge(int a, long long b) {
		e = a;
		w = b;
	}
	bool operator<(const Edge& e) const {
		return w > e.w;
	}
};

int n, m, f, t;
vector<Edge> v[1001];
long long dist[1001];
int from[1001];
int path[1001];
priority_queue<Edge> pq;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		Edge tmpe = Edge(b, c);
		v[a].push_back(tmpe);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[0] = 0LL;
	scanf("%d %d", &f, &t);
	pq.push({ f,0LL });
	while (!pq.empty()) {
		long long tw = pq.top().w;
		int cur = pq.top().e;
		pq.pop();
		if (tw > dist[cur]) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			long long ttw = tw + v[cur][i].w;
			int ttc = v[cur][i].e;
			if (dist[ttc] > ttw) {
				dist[ttc] = ttw;
				pq.push({ ttc,ttw });
				from[ttc] = cur;
			}
		}
	}
	printf("%lld\n", dist[t]);
	int df = t;
	path[0] = t;
	int mdist = 1;
	while (df != f) {
		path[mdist] = from[df];
		df = from[df];
		mdist++;
	}
	printf("%d\n", mdist);
	for (int i = mdist -1 ; i >=0; i--) {
		printf("%d ",path[i]);
	}
}
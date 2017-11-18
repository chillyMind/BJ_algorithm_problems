#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9;

struct Edge {
	int t, w;
	bool operator<(const Edge& e) const {
		return w > e.w;
	}
};


int N, M;
int p[1001];
vector<Edge> v[1001];
priority_queue<Edge> pq;
int dist[1001];
int from[1001];

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 2; i <= N; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	pq.push({ 1,0 });
	while (!pq.empty()) {
		Edge te = pq.top();
		pq.pop();
		if (te.w > dist[te.t]) continue;
		for (int i = 0; i < v[te.t].size(); i++) {
			int tw = te.w + v[te.t][i].w;
			int tc = v[te.t][i].t;
			if (dist[tc] > tw) {
				dist[tc] = tw;
				pq.push({ tc,tw });
				from[tc] = te.t;
			}
		}
	}
	printf("%d\n", N - 1);
	for (int i = 2; i <= N; i++) {
		printf("%d %d\n", i, from[i]);
	}
}

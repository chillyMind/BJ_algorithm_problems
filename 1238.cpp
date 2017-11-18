#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1e9;
using namespace std;

struct Edge {
	int t, w;
	Edge(int a, int b) {
		t = a;
		w = b;
	}
	bool operator<(const Edge& e) const {
		return w > e.w;
	}
};

int n, m, x;
vector<Edge> in[1001];
vector<Edge> out[1001];
int mx = 0;

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		in[a].push_back(Edge(b, c));
		out[b].push_back(Edge(a, c));
	}
	priority_queue<Edge> pq;
	int dist[2][1001];
	for (int i = 0; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
	}
	pq.push(Edge(x, 0));
	dist[0][x] = 0;
	while (!pq.empty()) {
		int w = pq.top().w;
		int cur = pq.top().t;
		pq.pop();
		if (w > dist[0][cur])continue;
		for (int i = 0; i < in[cur].size(); i++) {
			int tw = w + in[cur][i].w;
			int tcur = in[cur][i].t;
			if (dist[0][tcur] > tw) {
				dist[0][tcur] = tw;
				pq.push(Edge(tcur, tw));
			}
		}
	}
	pq.push(Edge(x, 0));
	dist[1][x] = 0;
	while (!pq.empty()) {
		int w = pq.top().w;
		int cur = pq.top().t;
		pq.pop();
		if (w > dist[1][cur])continue;
		for (int i = 0; i < out[cur].size(); i++) {
			int tw = w + out[cur][i].w;
			int tcur = out[cur][i].t;
			if (dist[1][tcur] > tw) {
				dist[1][tcur] = tw;
				pq.push(Edge(tcur, tw));
			}
		}
	}
	mx = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmpdist = dist[0][i] + dist[1][i];
		mx = mx > tmpdist ? mx : tmpdist;
	}
	printf("%d\n", mx);
	return 0;
}
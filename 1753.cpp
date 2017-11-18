#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1000000;

int v, e, s;

typedef struct edge {
	int v;
	int w;
	bool operator < (const edge e) const {
		return w > e.w;
	}
}Edge;

std::vector<Edge> vertex[20001];
std::priority_queue<Edge> pq;
long dist[20001];

int main(void) {
	scanf("%d %d %d", &v, &e, &s);

	for (int i = 0; i < e; i++) {
		int a;
		Edge tmpEdge;
		scanf("%d %d %d", &a , &tmpEdge.v, &tmpEdge.w);
		vertex[a].push_back(tmpEdge);
	}
	for (int i = 0; i <= v; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	Edge initEdge;
	initEdge.v = s;
	initEdge.w = 0;
	pq.push(initEdge);
	while (!pq.empty()) {
		long long w = pq.top().w;
		int curr = pq.top().v;
		pq.pop();

		if (w > dist[curr]) {
			continue;
		}
		for (int i = 0; i < vertex[curr].size(); i++) {
			long long tmpcurrw = w + vertex[curr][i].w;
			int tmpcurr = vertex[curr][i].v;
			if (dist[tmpcurr] > tmpcurrw) {
				dist[tmpcurr] = tmpcurrw;
				Edge tmpEdge;
				tmpEdge.v = tmpcurr;
				tmpEdge.w = tmpcurrw;
				pq.push(tmpEdge);
			}
		}
	}
	
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 1000000)
			printf("%s\n", "INF");
		else
			printf("%d\n", dist[i]);
	}
}


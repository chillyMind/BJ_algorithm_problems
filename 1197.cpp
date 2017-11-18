#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int f, t, w;
	bool operator<(const Edge& e) const {
		return w < e.w;
	}
};

int p[10001];
Edge e[100001];
int V, E, cost;

int Find(int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++) {
		p[i] = i;
	}
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &e[i].f, &e[i].t, &e[i].w);
	}
	sort(e, e + E);
	for (int i = 0; i < E; i++) {
		if (Find(e[i].f) != Find(e[i].t)) {
			cost += e[i].w;
			Union(e[i].f, e[i].t);
		}
	}
	printf("%d\n", cost);
}
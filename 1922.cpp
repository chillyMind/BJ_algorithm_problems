#include <stdio.h>
#include <algorithm>

using namespace std;

struct Edge {
	int f, t, w;
	bool operator<(const Edge& e) const {
		return w < e.w;
	}
};

int N, M;
int ans;
int p[1001];
Edge e[100001];

int Find(int x) {
	return p[x] = x == p[x] ? x : Find(p[x]);
}
void Union(int x, int y) {
	if (x > y) swap(x, y);
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &e[i].f, &e[i].t, &e[i].w);
	}
	sort(e, e + M);
	for (int i = 0; i < M; i++) {
		if (Find(e[i].f) != Find(e[i].t)) {
			ans += e[i].w;
			Union(e[i].f, e[i].t);
		}
	}
	printf("%d", ans);
}
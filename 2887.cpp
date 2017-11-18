#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
	int f, t,w;
	bool operator<(const Edge& e) const {
		return w > e.w;
	}
};

int N;
long long cost;
int p[100001];
pair<int, int> x[100001];
pair<int, int> y[100001];
pair<int, int> z[100001];
priority_queue<Edge> pq;

int Find(int x) {
	return p[x] = x == p[x] ? x : Find(p[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		int tx, ty, tz;
		scanf("%d %d %d", &tx, &ty, &tz);
		x[i] = { tx,i };
		y[i] = { ty,i };
		z[i] = { tz,i };
	}
	sort(x, x + N);
	for (int i = 1; i < N; i++) {
		int dist = x[i].first - x[i - 1].first;
		int f = x[i-1].second;
		int t = x[i].second;
		pq.push({ f,t,dist });
	}
	sort(y, y + N);
	for (int i = 1; i < N; i++) {
		int dist = y[i].first - y[i - 1].first;
		int f = y[i - 1].second;
		int t = y[i].second;
		pq.push({ f,t,dist });
	}
	sort(z, z + N);
	for (int i = 1; i < N; i++) {
		int dist = z[i].first - z[i - 1].first;
		int f = z[i - 1].second;
		int t = z[i].second;
		pq.push({ f,t,dist });
	}
	while (!pq.empty()) {
		Edge te = pq.top();
		pq.pop();
		if (Find(te.f) != Find(te.t)) {
			cost += te.w;
			Union(te.f, te.t);
		}
	}
	printf("%lld", cost);	
}
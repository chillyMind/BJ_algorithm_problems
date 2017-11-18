#include <stdio.h>
#include <vector>
#include <queue>

#define INF 100000001;

typedef struct bus{
	int e;
	int cost;
	bool operator<(const bus b) const {
		return cost > b.cost; // cost가 더 작은 것을 더 큰 우선수위를 줌
	}
}Bus;

int n, m, s, e;
std::vector<Bus> cities[1001];
long dist[100001];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a;
		Bus tmpBus;
		scanf("%d %d %d", &a, &tmpBus.e, &tmpBus.cost);
		cities[a].push_back(tmpBus);
	}
	scanf("%d %d", &s, &e);

	for (int i = 0; i < n+1; i++) {
		dist[i] = INF;
	}

	dist[s] = 0;
	std::priority_queue<Bus> pq;
	Bus initBus;
	initBus.cost = 0;
	initBus.e = s;
	pq.push(initBus);
	
	while (!pq.empty()) {
		long long cost = pq.top().cost;
		int curr = pq.top().e;
		pq.pop();

		if (cost > dist[curr]) {
			continue;
		}
		
		for (int i = 0; i < cities[curr].size(); i++) {
			long long tmpcurrcost = cost + cities[curr][i].cost;
			int tmpcurr = cities[curr][i].e;
			if (dist[tmpcurr] > tmpcurrcost) {
				dist[tmpcurr] = tmpcurrcost;
				Bus tmpBus;
				tmpBus.e = tmpcurr;
				tmpBus.cost = tmpcurrcost;
				pq.push(tmpBus);
			}			
		}
	}
	printf("%d", dist[e]);
}
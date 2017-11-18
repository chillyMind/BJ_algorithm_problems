#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> v[32001];
int in[32001];
priority_queue<int> pq;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		in[b]++;
	}

	for (int i = 1; i < n+1; i++) {
		if (in[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int it = -pq.top();
		printf("%d ", it);
		pq.pop();
		for (int i = 0; i < v[it].size(); i++) {
			int t = v[it][i];
			in[t]--;
			if (in[t] == 0) {
				pq.push(-t);
			}
		}
	}
}

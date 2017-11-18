#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, ans = 1;
typedef struct Ninfo {
	int g, s, b, num;
	bool operator==(const Ninfo n) const {
		if (g == n.g) {
			if (s == n.s) {
				return b == n.b;
			}
			else return false;
		}
		else return false;
	}
	bool operator<(const Ninfo n) const {
		if (g == n.g) {
			if (s == n.s) {
				return b < n.b;
			}
			else return s < n.s;
		}
		else return g < n.g;
	}
};
priority_queue<Ninfo> pq;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		Ninfo tmp;
		scanf("%d %d %d %d", &tmp.num, &tmp.g, &tmp.s, &tmp.b);
		pq.push(tmp);
	}
	Ninfo prev = pq.top();
	pq.pop();
	int same = 0;
	while (!pq.empty()) {
		if (prev.num == K) break;
		Ninfo tmp = pq.top();
		pq.pop();
		if (tmp == prev) {
			same++;
		}
		else {
			same = 0;
		}
		ans++;
		prev = tmp;
	}
	printf("%d", ans - same);
}
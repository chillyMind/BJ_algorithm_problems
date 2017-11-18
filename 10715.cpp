#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>

int n;
int m;
std::set<int> c1;
std::queue<int> q;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		c1.insert(a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		c1.count(a) ? q.push(1) : q.push(0);
	}
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
}
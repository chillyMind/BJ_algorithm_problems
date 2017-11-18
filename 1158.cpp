#include <stdio.h>
#include <queue>
#include <algorithm>

int n;
int m;
std::queue<int> q;
std::queue<int> p;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}
	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < m-1; j++) {
			int tmp;
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		p.push(q.front());
		q.pop();
	}
	printf("<");
	for (int i = 0; i < n; i++) {
		printf("%d",p.front());
		if(i + 1 != n) printf(", ");
		p.pop();
	}
	printf(">");
}
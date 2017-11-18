#include <stdio.h>
#include <stdlib.h>
#include <queue>

int n;
int p[1001];
int sum=0;
std::priority_queue<int> pq;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		a = -a;
		pq.push(a);
	}
	int i = 0;
	while (!pq.empty()) {
		int s1 = pq.top();
		pq.pop();
		sum += s1;
		p[i] = sum;
		i++;
	}
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}
	printf("%d", -sum);
}
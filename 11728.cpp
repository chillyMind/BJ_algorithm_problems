#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int N, M;
priority_queue<int> pq;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		pq.push(-tmp);
	}
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		pq.push(-tmp);
	}
	while (!pq.empty()) {
		printf("%d ", -pq.top());
		pq.pop();
	}
}
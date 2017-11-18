#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;
int n;

int main() {
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		int tmp;
		scanf("%d", &tmp);
		pq.push(-tmp);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			pq.push(-tmp);
			pq.pop();
		}
	}
	printf("%d", -pq.top());
}
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<long long> pq;
long long n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		if (tmp == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%lld\n", -pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(-tmp);
		}
	}
}
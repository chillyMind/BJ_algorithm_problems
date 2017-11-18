#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int> pq;
vector<int> ans;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {
			pq.push(tmp);
		}
		else if (tmp == 0) {
			if (pq.empty()) {
				ans.push_back(0);
			}
			else {
				ans.push_back(pq.top());
				pq.pop();
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}	
}
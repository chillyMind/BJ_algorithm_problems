#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int n;

struct Node {
	int first;
	Node(int p) {
		first = p;
	}
	bool operator<(const Node& n) const{
		if (abs(first) == abs(n.first)) {
			return first > n.first;
		}
		return abs(first) > abs(n.first);
	}
};

priority_queue<Node> pq;
vector<int> ans;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0){
			if (!pq.empty()) {
				ans.push_back(pq.top().first);
				pq.pop();
			}else {
				ans.push_back(0);
			}
		}else {
			Node tmpN = Node(tmp);
			pq.push(tmpN);
		}
	}
	
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int a, b;
	Node(int x, int y) {
		a = x;
		b = y;
	}
	bool operator<(const Node& n) const{
		if (a == n.a) {
			return b > n.b;
		}
		return a > n.a;
	}
};

int n, m;
vector<int> v[101];
priority_queue<Node> pq;
queue<int> q;
int visited[101];
int kn = 0;

int main() {
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int depth = 1;
		q.push(i);
		visited[i] = depth;
		while (!q.empty()) {
			int tt = q.front();
			q.pop();
			for (int i = 0; i < v[tt].size(); i++) {
				int there = v[tt][i];
				if (!visited[there]) {
					visited[there] = visited[tt]+1;
					kn += visited[there];
					q.push(there);
				}
			}
		}
		pq.push(Node(kn,i));
		kn = 0;
		memset(visited, 0, sizeof(visited));
	}
	printf("%d", pq.top().b);
}
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define ii pair<int,int>
#define INF 1e9;

struct Node {
	int x, y, d;
	Node(int a, int b, int c) {
		x = a;
		y = b;
		d = c;
	}
	bool operator<(const Node& n)const {
		return d > n.d;
	}
};

int n, f, t,te;
short mp[127][127];
int dist[127][127];
int dx[4] = { 0, 0 ,-1 ,1 };
int dy[4] = { 1,-1 ,0 ,0 };
priority_queue<Node> pq;

int main() {
	te = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &mp[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dist[i][j] = INF;
		}
		dist[1][1] = mp[1][1];
		Node initnode = Node(1, 1, mp[1][1]);
		pq.push(initnode);
		while (!pq.empty()) {
			int tw = pq.top().d;
			int cx = pq.top().x;
			int cy = pq.top().y;
			pq.pop();
			if (tw > dist[cy][cx]) continue;
			for (int i = 0; i < 4; i++) {
				int tcx = cx + dx[i];
				int tcy = cy + dy[i];
				int ttw = tw + mp[tcy][tcx];
				//printf(">>[%d %d] d(ttw): %d dist[tcy][tcx] %d\n", tcx, tcy, ttw, dist[tcy][tcx]);
				if (tcx < 1 || tcy < 1 || tcx > n || tcy > n) continue;
				if (dist[tcy][tcx] > ttw) {
					dist[tcy][tcx] = ttw;
					//printf("done ttw : %d\n", ttw);
					Node newnode = Node(tcx, tcy, ttw);
					pq.push(newnode);
				}
			}
		}
		printf("Problem %d: %d\n",te, dist[n][n]);
		te++;
	}
}
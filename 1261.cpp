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

int n, m, f, t;
int row, col;
int mp[102][102];
int dist[102][102];
int dx[4] = { 0, 0 ,-1 ,1 };
int dy[4] = { 1,-1 ,0 ,0 };
priority_queue<Node> pq;

int main() {
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf("%1d", &mp[i][j]);
		}
	}
;	for (int i = 1; i <= row; i++) {
		for(int j = 1 ; j <= col ; j++)
			dist[i][j] = INF;
	}
	dist[1][1] = 0;
	Node initnode = Node(1, 1, 0 );
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
			if (tcx < 1 || tcy < 1 || tcx > col || tcy > row) continue;			
			if (dist[tcy][tcx] > ttw) {
				dist[tcy][tcx] = ttw;
				//printf("done ttw : %d\n", ttw);
				Node newnode = Node(tcx, tcy, ttw);
				pq.push(newnode);
			}
		}
	}
	printf("%d", dist[row][col]);
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;
int cnt = 1;
int board[101][101];
int milesboard[101][101];
int dx[4] = { 1 ,-1 ,0, 0 };
int dy[4] = { 0 , 0 ,1 ,-1 };
bool bridgefind = false;
struct BFSPRM {
	int x;
	int y;
	int miles;
	int from;
	BFSPRM(int x, int y, int m, int f) {
		this->x = x;
		this->y = y;
		this->miles = m;
		this->from = f;
	}
};
priority_queue<int> pq;
queue<BFSPRM> q;

void dfs(int x, int y) {
	board[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
			if (board[tx][ty] == 1) {
				dfs(tx, ty);
			}
		}
	}
}

void bfs(int x, int y, int miles, int from) {
	miles++;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
			if (board[tx][ty] == 0) {
				BFSPRM tmp = BFSPRM(tx, ty, miles, from);
				q.push(tmp);
				board[tx][ty] = -from;
				milesboard[tx][ty] = miles;
			}
			else if (board[tx][ty] < 0 && -from != board[tx][ty]) {
				miles--;
				pq.push(-miles - milesboard[tx][ty]);
				bridgefind = true;
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf(" %d", &board[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] > 1) {
				BFSPRM tmp = BFSPRM(i, j, 0, board[i][j]);
				q.push(tmp);
			}
		}
	}
	while (!q.empty()) {
		BFSPRM tmp = q.front();
		q.pop();
		bfs(tmp.x, tmp.y, tmp.miles, tmp.from);
	}
	if (!pq.empty())
		printf("%d", -pq.top());
	else
		printf("0");
}
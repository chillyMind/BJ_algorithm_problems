#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int n, m;
int sx, sy, d;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int mat[51][51];
int ans=1;

void dfs(int x, int y, int d) {
	//본인의 왼쪽 좌표 구하기
	//if d = 0 >> 절대값 = 상대값 (x-1)
	//if d = 1 >> 절대값 y+1
	//if d = 2 >> 절대값 x+1
	//if d = 3 >> 절대값 y-1
	//  0  1  2  3
	//x -1 0 +1  0
	//y 0 +1  0  -1
	//본인의 후진 좌표 구하기
	//if d = 0 >> 절대값 = 상대값 (y+1)
	//if d = 1 >> x-1
	//if d = 2 >> y-1
	//if d = 3 >> x+1
	mat[x][y] = 2;
	if (mat[x + dx[d]][y + dy[d]] == 0) {
		ans++;
		dfs(x + dx[d], y + dy[d],(d+3)%4);
	}
	else if (
		mat[x + dy[d]][y - dx[d]] == 2 &&
		mat[x + dy[(d + 1) % 4]][y - dx[(d + 1) % 4]] != 0 &&
		mat[x + dy[(d + 2) % 4]][y - dx[(d + 2) % 4]] != 0 &&
		mat[x + dy[(d + 3) % 4]][y - dx[(d + 3) % 4]] != 0) {
		dfs(x + dy[d], y - dx[d], d);
	}
	else if (mat[x + dy[d]][y - dx[d]] == 1 &&
		mat[x + dy[(d + 1) % 4]][y - dx[(d + 1) % 4]] != 0 &&
		mat[x + dy[(d + 2) % 4]][y - dx[(d + 2) % 4]] != 0 &&
		mat[x + dy[(d + 3) % 4]][y - dx[(d + 3) % 4]] != 0) {
		//printf("%d %d %d", x + dy[d],y- dx[d], d);
		//printf("[3]");
		return;
	}
	else if (mat[x + dx[d]][y + dy[d]] != 0) {
		dfs(x, y, (d + 3) % 4);
	}
	return;
}

int main() {
	cin >> n >> m >> sx >> sy >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &mat[j][i]);
		}
	}

	dfs(sy, sx, d);
	printf("%d", ans);
}
/*
5 7
1 1 0
1 1 1 1 1 1 1
1 0 1 0 0 0 1
1 0 0 0 1 0 1
1 0 0 0 1 0 1
1 1 1 1 1 1 1
*/
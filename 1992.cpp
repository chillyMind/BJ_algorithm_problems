#include <stdio.h>
#include <stdlib.h>
bool **mat;

void solve(int x, int y, int size) {
	bool isSame=true;
	bool init = mat[y][x];
	for (int tmpX = x; tmpX < x + size; tmpX++) {
		for (int tmpY = y; tmpY < y + size; tmpY++) {
			if (mat[tmpY][tmpX] != init) {
				isSame = false;
				break;
			}
		}
		if (!isSame) { break; }
	}
	if (isSame) {
		printf("%d", init);
	}
	else {
		printf("%c", '(');
		int tmpSize = size / 2;
		solve(x,y, tmpSize);
		solve(x+tmpSize,y ,tmpSize);
		solve(x, y + tmpSize, tmpSize);
		solve(x + tmpSize, y + tmpSize, tmpSize);
		printf("%c", ')');
	}
	
}

int main(){
	int n;
	scanf("%d", &n);
	mat = (bool**)malloc(sizeof(bool*)*n);
	for (int i = 0; i < n; i++) {
		mat[i] = (bool*)malloc(sizeof(bool)*n);
		for (int j = 0; j < n; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}
	solve(0, 0, n);
	return 0;
}
#include <stdio.h>
#include <math.h>
int mat[2188][2188];
int k;
int count[3] = { 0 };

int dfs(int x, int y, int size) {
	if (size == 1) {
		count[mat[x][y] + 1]++;
		return mat[x][y];
	}
	int tmpsize = size / 3;
	int tmp = mat[x][y];
	bool isSame = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int a = dfs(x + i * tmpsize, y + j *tmpsize, tmpsize);
			if (tmp != a) {
				//printf("different %d %d \n",mat[x][y], a);
				isSame = false;
			}
		}
	}
	if (isSame) {
		count[tmp + 1] -= 8;
		return tmp;
	}
	else {
		return 2;
	}
}

int main(void) {
	scanf("%d", &k);

	for (int i = 0; i < k ; i++) {
		for (int j = 0; j < k ; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	dfs(0, 0, k);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", count[i]);
	}
}
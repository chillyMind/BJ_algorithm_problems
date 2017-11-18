#include <stdio.h>
#include <algorithm>
#include <vector>

typedef struct trash {
	bool isVisited = false;
	int x;
	int y;
}Trash;

Trash trashes[BUFSIZ];
int x = 0;
int y = 0;
int trashnum;
int coords[102][102];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0 ,-1,1 };
int findCC(int num) {
	if (trashes[num].isVisited) {
		return 0;
	}
	int size = 1;
	trashes[num].isVisited = true;
	int currX = trashes[num].x;
	int currY = trashes[num].y;
	for (int i = 0; i < 4; i++) {
		int tx = currX + dx[i];
		int ty = currY + dy[i];
		if (coords[ty][tx] > 0)
			size += findCC(coords[ty][tx]);
	}
	return size;
}


int main() {
	int sizes[10001];

	scanf("%d %d %d", &x, &y, &trashnum);
	for (int i = 1; i <= trashnum; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		trashes[i].x = a;
		trashes[i].y = b;
		coords[b][a] = i;
	}

	for (int i = 1; i <= trashnum; i++) {
		sizes[i] = findCC(i);
	}

	std::sort(sizes, sizes + trashnum);
	printf("%d", sizes[trashnum - 1]);
	return 0;
}
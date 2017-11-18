#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

typedef struct node {
	int currX;
	int currY;
	int m_dist;
}Node;

int m;
int x, y;
int startX, startY;
int map[1001][1001];
int dist = -1;
int result[100];
bool isVisited[1001][1001];
bool finished = false;
std::queue<Node> q;
std::queue<Node> fireQ;

void bfs(int currX, int currY, int m_dist) {
	isVisited[currX][currY] = true;
	m_dist++;
	if (finished) {
		return;
	}
	else if (currX == 1 || currY == 1 || currX == y || currY == x) {
		dist = m_dist;
		finished = true;
		return;
	}

	if (!isVisited[currX - 1][currY] && map[currX - 1][currY]) {
		Node tmpNode;
		tmpNode.currX = currX - 1;
		tmpNode.currY = currY;
		tmpNode.m_dist = m_dist;
		isVisited[currX - 1][currY] = 1;
		q.push(tmpNode);
	}
	if (!isVisited[currX][currY - 1] && map[currX][currY - 1]) {
		Node tmpNode;
		tmpNode.currX = currX;
		tmpNode.currY = currY - 1;
		tmpNode.m_dist = m_dist;
		isVisited[currX][currY - 1] = 1;
		q.push(tmpNode);
	}
	if (!isVisited[currX + 1][currY] && map[currX + 1][currY]) {
		Node tmpNode;
		tmpNode.currX = currX + 1;
		tmpNode.currY = currY;
		tmpNode.m_dist = m_dist;
		isVisited[currX + 1][currY] = 1;
		q.push(tmpNode);
	}
	if (!isVisited[currX][currY + 1] && map[currX][currY + 1]) {
		Node tmpNode;
		tmpNode.currX = currX;
		tmpNode.currY = currY + 1;
		tmpNode.m_dist = m_dist;
		isVisited[currX][currY + 1] = 1;
		q.push(tmpNode);
	}
	return;
}

void fireBfs(int currX, int currY, int m_dist) {
	map[currX][currY] = 0;
	m_dist++;
	if (map[currX - 1][currY] == 1) {
		Node fireNode;
		fireNode.currX = currX - 1;
		fireNode.currY = currY;
		fireNode.m_dist = m_dist;
		fireQ.push(fireNode);
	}
	if (map[currX][currY - 1] == 1) {
		Node fireNode;
		fireNode.currX = currX;
		fireNode.currY = currY - 1;
		fireNode.m_dist = m_dist;
		fireQ.push(fireNode);
	}
	if (map[currX + 1][currY] == 1) {
		Node fireNode;
		fireNode.currX = currX + 1;
		fireNode.currY = currY;
		fireNode.m_dist = m_dist;
		fireQ.push(fireNode);
	}
	if (map[currX][currY + 1] == 1) {
		Node fireNode;
		fireNode.currX = currX;
		fireNode.currY = currY + 1;
		fireNode.m_dist = m_dist;
		fireQ.push(fireNode);
	}
	return;
}


int main() {
	scanf("%d", &m);
	for (int k = 0; k<m; k++) {
		scanf("%d %d", &x, &y);
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				char a;
				char b[2];
				scanf("%1s", &b);
				a = b[0];
				if (a == '#') {
					map[i][j] = 0;
				}
				else if (a == '*') {
					map[i][j] = 0;
					Node fireNode;
					fireNode.currX = i;
					fireNode.currY = j;
					fireNode.m_dist = -2;
					fireQ.push(fireNode);
				}
				else if (a == '@') {
					map[i][j] = 1;
					startX = i;
					startY = j;
				}
				else {
					map[i][j] = 1;
				}
			}
		}

		bfs(startX, startY, 0);
		while (1) {
			if (!q.empty() && !fireQ.empty()) {
				Node tmpNode = q.front();
				Node fireNode = fireQ.front();
				if (tmpNode.m_dist <= fireNode.m_dist) {
					bfs(tmpNode.currX, tmpNode.currY, tmpNode.m_dist);
					q.pop();
				}
				else {
					fireBfs(fireNode.currX, fireNode.currY, fireNode.m_dist);
					fireQ.pop();
				}
			}
			else if (!q.empty()) {
				Node tmpNode = q.front();
				bfs(tmpNode.currX, tmpNode.currY, tmpNode.m_dist);
				q.pop();
			}
			else {
				break;
			}

		}

		result[k] = dist;
		while (!q.empty()) { q.pop(); }
		while (!fireQ.empty()) { fireQ.pop(); }
		memset(map, 0, 1001 * 1001 * sizeof(int));
		memset(isVisited, false, 1001 * 1001 * sizeof(bool));
		finished = false;
		dist = -1;
	}
	for (int i = 0; i < m; i++) {
		if (result[i] == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", result[i]);
	}
	return 0;
}
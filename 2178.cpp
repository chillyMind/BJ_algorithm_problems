#include <stdio.h>
#include <queue>

typedef struct node {
    int currX;
    int currY;
    int m_dist;
}Node;

int m, n;
bool map[102][102];
bool isVisited[102][102];
int dist = 0;
std::queue<Node> q;

void bfs(int currX, int currY, int m_dist) {
    isVisited[currX][currY] = true;
    m_dist++;
    
    if (currX==m && currY == n){
        dist = m_dist;
        return;
    }
    
    if (!isVisited[currX - 1][currY] && map[currX - 1][currY]){
        Node tmpNode;
        tmpNode.currX = currX - 1;
        tmpNode.currY = currY;
        tmpNode.m_dist = m_dist;
        isVisited[currX - 1][currY]=1;
        q.push(tmpNode);
    }
    if (!isVisited[currX][currY - 1] && map[currX][currY - 1]) {
        Node tmpNode;
        tmpNode.currX = currX;
        tmpNode.currY = currY - 1;
        tmpNode.m_dist = m_dist;
        isVisited[currX][currY - 1]=1;
        q.push(tmpNode);
    }
    if (!isVisited[currX + 1][currY] && map[currX + 1][currY]) {
        Node tmpNode;
        tmpNode.currX = currX + 1;
        tmpNode.currY = currY;
        tmpNode.m_dist = m_dist;
        isVisited[currX + 1][currY]=1;
        q.push(tmpNode);
    }
    if (!isVisited[currX][currY + 1] && map[currX][currY + 1]) {
        Node tmpNode;
        tmpNode.currX = currX;
        tmpNode.currY = currY + 1;
        tmpNode.m_dist = m_dist;
        isVisited[currX][currY + 1]=1;
        q.push(tmpNode);
    }
    return;
}

int main() {
    scanf("%d %d", &m, &n);
    
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    bfs(1, 1, 0);
    while (!q.empty()) {
        Node tmpNode = q.front();
        bfs(tmpNode.currX, tmpNode.currY, tmpNode.m_dist);
        q.pop();
    }
    printf("%d", dist);
}
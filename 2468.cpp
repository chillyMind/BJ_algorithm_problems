#include <stdio.h>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int n; 
int mat[101][101];
bool visited[101][101];

vector<pair<int,int>> v[101];
priority_queue<int> ans;
map<int, vector<pair<int,int>>> mp;
int dx[4] = { 1 , -1 ,0 , 0 };
int dy[4] = { 0 , 0 , 1 , -1 };

void dfs(int x , int y , int height) {
	//printf("__%d %d height = %d \n", x, y, height);
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > -1 && ty > -1 && tx < n && ty < n) {
			if (mat[tx][ty] > height && !visited[tx][ty]) {
				dfs(tx, ty, height);
			}				
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf(" %d", &tmp);
			mat[i][j] = tmp;
			mp[tmp].push_back(make_pair(i, j));
		}
	}
	map<int, vector<pair<int, int>>>::iterator iter;
	ans.push(1);
	iter = mp.begin();
	while (iter != mp.end()){
		int tmpans = 0;
		int height = (*iter).first;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && mat[i][j]>height) {
					dfs(i, j, (*iter).first);
					tmpans++;
				}
			}
		}
		ans.push(tmpans);
		memset(visited, false, sizeof(visited));
		iter++;
	}
	printf("%d", ans.top());
}
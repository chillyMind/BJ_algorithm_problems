#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, k,ans;
bool visited[100001];
int dx[] = {-1, 1, 0};
queue<pair<int, int>> q;

int main() {
	scanf("%d %d", &n, &k);
	memset(visited, false, sizeof(visited));
	q.push(make_pair(0, n));
	while (!q.empty()) {
		pair<int,int> tmp = q.front();
		if (tmp.second == k) {
			ans = tmp.first;
			break;
		}
		int tt = 1 + tmp.first;
		q.pop();
		visited[tmp.second] = true;
		for (int i = 0; i < 3; i++) {
			int tx = dx[i] + tmp.second;
			if (dx[i] == 0) {
				tx *= 2;
			}
			if(tx <= 100000 && tx > -1){
				if (!visited[tx]) {
					pair<int, int> tp = make_pair(tt,tx);
					q.push(tp);
				}
			}
		}
	}
	printf("%d", ans);
}
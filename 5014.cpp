#include <stdio.h>
#include <queue>
using namespace std;
long long ans = -1;
int f, s, g, u, d;
queue<pair<int,long long>> q;
bool visited[1000001];

void bfs() {
	while (!q.empty()) {
		int curr = q.front().first;
		//printf("[%d]", curr);
		int tu = curr + u;
		int td = curr - d;
		long long ts = q.front().second + 1;
		q.pop();
		if (tu <= f && !visited[tu]) {
			if (tu == g) {
				ans = ts;
				break;
			}
			visited[tu] = true;
			q.push({ tu,ts });
		}
		if (td > 0 && !visited[td]) {
			if (td == g) {
				ans = ts;
				break;
			}
			visited[td] = true;
			q.push({ td,ts });
		}
	}
}

int main() {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	q.push({s,0});
	visited[s] = true;
	if (s == g) { printf("%d\n", 0); return 0; }
	bfs();
	if (ans == -1) {
		printf("use the stairs\n");
		return 0;
	}
	printf("%d", ans);
}
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
#define ii pair<int,int>

vector<int> v[10001];
int N, M;
int mx;
int arr[10001];
bool visited[10001];

int dfs(int n) {
	int cn = 1;
	visited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int t = v[n][i];
		if (!visited[t]) {
			cn += dfs(t);
		}
	}
	return cn;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		arr[i] = dfs(i);
		mx = mx > arr[i] ? mx : arr[i];
	}
	for (int i = 1; i <= N; i++) {
		if (mx == arr[i]) printf("%d ", i);
	}
}
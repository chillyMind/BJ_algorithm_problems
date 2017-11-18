#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

int N;
int arr[101];
vector<int> ans;
bool visited[101];

int dfs(int n) {
	visited[n] = true;
	if (!visited[arr[n]]) {
		int tmp = dfs(arr[n]);
		visited[n] = false;
		return tmp;
	}
	else {
		visited[n] = false;
		return arr[n];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (dfs(i) == i) ans.push_back(i);
		memset(visited, false, sizeof(visited));
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
}
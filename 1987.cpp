#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cstring>
using namespace std;

int n, m, ans = 0;
string mp[21];
int check[26];
int dx[4] = { 1 , -1 , 0, 0 };
int dy[4] = { 0 , 0 , 1, -1 };

void dfs(int r, int c,int d) {
	if (check[mp[r][c] - 'A'] != 0) {
		return;
	}
	check[mp[r][c] - 'A'] = 1;
	ans = ans > d ? ans : d;
	for (int i = 0; i < 4; i++) {
		int tr = r + dx[i];
		int tc = c + dy[i];
		if (tr < n && tc <m && tr > -1 && tc > -1){
			dfs(tr, tc, d+1);
		}
	}
	check[mp[r][c] - 'A'] = 0;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> mp[i];
	}
	dfs(0, 0, 1);
	printf("%d", ans);
}
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int n, k, root[50];
int L[50][1000001];
int R[50][1000001];
map<string, int> mp;
string str[50];

void pushv(int x,int y,int t) {
	if (x < y) {
		if (L[t][y] == 0) {
			L[t][y] = x;
			return;
		}
		pushv(x, L[t][y],t);
	}else{
		if (R[t][y] == 0) {
			R[t][y] = x;
			return;
		}
		pushv(x, R[t][y],t);
	}
}

void prefix(int n,int t) {
	if (L[t][n] != 0) {
		str[t].push_back('L');
		prefix(L[t][n], t);
	}
	if (n == root[t]) str[t].push_back('r');
	if (R[t][n] != 0) {
		str[t].push_back('R');
		prefix(R[t][n], t);
	}
	str[t].push_back('f');
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int a;
			scanf("%d", &a);
			if (root[i] == 0) root[i] = a;
			else pushv(a, root[i], i);
		}
	}
	for (int i = 0; i < n; i++) {
		prefix(root[i],i);
		mp[str[i]];
	}
	printf("%d", mp.size());
}
#include <stdio.h>
#include <vector>
using namespace std;
#define ii pair<int,int>

ii v[100001];
vector<int> d[100001];
int d_width[100001];
int hasPrnt[100001];
int n, root;
int cnt = 1;
int mxd = 0;
int ansd = 0;
int ansl = 0;

void dfs(int n,int depth) {
	if(v[n].first!=-1) dfs(v[n].first,depth+1);
	d[depth].push_back(cnt);
	//printf("[%d] (depth : %d, col : %d)\n", n, depth, cnt);
	cnt++;
	if (v[n].second != -1) dfs(v[n].second,depth+1);
	mxd = mxd > depth ? mxd : depth;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].first= b;
		v[a].second= c;
		if(b!=-1)hasPrnt[b] = 1;
		if(c!=-1)hasPrnt[c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (hasPrnt[i] == 0) {
			root = i; break;
		}
	}
	dfs(root, 1);
	for (int i = 1; i <= mxd; i++) {
		d_width[i] = d[i][d[i].size() - 1] - d[i][0] + 1;
		if (ansl < d_width[i]) {
			if (ansl == d_width[i]) {
				ansd = ansd < i ? ansd : i;
			}
			else {
				ansd = i;
			}
			ansl = d_width[i];

		}
	}
	printf("%d %d\n", ansd, ansl);
}
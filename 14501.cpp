#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int t[20];
int p[20];
int wk_m[20][20];

int wk(int m, int n) {
	if (m + t[n]-1 > N) {
		wk_m[m][n] = 0;
		return 0;
	}
	int currtime = m + t[n];
	int mx = 0;
	for (int i = currtime; i <= N; i++) {
		if (i == 0) continue;
		if (wk_m[i][i] != -1) {
			mx = mx > wk_m[i][i] ? mx : wk_m[i][i];
		}
		else {
			int tmp = wk(i, i);
			mx = mx > tmp ? mx : tmp;
		}
	}
    wk_m[m][n] = p[n] + mx;
	return p[n] + mx;
}

int main() {
	scanf("%d", &N);
	memset(wk_m, -1, sizeof(wk_m));
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
	int mx = 0;
	printf("%d", wk(0,0));
}

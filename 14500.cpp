#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,ans=0;
int mat[502][502];
bool visited[502][502];
int da[4] = { -1, 1, 0 , 0 };
int db[4] = { 0 , 0, -1, 1 };
int exca[4][3][2] = {
	{{ 1,-1 },{ 1,0 },{ 1,1 }},
	{{ 1,1 },{ 0,1 },{ -1,1 }},
	{{-1,1 },{ -1,0 },{ -1,-1 }},
	{{-1,-1 },{ 0,-1 },{ 1,-1 }}
};
int dfs(int a,int b, int depth, int num) {
	int ret = 0;
	num += mat[a][b];
	if (depth == 3) {
		return num;
	}
	visited[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int ta = a + da[i];
		int tb = b + db[i];
		if (ta > 0 && tb > 0 && ta < n+1 && tb < m+1) {
			if (!visited[ta][tb]) {
				int tmpret = dfs(ta, tb, depth + 1, num);
				if (ret < tmpret) {
					ret = tmpret;
				}
			}
		}
	}
	visited[a][b] = false;
	return ret;
}
int excase(int a,int b) {
	int ret = mat[a][b];
	priority_queue<int> tmppq;
	for (int i = 0; i < 4; i++) {
		int isTri = 0;
		int tmpsum = 0;
		for (int j = 0; j < 3; j++) {
			int ta = a + exca[i][j][0];
			int tb = b + exca[i][j][1];
			if (!(ta > 0 && tb > 0 && ta < n + 1 && tb < m + 1))break;
			tmpsum += mat[ta][tb];
			isTri++;
		}
		if (isTri < 3) continue;
		tmppq.push(tmpsum);
	}
	if (!tmppq.empty()) ret += tmppq.top();
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	int tmpmax = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 1; i < n + 1; i++){
		for (int j = 1; j < m + 1; j++) {
			int tmp = dfs(i, j, 0, 0);
			int tmp2 = excase(i, j);
			tmp = max(tmp, tmp2);
			if (ans < tmp) {
				ans = tmp;
			}
		}
	}
	printf("%d", ans);
}
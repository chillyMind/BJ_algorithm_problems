#include <stdio.h>
#include <cstring>
using namespace std;
int N, M, t;
int sum[301][301];
int main() {
	memset(sum, 0, sizeof(sum));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp;
			scanf("%d",&tmp);
			sum[i][j] = sum[i-1][j] + sum[i][j - 1] + tmp - sum[i-1][j-1];
		}
	}
	scanf("%d", &t);
	while (t--) {
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]);
	}
}